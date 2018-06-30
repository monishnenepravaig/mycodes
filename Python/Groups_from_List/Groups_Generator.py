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
    pokemons = list_from_file("Pokemons","\n")
    n=len(pokemons)
    print("Ash has",n,"Pokemons, but, he can only use 6 at a time in a battle.")
    number_of_groups = combination(n,6)
    print("Total Number of combinations of 6 pokemons that Ash can use in a battle are", number_of_groups)
    while True:   
        groups = random_group(pokemons,6)
        shuffle(groups)
        print("Random Group of 6 pokemons for ash's next battle\n",groups)
        key_pressed = input("Press any key for next group of 6 pokemons and Press Return to exit\n")
        if key_pressed == '':
            break
        seed(power(ord(key_pressed),randint(0,n))/7919)
        
    
