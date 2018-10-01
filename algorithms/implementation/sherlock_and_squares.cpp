/*
Solution for https://www.hackerrank.com/challenges/sherlock-and-squares/problem
Author: Pushkar Anand (https://github.com/pushkar-anand)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long t, a, b;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<floor(sqrt(b)) - ceil(sqrt(a)) + 1<<endl;
    }
    return 0;
}
