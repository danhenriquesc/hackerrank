
import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.

n = int(input())

arr = list(map(int, input().rstrip().split()))

numSwaps = 0
i = 0
while(i < len(arr)-1):
    if arr[i] != i+1:
        tmp = arr[i]
        arr[i], arr[tmp-1] = arr[tmp-1], arr[i]
        numSwaps += 1
    else:
        i += 1
print(numSwaps)