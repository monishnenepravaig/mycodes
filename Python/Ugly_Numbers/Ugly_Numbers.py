print("Ugly Numbers")
condition = True
while(condition):
    string = input("Enter next number ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    if number < 0:
        temp = -1 * number
    else:
        temp = number
    while (temp % 2 == 0) and ( temp >= 2 ):
        temp /= 2
    while (temp % 3 == 0) and ( temp >= 3 ):
        temp /= 3
    while (temp % 5 == 0) and ( temp >= 5 ):
        temp /= 5
    if temp == 1 or temp == 0 :
        print(number,"is an ugly number.")
    else:
        print(number,"is a beautiful number.")
print("Ugly numbers Code Ended")

