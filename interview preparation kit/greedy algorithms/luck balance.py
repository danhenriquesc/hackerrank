n,k = input().strip().split(' ')
n,k = [int(n),int(k)]
a=[]
b=[]
luck=0
for i in range(n):
    ai = [int(ai) for ai in input().strip().split(' ')]
    if(ai[1]==1):
        a.append(ai[0])
    else:
        luck = luck+ai[0]
a = sorted(a)
i=0
while(i<len(a)-k):
    luck = luck-a[i]
    i=i+1
while(i<len(a)):
    luck = luck+a[i]
    i=i+1
print(luck)
