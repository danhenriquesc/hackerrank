#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    
    n = len(arr)
    
    neg = pos = zero = 0
    for i in arr:
        if i == 0:
            zero+=1
        elif i>0:
            pos+=1
        elif i<0:
            neg+=1
            
    print("%.6f" % ((pos/n)))
    print("%.6f" % ((neg/n)))
    print("%.6f" % ((zero/n)))

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
