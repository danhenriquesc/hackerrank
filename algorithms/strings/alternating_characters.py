#!/bin/python3


def alternatingCharacters(s):
    i = 0
    for j in range(len(s) - 1):
        if s[j] == s[j + 1]:
            i += 1
    return i


q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = alternatingCharacters(s)
    print(result)
