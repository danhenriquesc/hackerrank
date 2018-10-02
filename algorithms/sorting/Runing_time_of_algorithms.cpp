#include <bits/stdc++.h>

using namespace std;

int runningTime(vector <int> arr) {
    // Complete this function
    int shifts = 0 ;
    for(int i = 0 ; i<arr.size(); i++)
    {
        int temp = arr[i];
        int j = i; 
        
        while(j>0 && temp<arr[j-1])
        {
            arr[j] =arr[j-1];
            j--;
            shifts++;
        }
        arr[j] =temp ;
    }
    return shifts;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = runningTime(arr);
    cout << result << endl;
    return 0;
}

