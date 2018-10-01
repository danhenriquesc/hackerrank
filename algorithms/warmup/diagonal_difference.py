sm = 0
for i in range(int(input())):
    lst = list(map(int,input().split()))
    sm += lst[i]- lst[-(i+1)]
print(abs(sm))