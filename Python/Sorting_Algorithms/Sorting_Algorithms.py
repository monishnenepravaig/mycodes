
def selection_sort(original,n):
    return result

def insertion_sort(original,n):
    return result

def binary_insertion_sort(original,n):
    return result

def merge_sort(original,n):
    return result

def quick_lr_sort(original,n):
    return result

def quick_ll_sort(original,n):
    return result

def quick_ternary_lr_sort(original,n):
    return result

def quick_ternary_ll_sort(original,n):
    return result

def quick_dual_pivot_sort(original,n):
    return result

def bubble_sort(original,n):
    return result

def cocktail_shatter_sort(original,n):
    return result

def gnome_sort(original,n):
    return result

def gravity_sort(original,n):
    return result

def shell_sort(original,n):
    return result

def comb_sort(original,n):
    return result

def heap_sort(original,n):
    return result

def smooth_sort(original,n):
    return result

def odd_even_sort(original,n):
    return result

def bitonic_sort(original,n):
    return result

def cycle_sort(original,n):
    return result

def radix_msd_sort(original,n):
    return result

def radix_lsd_sort(original,n):
    return result

def std_gcc_sort(original,n):
    return result

def std_gcc_stable_sort(original,n):
    return result

def tim_sort(original,n):
    return result

def block_merge_sort(original,n):
    return result

def cocktail_merge_sort(original,n):
    return result

def flash_sort(original,n):
    return result

def pancake_sort(original,n):
    return result

def hybrid_sort(original,n):
    return result

algorithm_names_dict={'selection': selection_sort,
                      'pancake': pancake_sort,
                      'quick_lr': quick_lr_sort,
                      'block_merge': block_merge_sort,
                      'quick_dual_pivot': quick_dual_pivot_sort,
                      'insertion': insertion_sort,
                      'quick_ll': quick_ll_sort,
                      'binary_insertion': binary_insertion_sort,
                      'radix_lsd': radix_lsd_sort,
                      'std_gcc_stable': std_gcc_stable_sort,
                      'std_gcc': std_gcc_sort,
                      'radix_msd': radix_msd_sort,
                      'flash': flash_sort,
                      'hybrid': hybrid_sort,
                      'gravity': gravity_sort,
                      'tim': tim_sort,
                      'cocktail_shatter': cocktail_shatter_sort,
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
                      'quick_ternary_ll': quick_ternary_ll_sort
                      }

def algorithm_selection(algorithm_command,original,n):
    try:
        algorithm = algorithm_names_dict[algorithm_command]
    except:
        print("Invalid Sorting Algorithm")
        return None
    return algorithm(original,n)

