from Random_Array_Generator import random_array_generator_function
from Sorting_Algorithms import *
from File_operations import *
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
data = random_array_generator_function(n)
print(data)
condition = True
while condition:
    sorting_algorithm=input("Which Sorting Algorithm do you want to use? ");
    data = algorithm_selection(sorting_algorithm,data,n)
    if data:
        condition = False
print("Sorted data saved to file")
print(data)
write_to_file("sorted_array.txt",data)
