from Random_Array_Generator import random_array_generator_function
from Sorting_Algorithms import *
from File_operations import *
print("Generate an array of n random numbers (0 to n-1)")
n=int(input("Enter n "))
data = random_array_generator_function(n)
print(data)
condition = True
flag = True
while condition:
    sorting_algorithm=input("Which Sorting Algorithm do you want to use? ");
    data = algorithm_selection(sorting_algorithm,data)
    if data:
        condition = False
for i in range(0,n-1):
    if data[i]>=data[i+1]:
        flag = False
print(data)
if flag:
    print("Data Sorting Succesful. Sorted data saved to file.")
    write_to_file("sorted_array.txt",data)
else:
    print("Data Sorting Failed.")

