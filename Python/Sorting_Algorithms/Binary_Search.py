def Binary_Search_Array(x,data):
    n = len(data)
    if n == 1 or n == 2:
        if x <= data[0]:
            location = 0
        elif x >= data[n-1]:
            location = n
        else:
            location = 1
        return location
    middle = data[int(n/2)]
    if x > middle:
        location = Binary_Search_Array(x,data[int((n/2)+1):])
        location += (int(n/2)+1)
    else:
        location = Binary_Search_Array(x,data[:int((n/2)+1)])
    return location
        
