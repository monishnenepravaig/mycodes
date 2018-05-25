#!/usr/bin/env python
from os import environ, path
from pocketsphinx.pocketsphinx import *
from sphinxbase.sphinxbase import *

import os
import pyaudio
import wave
import audioop
from collections import deque
import time
import math
import serial
import RPi.GPIO as GPIO      
import os, time
led1=17
led2=27
led3=22
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led1, GPIO.OUT)
GPIO.setup(led2, GPIO.OUT)
GPIO.setup(led3, GPIO.OUT)
GPIO.output(led1,0)
GPIO.output(led2,0)
GPIO.output(led3,0)
bt_serial = serial.Serial("/dev/rfcomm0", baudrate=9600)

class SpeechDetector:
    def __init__(self,string):
        self.string=string
        # Microphone stream config.
        self.CHUNK = 512 # CHUNKS of bytes to read each time from mic
        self.FORMAT = pyaudio.paInt16
        self.CHANNELS = 1
        self.RATE = 44100

        self.SILENCE_LIMIT = 0.5  # Silence limit in seconds. The max ammount of seconds where
                           # only silence is recorded. When this time passes the
                           # recording finishes and the file is decoded

        self.PREV_AUDIO = 0.5  # Previous audio (in seconds) to prepend. When noise
                          # is detected, how much of previously recorded audio is
                          # prepended. This helps to prevent chopping the beginning
                          # of the phrase.

        self.THRESHOLD = 4600
        self.num_phrases = -1

        # These will need to be modified according to where the pocketsphinx folder is
        MODELDIR = "/usr/local/lib/python2.7/dist-packages/pocketsphinx/model"
        DATADIR = "/usr/local/lib/python2.7/dist-packages/pocketsphinx/data"

        # Create a decoder with certain model
        config = Decoder.default_config()
        config.set_string('-hmm', path.join(MODELDIR, '/usr/local/lib/python2.7/dist-packages/pocketsphinx/model/en-us'))
        config.set_string('-lm', path.join(MODELDIR, '/home/pi/1544.lm'))
        config.set_string('-dict', path.join(MODELDIR, '/home/pi/1544.dic'))

        # Creaders decoder object for streaming data.
        self.decoder = Decoder(config)

    def setup_mic(self, num_samples=50):
        """ Gets average audio intensity of your mic sound. You can use it to get
            average intensities while you're talking and/or silent. The average
            is the avg of the .2 of the largest intensities recorded.
        """
        print ("Getting intensity values from mic.")
        p = pyaudio.PyAudio()
        stream = p.open(format=self.FORMAT, 
                        channels=self.CHANNELS,
                        rate=self.RATE, 
                        input=True, 
                        frames_per_buffer=self.CHUNK)

        values = [math.sqrt(abs(audioop.avg(stream.read(self.CHUNK), 4)))
                  for x in range(num_samples)]
        values = sorted(values, reverse=True)
        r = sum(values[:int(num_samples * 0.2)]) / int(num_samples * 0.2)
        print (" Finished ")
        print (" Average audio intensity is "), r
        stream.close()
        p.terminate()

        if r < 3000:
            self.THRESHOLD = 3500
        else:
            self.THRESHOLD = r + 100

    def save_speech(self, data, p):
        """
        Saves mic data to temporary WAV file. Returns filename of saved
        file
        """
        filename = 'output_'+str(int(time.time()))
        # writes data to WAV file
        data = ''.join(data)
        wf = wave.open(filename + '.wav', 'wb')
        wf.setnchannels(1)
        wf.setsampwidth(p.get_sample_size(pyaudio.paInt16))
        wf.setframerate(2000)  # TODO make this value a function parameter?
        wf.writeframes(data)
        wf.close()
        return filename + '.wav'

    def decode_phrase(self, wav_file):
        self.decoder.start_utt()
        stream = open(wav_file, "rb")
        while True:
          buf = stream.read(512)
          if buf:
            self.decoder.process_raw(buf, False, False)
          else:
            break
        self.decoder.end_utt()
        words = []
        [words.append(seg.word) for seg in self.decoder.seg()]
        return words

    def run(self):
        """
        Listens to Microphone, extracts phrases from it and calls pocketsphinx
        to decode the sound
        """
        self.setup_mic()

        #Open stream
        p = pyaudio.PyAudio()
        stream = p.open(format=self.FORMAT, 
                        channels=self.CHANNELS, 
                        rate=self.RATE, 
                        input=True, 
                        frames_per_buffer=self.CHUNK)
        print ("* Mic set up and listening. ")

        audio2send = []
        cur_data = ''  # current chunk of audio data
        rel = self.RATE/self.CHUNK
        slid_win = deque(maxlen=self.SILENCE_LIMIT * rel)
        #Prepend audio from 0.5 seconds before noise was detected
        prev_audio = deque(maxlen=self.PREV_AUDIO * rel)
        started = False
        X=1
        while (X==1):
            cur_data = stream.read(self.CHUNK)
            slid_win.append(math.sqrt(abs(audioop.avg(cur_data, 4))))

            if sum([x > self.THRESHOLD for x in slid_win]) > 0:
                if started == False:
                    GPIO.output(led1,1)
                    GPIO.output(led2,0)
                    print ("Starting recording of phrase")
                    started = True
                audio2send.append(cur_data)

            elif started:
                GPIO.output(led1,0)
                GPIO.output(led2,1)
                GPIO.output(led3,0)
                print ("Finished recording, decoding phrase")
                filename = self.save_speech(list(prev_audio) + audio2send, p)
                r = self.decode_phrase(filename)
                print ("DETECTED: "), r
                command=r
                self.string=r
                # Removes temp audio file
                os.remove(filename)
                # Reset all
                started = False
                slid_win = deque(maxlen=self.SILENCE_LIMIT * rel)
                prev_audio = deque(maxlen=0.5 * rel)
                audio2send = []
                cur_data = ''
                X=0
            else:
                prev_audio.append(cur_data)

        print ("* Done listening")
        GPIO.output(led2,0)
        stream.close()
        p.terminate()
        command = r
        data = dict()
        raw_data=open("commands.txt","r")
        for item in raw_data:
         if ':' in item:
          key,value = item.split(':', 1)
          data[key]=value
        j= False
        for key in data:  
         if key in command:
          j = True
          print ("The command is")
          print (key)
          print (data[key])
          bt_serial.write(str(data[key]))
        if (j == False):
         print ("no command found")
        else:
         GPIO.output(led3,1)

while True:        
 print("What is the command?")
 instruction=SpeechDetector("a")
 instruction.run()
 time.sleep(5)



