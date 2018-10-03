#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <long long int> arr) {
    sort(arr.begin(), arr.end());
    cout<<arr[0]+arr[1]+arr[2]+arr[3]<<' '<<arr[4]+arr[1]+arr[2]+arr[3];
}

int main() {
    vector<long long int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMaxSum(arr);
    return 0;
}
