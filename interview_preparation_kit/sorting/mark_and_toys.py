#!/bin/python3
 import math
import os
import random
import re
import sys

 # Complete the maximumToys function below.
def maximumToys(prices, k):
    sorted_prices = sorted(prices)
    count = 0
    for p in sorted_prices:
        if k > p:
            k -= p
            count += 1
    return count

 if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
     nk = input().split()
     n = int(nk[0])
     k = int(nk[1])
     prices = list(map(int, input().rstrip().split()))
     result = maximumToys(prices, k)
     fptr.write(str(result) + '\n')
     fptr.close()