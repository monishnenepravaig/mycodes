from Number_Operations import digits
print("Automorphic Numbers -> A number whose square ends with the number itself")
while True:
    string = input("Enter a range upto which you want the automorphic numbers ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    print("Automorphic numbers upto",number,"are:")
    for i in range(0,number+1):
        condition = True
        split = digits(i)
        square_split = digits(i*i)
        length = len(split)
        for j in range(0,length):
            if split[j] != square_split[j]:
                condition = False
        if condition:
            print(i)
print("Automorphic numbers Code Ended")
