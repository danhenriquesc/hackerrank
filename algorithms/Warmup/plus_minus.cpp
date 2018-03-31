#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int p=0, neg=0, z=0;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        if (arr[arr_i] > 0) 
            p++;
        else if (arr[arr_i] == 0)
            z++;
        else if (arr[arr_i] < 0) 
            neg++;
    }
    cout << fixed;
    cout.precision(6);
    cout << ((float)p/(float)n) << endl << ((float)neg/(float)n) << endl << ((float)z/(float)n);
    return 0;
}