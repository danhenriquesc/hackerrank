#!/bin/python3


def getMoneySpent(keyboards, drives, s):
    maxV = -1
    selectedKb = -1
    selectedD = -1
    for keyboard in keyboards:
        for drive in drives:
            if drive + keyboard <= s and drive + keyboard > maxV:
                maxV = drive + keyboard
                selectedD = drive
                selectedKb = keyboard

    maxKD = max(selectedD, selectedKb)
    minKD = min(selectedD, selectedKb)

    if maxV > -1:
        while maxV + maxKD <= maxV:
            maxV = maxV + maxKD

        while maxV + minKD <= maxV:
            maxV = maxV + minKD

    return maxV


s, n, m = input().strip().split(' ')
s, n, m = [int(s), int(n), int(m)]
keyboards = list(map(int, input().strip().split(' ')))
drives = list(map(int, input().strip().split(' ')))
moneySpent = getMoneySpent(keyboards, drives, s)
print(moneySpent)
