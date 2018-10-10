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
    #us_word=uk_word.replace('ze', 'se')
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

#10
#gram beard clothing colonise prior catalyze direction wrap coin able
#hydrolyse realize recover envelope colonize achieve even crazy combine present
#more essential covering mystery retired realise shopping dry recognise reach
#hydrolyse such scientific virus motorcycle passport paralyze shell yet lean
#eastern duty newly produce openly illness realize catalyze float trap
#chart colonise tooth corner per dentist garage paralyse hydrolyze bent
#physically typical materialise maintain penny keep encouragement pint recognize materialie
#materialize crash example empty equal save complex professor left brand
#colonise late negative apart colonize climb reservation recommend industry recognie
#along pace catalyse expose minute left paralyse bet price materialis
#8
#hydrolyze
#catalyze
#materialize
#colonize
#recognize
#caramelize
#realize
#paralyze
