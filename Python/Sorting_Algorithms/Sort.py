from Random_Array_Generator import random_array_generator_function
from Algorithms import *
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
original = random_array_generator_function(n)
sorting_algorithm=input("Which Sorting Algorithm do you want to use? ");
result = sorting_algorithm(original,n)
file = open("sorted_array.txt", "w")
file.write(str(n))
file.write(str(result))
file.close
