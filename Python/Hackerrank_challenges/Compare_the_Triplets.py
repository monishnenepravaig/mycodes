#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(a, b):
    n = len(a)
    m = len(b)
    if n > m:
        r = m
    else:
        r = n
    a_score = 0
    b_score = 0
    result = []
    for i in range (0,r):
        if a[i] > b[i]:
            a_score += 1
        elif b[i] > a[i]:
            b_score += 1
    result.append(a_score)
    result.append(b_score)
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = solve(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
