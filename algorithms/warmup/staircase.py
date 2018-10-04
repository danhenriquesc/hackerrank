#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    spaces = n-1
    symbol = 1
    for i in range(n):
        for j in range(spaces):
            print(" ",end="")
        spaces-=1
        for k in range(symbol):
            print("#",end="")
        symbol+=1
        print("\n",end="")    
        
        

if __name__ == '__main__':
    n = int(input())

    staircase(n)
