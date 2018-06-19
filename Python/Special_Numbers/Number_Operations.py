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
    for i in range(1,number + 1):
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

def HCF(a,b):
    common_factors=[]
    factors_a = divisors(a)
    factors_b = divisors(b)
    for i in factors_a:
        if i in factors_b:
            common_factors.append(i)
    HCF = common_factors[-1]
    return HCF

def LCM(a,b):
    common_factors=[]
    d = HCF(a,b)
    LCM = int( a * b / d )
    return LCM
        
if __name__ == "__main__":
    print("Test Code.")
    condition = True
    while(condition):
        string = input("Enter first number ")
        if string == "":
            break
        try:
            a = int(string)
        except:
            print("Invalid Input")
            continue
        string = input("Enter second number ")
        if string == "":
            break
        try:
            b = int(string)
        except:
            print("Invalid Input")
            continue
        c = LCM(a,b)
        print("The LCM of numbers ",a," and ",b," is ",c)
    print("Test Code Ended")

