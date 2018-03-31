#!/bin/python3
import os


def pangrams(s):
    return "{}pangram".format(
        "not " if (len(set(s.lower().replace(" ", ""))) != 26) else ""
    )


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = pangrams(s)
    fptr.write(result + '\n')
    fptr.close()
