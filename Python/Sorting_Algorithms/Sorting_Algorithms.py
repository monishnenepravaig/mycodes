
from Binary_Search import *

from random import getrandbits

def merge_shuffle(data):
    n = len(data)
    if n == 1:
        return data
    elif n == 2:
        if getrandbits(1):
            data[0],data[1] = data[1],data[0]
        return data
    else:
        data_1 = shuffleArray(data[:int(n/2)])
        data_2 = shuffleArray(data[int(n/2):])
        n_1 = len(data_1)
        n_2 = len(data_2)
        counter_1=0
        counter_2=0
        counter_merge=0
        while(counter_1 < n_1 or counter_2 < n_2):
            if counter_1 < n_1 and counter_2 < n_2:
                if getrandbits(1):
                    data[counter_merge] = data_1[counter_1]
                    counter_1 += 1
                else:
                    data[counter_merge] = data_2[counter_2]
                    counter_2 += 1
            elif counter_1 < n_1:
                data[counter_merge] = data_1[counter_1]
                counter_1 += 1
            else:
                data[counter_merge] = data_2[counter_2]
                counter_2 += 1
            counter_merge += 1
        return data

def selection_sort(data): 
    n = len(data) 
    for i in range(0,n):
        min_value = i
        for j in range(i,n):
            if data[j] < data[min_value]:
                min_value = j
        data[i],data[min_value]= data[min_value],data[i]
    return data

def insertion_sort(data): 
    n = len(data) 
    for i in range(1,n):
        temp_value = data[i]
        condition = True
        j = i
        while (condition and j>0):
            if data[j-1] > temp_value:
                data[j] = data[j-1]
                j-=1
            else:
                condition = False
        data[j] = temp_value
    return data

def binary_insertion_sort(data): 
    n = len(data)
    for i in range(1,n):
        temp_value = data[i]
        location = Binary_Search_Array(temp_value,data[:i])
        j = i
        while (j>location):
            data[j] = data[j-1]
            j-=1
        data[location] = temp_value
    return data

def merge_sort(data):
    n = len(data)
    if n == 1:
        return data
    elif n == 2:
        if data[0] > data[1]:
            data[0],data[1] = data[1],data[0]
        return data
    else:
        data_1 = merge_sort(data[:int(n/2)])
        data_2 = merge_sort(data[int(n/2):])
        n_1 = len(data_1)
        n_2 = len(data_2)
        counter_1=0
        counter_2=0
        counter_merge=0
        while(counter_1 < n_1 or counter_2 < n_2):
            if counter_1 < n_1 and counter_2 < n_2:
                if data_1[counter_1] < data_2[counter_2]:
                    data[counter_merge] = data_1[counter_1]
                    counter_1 += 1
                else:
                    data[counter_merge] = data_2[counter_2]
                    counter_2 += 1
            elif counter_1 < n_1:
                data[counter_merge] = data_1[counter_1]
                counter_1 += 1
            else:
                data[counter_merge] = data_2[counter_2]
                counter_2 += 1
            counter_merge += 1
        return data

def quick_sort(data):
    n = len(data)
    if n == 1 or n == 0:
        return data
    elif n == 2:
        if data[0] > data[1]:
            data[0],data[1] = data[1],data[0]
        return data
    pivot = data[n-1]
    wall_location = 0
    for j in range(0,n-1):
        if data[j] < pivot:
            data[j],data[wall_location]=data[wall_location],data[j]
            wall_location += 1
    j = n-1
    while (j>wall_location):
        data[j] = data[j-1]
        j-=1
    data[wall_location]= pivot
    if n > 2: 
        data[:wall_location]=quick_sort(data[:wall_location])
        data[wall_location+1:]=quick_sort(data[wall_location+1:])
    return data

def bubble_sort(data): 
    n = len(data) 
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if data[j] > data[j+1]:
                data[j],data[j+1]= data[j+1],data[j]
    return data

def cocktail_shaker_sort(data): 
    n = len(data)
    bottom = 0
    top = n-1
    for i in range(0,n-1):   
            for j in range(bottom,top):
                if data[j] > data[j+1]:
                    data[j],data[j+1]= data[j+1],data[j]
            top -= 1
            for k in range(top,bottom,-1):
                if data[k] < data[k-1]:
                    data[k],data[k-1]= data[k-1],data[k]
            bottom += 1
    return data

def gnome_sort(data): 
    n = len(data) 
    return data

def gravity_sort(data):
    n = len(data)
    i = 0
    j = 0
    temp_data=[]
    temp = 1
    bottom = 0
    for i in range(0,n):
            if data[i] == 0:
                bottom += 1
    while temp>0:
        temp = 0
        for i in range(0,n):
            if data[i] > 0:
                temp += 1
                data[i] -= 1
        else:
            temp_data.append(temp)
    j = 0
    i = 0
    while temp_data[j] > 0:
        while temp_data[j] > 0:
            data[i] += 1
            temp_data[j] -= 1
            i -= 1
        j += 1
        i = n-1
    data[bottom]+=1
    for i in range(0,bottom):
        data[i] = 0
    return data

def shell_sort(data): 
    n = len(data) 
    return data

def comb_sort(data): 
    n = len(data) 
    return data

def heap_sort(data): 
    n = len(data) 
    return data

def smooth_sort(data): 
    n = len(data) 
    return data

def odd_even_sort(data): 
    n = len(data) 
    return data

def bitonic_sort(data): 
    n = len(data) 
    return data

def cycle_sort(data): 
    n = len(data) 
    return data
    
def radix_msd_sort(data): 
    n = len(data) 
    return data

def radix_lsd_sort(data): 
    n = len(data)
    max_number = 0
    digits_in_max = 0
    divisor = 1
    modulous = 10
    for i in range(0,n):
        if data[i] > max_number:
            max_number = data[i]
    condition = True
    while condition:
        digits_in_max += 1
        max_number /= 10
        if max_number < 10:
            condition = false
    return data

def std_gcc_sort(data): 
    n = len(data) 
    return data

def std_gcc_stable_sort(data): 
    n = len(data) 
    return data

def tim_sort(data): 
    n = len(data) 
    return data

def block_merge_sort(data): 
    n = len(data) 
    return data

def cocktail_merge_sort(data): 
    n = len(data) 
    return data

def flash_sort(data):
    n = len(data)
    return data

def pancake_sort(data): 
    n = len(data) 
    return data

def hybrid_sort(data): 
    n = len(data) 
    return data

algorithm_names_dict={'selection': selection_sort,
                      'pancake': pancake_sort,
                      'quick': quick_sort,
                      'block_merge': block_merge_sort,
                      'block' : block_merge_sort,
                      'insertion': insertion_sort,
                      'binary_insertion': binary_insertion_sort,
                      'radix_lsd': radix_lsd_sort,
                      'radix' : radix_lsd_sort,
                      'std_gcc_stable': std_gcc_stable_sort,
                      'std_gcc': std_gcc_sort,
                      'gcc': std_gcc_sort,
                      'radix_msd': radix_msd_sort,
                      'flash': flash_sort,
                      'hybrid': hybrid_sort,
                      'gravity': gravity_sort,
                      'tim': tim_sort,
                      'cocktail_shaker': cocktail_shaker_sort,
                      'cocktail': cocktail_shaker_sort,
                      'bubble': bubble_sort,
                      'shell': shell_sort,
                      'odd_even': odd_even_sort,
                      'heap': heap_sort,
                      'cocktail_merge': cocktail_merge_sort,
                      'comb': comb_sort,
                      'cycle': cycle_sort,
                      'gnome': gnome_sort,
                      'bitonic': bitonic_sort,
                      'smooth': smooth_sort,
                      'merge': merge_sort
                      }


def algorithm_selection(algorithm_command,data):
    try:
        algorithm = algorithm_names_dict[algorithm_command]
        print("Data sorted by",algorithm_command,"sort")
    except:
        print("Invalid Sorting Algorithm")
        return None
    return algorithm(data)

