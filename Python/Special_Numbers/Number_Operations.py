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

if __name__ == "__main__":
    print("Prime factors.")
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
        factors = prime_factors(number)
        print("The prime factors for the number ",number," are ",factors)
    print("Prime Factors Code Ended")

