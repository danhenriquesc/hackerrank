#!/bin/python3

def array_left_rotation(a, n, d):
    return a if n == d else a[d:] + a[:d]

n, d = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
result = array_left_rotation(a, n, d)
print(*result, sep=' ')
