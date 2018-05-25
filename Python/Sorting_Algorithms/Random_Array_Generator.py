import random
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
a=[]
b=0
while len(a)!=n:
    b = random.randint(0,n-1)
    condition = True
    for i in range(0,len(a)):
        if (int(b) == int(a[i])):
            condition = False
    if condition:
        a.append(b)
file = open("random_numbers_array.txt", "w")
file.write(str(n))
file.write(str(a))
file.close
print (a)
