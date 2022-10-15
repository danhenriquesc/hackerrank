# Complete the plusMinus function below.
def plusMinus(arr):
    pos, neg, zero = 0,0,0
    for el in arr:
        if el > 0: pos +=1
        elif el < 0: neg +=1
        else: zero +=1
    print(round(pos/len(arr), 6))
    print(round(neg/len(arr), 6))
    print(round(zero/len(arr), 6))
