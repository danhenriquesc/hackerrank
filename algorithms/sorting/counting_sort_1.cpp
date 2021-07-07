#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    int a[100];
    for(int i=0;i<100;i++)a[i]=0;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        a[num]++;
    }
    for(int i=0;i<100;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}