#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sumXor function below.
def sumXor(n):
    return(2**(bin(n).count('0')-1) if n else 1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    result = sumXor(n)

    fptr.write(str(result) + '\n')

    fptr.close()
