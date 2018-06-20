from Number_Operations import digits
print("Spy Numbers -> A number whose sum of cube of digits = number")
while True:
    string = input("Enter a range upto which you want the Spy numbers ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    print("Spy numbers upto",number,"are:")
    for i in range(0,number+1):
        sum = 0
        product = 1 
        split = digits(i)
        for j in split:
            sum += j
            product *= j
        if product == sum:
            print(i)
print("Spy numbers Code Ended")



