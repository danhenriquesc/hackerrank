#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    int tot = 0;
    
    if(b.front() % a.back() != 0) return 0;
    
    for(int i = a.back(); i <= b.front(); i += a.back()){
        bool status = true;
        
        for(int j = 0; j < a.size(); j++){
            if(i%a[j]){
                status = false;
                break;
            }
        }
        
        if(status){
            for(int j = 0; j < b.size(); j++){
                if(b[j]%i){
                    status = false;
                    break;
                }
            }
        }
        
        if(status) tot++;
    }
    
    return tot;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}