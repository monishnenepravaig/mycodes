from Number_Operations import prime_factors
print("Ugly Numbers -> Numbers with only -1, 2, 3 and 5 as prime factors.")
condition = True
while(condition):
    string = input("Enter next number to be checked ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    factors = prime_factors(number)
    temp = True
    for i in factors:
        if (i!=0)and(i!=1)and(i!=2)and(i!=3)and(i!=5)and(i!=-1):
            temp = False
    if temp:
        print(number,"is an ugly number.")
    else:
        print(number,"is a beautiful number.")
print("Ugly numbers Code Ended")

