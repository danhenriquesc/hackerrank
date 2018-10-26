#!/bin/python3

import os

# Complete the twoStrings function below.
def twoStrings(s1, s2):
    intersection = set(s1) & set(s2)
    if len(intersection) > 0:
        return "YES"
    return "NO"
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
