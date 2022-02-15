#include <iostream>
using namespace std;

int main()
{
   int n,d,i;
    cin>>n>>d;
    long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=d;i<n+d;i++)
        cout<<a[i%n]<<" ";
    return 0;
}