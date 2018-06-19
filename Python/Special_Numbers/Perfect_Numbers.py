from Number_Operations import divisors
print("Deficient Numbers -> Sum of divisors < Number.")
print("Perfect Numbers -> Sum of divisors = Number.")
print("Abundant Numbers -> Sum of divisors > Number.")
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
    if(number < 0):
        print("Invalid Input")
        continue
    factors = divisors(number)
    print("The divisors for the number ",number," are ",factors)
    sum = 0
    for i in factors:
        sum += i
    print("The sum of it's divsors is ",sum)
    if sum < number:
        print(number,"is a deficient number as ",sum," < ",number)
    elif sum == number:
        print(number,"is a perfect number as ",sum," = ",number)
    else:
        print(number,"is an abundant number as ",sum," > ",number)
print("Code Ended.")

