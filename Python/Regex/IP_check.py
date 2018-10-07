import re
ipv6_pattern=r"^(([\dabcdef]){1,4}:){7}([\dabcdef]){1,4}$"
ipv4_pattern=r"^(((\d)|(\d\d)|(1\d\d)|(2[01234]\d)|(25[012345]))\.){3}((\d)|(\d\d)|(1\d\d)|(2[01234]\d)|(25[012345]))$"
n=input()
for i in range(int(n)):
    a=input()
    if re.findall(ipv4_pattern,a):
        print("IPv4")
    elif re.findall(ipv6_pattern,a):
        print("IPv6") 
    else:
        print("Neither")
#3
#This line has junk text.  
#121.18.19.20  
#2001:0db8:0000:0000:0000:ff00:0042:8329  
