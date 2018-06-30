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

def average(numbers):
    sum = 0
    length = len(numbers)
    for i in numbers:
        sum += i
    average = sum/length
    return average

def root(number,n):
    low = 0
    if n <= 0 :
        return 0
    negative = False
    if( number < 0 ):
        if n % 2 == 0:
            return 0
        else:
            number *= -1
            negative = True
    high = number
    while True:
        midpoint = average([low,high])
        power = 1
        for i in range(0,n):
            power *= midpoint
        if number > round(power,6):
            low = midpoint
        elif number < round(power,6):
            high = midpoint
        else :
            if negative:
                midpoint *= -1
            return round(midpoint,6)
            
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

def factorial(number):
    if number == 0:
        return 1
    status = 1
    number = int(number)
    if number < 0:
        status = -1
    return number*factorial(number-status)

def permutation(n,r):
    return int(factorial(n)/factorial(n-r))

def combination(n,r):
    return int(factorial(n)/(factorial(n-r)*factorial(r)))

def digits(number):
    digits=[]
    if number < 0:
        number = -1 * number
    while(number > 9):
        digits.append(number%10)
        number = number // 10
    digits.append(number)
    return digits

def HCF(numbers):
    HCF = 0
    if min(numbers) <= 0:
        return HCF
    for i in range(1,min(numbers)+1):
        divisible = True
        for j in numbers:
            if j % i != 0:
                divisible = False
        if divisible:
            HCF = i
    return HCF

def LCM(numbers):
    if min(numbers) <= 0:
        return 0
    product = 1
    for i in numbers:
        product *= i
    for i in range(1,product+1):
        divisible = True
        for j in numbers:
            if i % j != 0:
                divisible = False
        if divisible:
            return i
        
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
        print("The LCM of numbers ",a," and ",b," is ")
    print("Test Code Ended")

