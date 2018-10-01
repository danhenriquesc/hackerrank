#!/bin/python3

import sys

def timeConversion(s):
    if s.endswith("AM"):
        s = s.strip("AM")
        h, m, ss = s.split(":")
        if int(h) == 12:
            h = int(0)
        return "{:02}:{}:{}".format(int(h), m, ss)
    else:
        s = s.strip("PM")
        h, m, ss = s.split(":")
        if int(h) == 12:
            h = int(h)
        else:
            h = (int(h) + 12) % 24
        return "{:02}:{}:{}".format(h, m, ss)

s = input().strip()
result = timeConversion(s)
print(result)
