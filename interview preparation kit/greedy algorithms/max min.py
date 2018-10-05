from itertools import combinations
n = int(input().strip())
k = int(input().strip())
a=[]
for i in range(n):
    ai = int(input().strip())
    a.append(ai)
a = sorted(a)
minn=0
x=max(a)
for i in range(0,n-k+1,1):
    minn = a[i+k-1]-a[i]
    if(minn<=x):
        x=minn
print(x)
