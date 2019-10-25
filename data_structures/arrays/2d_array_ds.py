#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.
def hourglassSum(arr):
    lis=[-999]*16
    c=0
    for i in range(0,4):
        for j in range(0,4):
            lis[c]= sum(arr[i][j:j+3]) + sum(arr[i+2][j:j+3])
            c+=1
    c=0
    for i in range(1,5):
        for j in range(1,5):
            lis[c]+=arr[i][j]
            c+=1
    return max(lis)
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
