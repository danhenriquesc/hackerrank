#include <bits/stdc++.h>
using namespace std;
int mod (int x)
{
    if(x<0)
        return (-1)*x;
    else
        return x;
}
int main()
{
    string str;
    int T,x,i,sum;
    cin>>T;
    assert(1<=T && T<=100);
    int count[26];
    while(T--)
    {
        for(i=0 ;  i<26 ; i++)
            count[i] = 0;
        sum =0;
        cin>>str;
        x = str.length();
        
        assert(1<=x && x<=10000);
        if(x%2==1)
            cout<<"-1"<<endl;
        else
        {
            for(i=0 ; i<x/2 ; i++)
                count[str[i] - 'a']++;
            for(i=x/2 ; i<x ; i++)
                count[str[i] - 'a']--;
            
            for(i=0 ; i<26 ; i++)
            {
                sum = sum + mod(count[i]);
            }
            sum = sum/2;
            cout<<sum<<endl;
        }
    }
    return 0;
}
