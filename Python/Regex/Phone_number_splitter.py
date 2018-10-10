import re
import string
n=input()
for i in range(int(n)):
    given=input()
    given=given.replace(' ', '-')
    split_number=given.split('-')
    country_code=split_number[0]
    area_code=split_number[1]
    number=split_number[2]
    output='CountryCode='+country_code+',LocalAreaCode='+area_code+',Number='+number
    print(output)

#2
#1 877 2638277
#91-011-23413627
