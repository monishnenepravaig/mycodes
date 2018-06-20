from Number_Operations import digits
print("Armstrong Numbers -> A number whose sum of cube of digits = number")
while True:
    string = input("Enter a range upto which you want the Armstrong numbers ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    print("Armstrong numbers upto",number,"are:")
    for i in range(0,number+1):
        sum = 0
        split = digits(i)
        for j in split:
            sum += j*j*j
        if sum == i:
            print(i)
print("Armstrong numbers Code Ended")


