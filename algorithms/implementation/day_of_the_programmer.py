#!/bin/python3


def leapJulian(year):
    return year % 4 == 0


def leapGregorian(year):
    return (year % 4 == 0 and year % 100 > 0) or year % 400 == 0


def solve(year):
    if year >= 1919:
        if(leapGregorian(year)):
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)

    elif year <= 1917:
        if(leapJulian(year)):
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)
    else:
        return "26.09." + str(year)


year = int(input().strip())
result = solve(year)
print(result)
