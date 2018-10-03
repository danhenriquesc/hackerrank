#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(unsigned long int n, vector <long long int> ar) {
    sort(ar.begin(),ar.end());
    unsigned long int x=0;
    for(long int ar_i = n-1; ar_i > -1; ar_i--){
        if(ar[n-1]==ar[ar_i]) x++;
        else break;
    }
    return x;
}

int main() {
    unsigned long int n;
    cin >> n;
    vector<long long int> ar(n);
    for(unsigned long int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    unsigned long int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}

