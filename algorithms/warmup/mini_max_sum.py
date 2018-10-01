#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    min=1000000001
    max=0
    sum=0
    for i in arr:
        sum+=i
        if (i>max):
            max=i
        if (i<min):
            min=i
    print(sum-max,sum-min)
if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
