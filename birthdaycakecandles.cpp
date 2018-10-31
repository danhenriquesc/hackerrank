#include<iostream>
using namespace std;
int main()
{
    int n,i,A[100001],max,c=0; 
    cin>>n;
    max=0;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
        if(max<A[i])
        {
            max=A[i];
        }
    }
    //cout<<max;
    for(i=0;i<n;i++)
    {
        if(max==A[i])
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}
