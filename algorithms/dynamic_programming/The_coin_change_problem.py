a,n=map(int,input().split())
q=list(map(int,input().split()))
l=[1]
q=sorted(q)
for i in range(0,a):
    l.append(0)
for coin in q:
    for amount in range(1,a+1):
        if amount>=coin:
            l[amount]=l[amount-coin]+l[amount]
print(l[-1])
