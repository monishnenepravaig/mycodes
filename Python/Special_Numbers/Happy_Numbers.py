from Number_Operations import digits
print("Happy Numbers -> Repeated sum of squares of digits = 1")
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
    while (number != 1) and (number != 4) and (number != 0): 
        factors = digits(number)
        number = 0
        for i in factors:
            number += i*i
            print(" +",i,"^2")
        print(" = ",number)
        if (number == 1) or (number == 4):
            break
    if number == 1:
        print(number,"is a happy number.")
    else:
        print(number,"is a sad number.")
print("Happy numbers Code Ended")



