from Random_Array_Generator import random_array_generator_function
from Sorting_Algorithms import *
from File_operations import *
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
original = random_array_generator_function(n)
print(original)
condition = True
while condition:
    sorting_algorithm=input("Which Sorting Algorithm do you want to use? ");
    result = algorithm_selection(sorting_algorithm,original,n)
    if result:
        condition = False
print("Data sorted and saved to file")
print(result)
write_to_file("sorted_array.txt",result)
