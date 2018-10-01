# Enter your code here. Read input from STDIN. Print output to STDOUT
s=raw_input().split();
a=(int)(s[0]);
b=(int)(s[1]);
x=(int)(s[2]);
if (x<3):
    if(x==1):
        print a
    else:
        print b
    
else:
    c = a + b*b
    x = x - 2
    while (x>0):
        a = b
        b = c
        c = a + b*b
        x = x - 1
    print b
    
