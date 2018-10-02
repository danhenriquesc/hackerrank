#!/bin/python3

import os
import sys

#
# Complete the gradingStudents function below.
#
def gradingStudents(grades):
    arr=[]
    for i in grades:
        if (i%5) > 2 and i>=38:
            arr.append(i+(5-i%5))
            continue
     
        else:
            arr.append(i)
    return arr
        

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    grades = []

    for _ in range(n):
        grades_item = int(input())
        grades.append(grades_item)

    result = gradingStudents(grades)

    f.write('\n'.join(map(str, result)))
    f.write('\n')

    f.close()