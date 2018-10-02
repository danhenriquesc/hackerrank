#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the luckBalance function below.
def luckBalance(k, contests):
    imp = []
    luck = 0
    for i in contests:
        if i[1] != 0:
            imp.append(i[0])
        else:
            luck = luck + i[0]

    imp.sort(reverse=True)

    luck = luck + sum(imp[0:k]) - sum(imp[k:])
    return luck


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
