#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    int alltot = 0;
    for(int i = 0; i < s.size() - m+1; i++){
        int tot = 0;
        for(int j = 0; j < m; j++){
            tot += s[i+j];
        }
        
        if(tot == d) alltot++;
    }
    
    return alltot;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}