from Number_Operations import divisors
print("Deficient Numbers -> Sum of divisors < 2 * Number.")
print("Perfect Numbers -> Sum of divisors = 2 * Number.")
print("Abundant Numbers -> Sum of divisors > 2 * Number.")
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
    if sum < 2 * number:
        print(number,"is a deficient number as ",sum," < 2 *",number)
    elif sum == 2 * number:
        print(number,"is a perfect number as ",sum," = 2 *",number)
    else:
        print(number,"is an abundant number as ",sum," > 2 *",number)
print("Code Ended.")

