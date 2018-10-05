import math
import os
import random
import re
import sys

# Complete the largestRectangle function below.
def largestRectangle(h):
    h.append(0)
    s = []
    maxa = len(h)
    for i in range(len(h)):
        left_index = i
        while(len(s)>0 and s[-1][0] >= h[i]):
            last = s.pop()
            left_index = last[1]
            maxa = max(maxa, h[i] * (i + 1 - last[1]))
            maxa = max(maxa, last[0] * (i - last[1]))
        s.append((h[i], left_index))
    return maxa

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    h = list(map(int, input().rstrip().split()))

    result = largestRectangle(h)

    fptr.write(str(result) + '\n')

    fptr.close()
