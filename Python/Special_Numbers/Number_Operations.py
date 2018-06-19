def prime_factors(number):
    factors=[]
    count=2
    if number == 0:
        factors.append(0)
        return factors
    elif number < 0:
        factors.append(-1)
        number = -1 * number
    factors.append(1)
    while number!=1:
        if number%count == 0:
            number = number/count
            factors.append(count)
        else:
            count += 1
    return factors

def divisors(number):
    factors=[]
    count=2
    if number == 0:
        factors.append(0)
        return factors
    elif number < 0:
        factors.append(-1)
        number = -1 * number
    for i in range(1,number):
        if number % i == 0:
            factors.append(i)
    return factors

def digits(number):
    digits=[]
    if number < 0:
        number = -1 * number
    while(number > 9):
        digits.append(number%10)
        number = number // 10
    digits.append(number)
    return digits

if __name__ == "__main__":
    print("Test Code.")
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
        factors = digits(number)
        print("The digits for the number ",number," are ",factors)
    print("Test Code Ended")

