import re
import string
    
n=input()
sentences=[]
for i in range(int(n)):
    sentences.append(input())
t=input()
for i in range(int(t)):
    counter=0
    uk_word=input()
    us_word=uk_word.replace('our', 'or')
    us_word='\\b('+us_word+')\\b'
    uk_word='\\b('+uk_word+')\\b'
    for j in range(int(n)):
        m=re.findall(uk_word,sentences[j])
        for k in m:
            counter+=1
        m=re.findall(us_word,sentences[j])
        for k in m:
            counter+=1
    print(counter)
#3
#assure vegetable tough candor swing hers apart or relaxed marriage
#transfer automatically outdoor ideally savior splendor on yawn control varied
#strictly reader honour we he right lecture behavior fat partnership
#8
#behaviour
#colour
#honour
#clamour
#splendour
#candour
#saviour
#odour
