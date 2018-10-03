#include <iostream>
using namespace std;

int solve(int n,int k){
    if(k == 0){
        for(int i = 1 ; i <= n ; i++){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    
    if(n % (2 * k) == 0){
        int t = k;
        for(int i = 1 ; i <= n ; i++){
            cout << i + t << " ";
            if(i % k == 0){
                t *= -1;
            }
        }
        cout << endl;
        return 0;
    }
    
    cout << -1 << endl;
    return 0;
}

int main(){
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        solve(n,k);
    }
}