from Random_Array_Generator import random_array_generator_function
from Algorithms import *
from File_operations import *
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
algorithm_names_dict = dict_from_file("Algorithm_names.txt")
original = random_array_generator_function(n)
sorting_algorithm=input("Which Sorting Algorithm do you want to use? ");
result = sorting_algorithm(original,n)
write_to_file("sorted_array.txt",result)
