import re
import string

def count_of_1(number):
    count = 0
    while number != 0:
        value = number & 1
        if value == 1:
            count+=1
        number = number>>1
    return count

def selection_matrix(n,r):
    high=pow(2,n)
    matrix=[]
    for i in range(high-1,-1,-1):
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

def ramen_combo(budget,ramen,extra):
    min_diff= 100000
    final=0
    groups=group_generator(extra,2)
    for noodle in ramen:
        cost = noodle
        diff = abs(cost-budget)
        if((diff==min_diff)and(cost<final))or(diff<min_diff):
            min_diff=diff
            final=cost
        for item in extra:
            cost = noodle + item
            diff = abs(cost-budget)
            if((diff==min_diff)and(cost<final))or(diff<min_diff):
                min_diff=diff
                final=cost
        for item in groups:
            cost = noodle + item[0]+item[1]
            diff = abs(cost-budget)
            if((diff==min_diff)and(cost<final))or(diff<min_diff):
                min_diff=diff
                final=cost    
    return final

def write_to_file(file_name,data):
    file = open(file_name, "a")
    file.write(str(data))
    file.close

if __name__ == "__main__":
    fp = open("task1-test-input.txt","r")
    total_cases=int(fp.readline())
    for i in range(1,total_cases+1):
        dummy=fp.readline()
        budget=int(fp.readline())
        ramen=[]
        extra=[]
        ramens=int(fp.readline())
        for j in range(ramens):
            line_in=fp.readline()
            n=re.findall('\d',line_in)
            total=0
            for z in n:
                total = total*10+int(z)
            ramen.append(total)
        extras=int(fp.readline())
        for j in range(extras):
            line_in=fp.readline()
            n=re.findall('\d',line_in)
            total=0
            for z in n:
                total = total*10+int(z)
            extra.append(total)
        print(budget,ramen,extra)
        x=ramen_combo(budget,ramen,extra)
        op="Case #"+str(i)+": "+str(x)+"\n"
        print(op)
        write_to_file("task1-output.txt", op)
    fp.close
