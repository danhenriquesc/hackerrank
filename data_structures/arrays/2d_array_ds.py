import math
import os
import random
import re
import sys
 # Complete the hourglassSum function below.
def hourglassSum(arr):
    
    value = None
    
    # Starting i in the first middle value
    # first_col < i < last_col
    i = 2
    
    # Starting j in the first middle value
    # first_row < j < last_row
    j = 2
    
    last_col_n = len(arr[0])
    last_row_n = len(arr)
    
    # i-1,j-1  i,j-1    i+1,j-1
    #          i,j
    # i-1,j+1  i,j+1    i+1,j+1
    while j < last_row_n:
        while i < last_col_n:
            if value == None:
                value = arr[i-1][j-1] + arr[i][j-1] + arr[i+1][j-1] + arr[i][j] + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1]    
            else:
                new_sum = arr[i-1][j-1] + arr[i][j-1] + arr[i+1][j-1] + arr[i][j] + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1]
                if new_sum > value:
                    value = new_sum
        
    return value
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    arr = []
    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))
        result = hourglassSum(arr)
        fptr.write(str(result) + '\n')
        fptr.close()