from Number_Operations import *
from File_operations import *
from random import randint
from random import seed
from random import shuffle

def selection_matrix(n,r):
    high=power(2,n)
    matrix=[]
    for i in range(0,high):
        if count_of_1(i) == r:
            matrix.append(i)
    return  matrix

def group_generator(data,r):
    n = len(data)
    matrix = selection_matrix(n,r)
    groups = []
    for number in matrix:
        set = []
        count = 0
        while number != 0:
            value = number & 1
            if value == 1:
                set.append(data[count])
            number = number>>1
            count+=1
        groups.append(set)
    return groups

def random_group(data,r):
    n = len(data)
    matrix = []
    set = []
    for i in range (0,n):
        matrix.append(0)
    for i in range (0,r):
        while True:
            random = randint(0,n-1)
            if matrix[random] == 1:
                continue
            else:
               matrix[random] = 1
               break
    count = 0
    for bit in matrix:
        if bit == 1:
            set.append(data[count])
        count+=1
    return set


        
if __name__ == "__main__":
    fruits = list_from_file("Fruits","\n")
    n=len(fruits)
    print("Fruit Basket\n")
    while True:
        string = input("How many fruits do you want in your fruit basket? ")
        if string == "":
            break
        try:
            r = int(string)
        except:
            print("Invalid Imput")
            continue
        number_of_groups = combination(n,r)
        print("Total Number of combinations of fruits are", number_of_groups)
        groups = group_generator(fruits,r)
        for set in groups:
            print(set,"\n")
    

