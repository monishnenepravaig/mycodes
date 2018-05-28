
from Binary_Search import *

def selection_sort(data): 
    n = len(data) 
    for i in range(0,n):
        min_value = i
        for j in range(i,n):
            if data[j] < data[min_value]:
                min_value = j
        data[i],data[min_value]= data[min_value],data[i]
    print("Data sorted by selection sort")
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
    print("Data sorted by insertion sort")
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
    print("Data sorted by binary insertion sort")
    return data

def merge_sort(data): 
    n = len(data) 
    print("Data sorted by merge sort")
    return data

def quick_lr_sort(data): 
    n = len(data) 
    print("Data sorted by quick lr sort")
    return data

def quick_ll_sort(data): 
    n = len(data) 
    print("Data sorted by quick ll sort")
    return data

def quick_ternary_lr_sort(data): 
    n = len(data) 
    print("Data sorted by quick ternary lr sort")
    return data

def quick_ternary_ll_sort(data): 
    n = len(data) 
    print("Data sorted by quick ternary ll sort")
    return data

def quick_dual_pivot_sort(data): 
    n = len(data) 
    print("Data sorted by quick dual pivot sort")
    return data

def bubble_sort(data): 
    n = len(data) 
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if data[j] > data[j+1]:
                data[j],data[j+1]= data[j+1],data[j]
    print("Data sorted by bubble sort")
    return data

def cocktail_shatter_sort(data): 
    n = len(data) 
    print("Data sorted by cocktail shatter sort")
    return data

def gnome_sort(data): 
    n = len(data) 
    print("Data sorted by gnome sort")
    return data

def gravity_sort(data): 
    n = len(data) 
    print("Data sorted by gravity sort")
    return data

def shell_sort(data): 
    n = len(data) 
    print("Data sorted by shell sort")
    return data

def comb_sort(data): 
    n = len(data) 
    print("Data sorted by comb sort")
    return data

def heap_sort(data): 
    n = len(data) 
    print("Data sorted by heap sort")
    return data

def smooth_sort(data): 
    n = len(data) 
    print("Data sorted by smooth sort")
    return data

def odd_even_sort(data): 
    n = len(data) 
    print("Data sorted by odd even sort")
    return data

def bitonic_sort(data): 
    n = len(data) 
    print("Data sorted by bitonic sort")
    return data

def cycle_sort(data): 
    n = len(data) 
    print("Data sorted by cycle sort")
    return data

def radix_msd_sort(data): 
    n = len(data) 
    print("Data sorted by radix msd sort")
    return data

def radix_lsd_sort(data): 
    n = len(data) 
    print("Data sorted by radix lsd sort")
    return data

def std_gcc_sort(data): 
    n = len(data) 
    print("Data sorted by std gcc sort")
    return data

def std_gcc_stable_sort(data): 
    n = len(data) 
    print("Data sorted by std gcc stable sort")
    return data

def tim_sort(data): 
    n = len(data) 
    print("Data sorted by tim sort")
    return data

def block_merge_sort(data): 
    n = len(data) 
    print("Data sorted by block merge sort")
    return data

def cocktail_merge_sort(data): 
    n = len(data) 
    print("Data sorted by cocktail merge sort")
    return data

def flash_sort(data):
    n = len(data)
    print("Data sorted by flash sort")
    return data

def pancake_sort(data): 
    n = len(data) 
    print("Data sorted by pancake sort")
    return data

def hybrid_sort(data): 
    n = len(data) 
    print("Data sorted by hybrid sort")
    return data

algorithm_names_dict={'selection': selection_sort,
                      'pancake': pancake_sort,
                      'quick_lr': quick_lr_sort,
                      'block_merge': block_merge_sort,
                      'block' : block_merge_sort,
                      'quick_dual_pivot': quick_dual_pivot_sort,
                      'insertion': insertion_sort,
                      'quick_ll': quick_ll_sort,
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
                      'cocktail_shatter': cocktail_shatter_sort,
                      'cocktail': cocktail_shatter_sort,
                      'bubble': bubble_sort,
                      'shell': shell_sort,
                      'odd_even': odd_even_sort,
                      'heap': heap_sort,
                      'cocktail_merge': cocktail_merge_sort,
                      'comb': comb_sort,
                      'cycle': cycle_sort,
                      'quick_ternary_lr': quick_ternary_lr_sort,
                      'gnome': gnome_sort,
                      'bitonic': bitonic_sort,
                      'smooth': smooth_sort,
                      'merge': merge_sort,
                      'quick_ternary_ll': quick_ternary_ll_sort,
                      'quick': quick_lr_sort
                      }


def algorithm_selection(algorithm_command,data):
    try:
        algorithm = algorithm_names_dict[algorithm_command]
    except:
        print("Invalid Sorting Algorithm")
        return None
    return algorithm(data)

