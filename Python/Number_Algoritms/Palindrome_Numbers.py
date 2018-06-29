from Number_Operations import digits
print("Palindrome Numbers -> A number that is the same written forwards or backwards")
condition = True
while True:
    string = input("Enter next number to be checked ")
    if string == "":
        break
    try:
        number = int(string)
    except:
        print("Invalid Input")
        continue
    split = digits(number)
    split_2 = split[::-1]
    if split == split_2:
        print(number,"is a palindrome number.")
    else:
        print(number,"is not a palindrome number.")
print("Palindrome numbers Code Ended")

