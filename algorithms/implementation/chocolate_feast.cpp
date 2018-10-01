/*
Solution for https://www.hackerrank.com/challenges/chocolate-feast/problem
Author: Pushkar Anand (https://github.com/pushkar-anand)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int availOff(int wrap, int m){
    int r=0,x=0;
    while(wrap>=m){
        x=wrap/m;
        r+=x;
        wrap=wrap%m;
        wrap+=x;
    }
    return r;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m,temp;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        // Computer answer
        answer = n/c;
        temp = availOff(answer, m);
        answer += temp;
        cout<<answer<<endl;
    }
    return 0;
}
