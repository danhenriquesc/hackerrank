def reverse(l,low,high):
   while low<high:
      l[low],l[high]=l[high],l[low]
      low+=1
      high-=1
n,d=map(int,input().split())
l=list(map(int,input().split()))
reverse(l,0,d-1)
reverse(l,d,n-1)
l.reverse()
for i in range(n):
   print(l[i],end=" ")
   
   
