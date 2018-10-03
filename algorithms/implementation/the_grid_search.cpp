#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(vector<string> a,vector<string> b,int R,int r,int C,int c) {
    bool found = false;
    
    for(int i = 0 ; i <= R - r ; i++){
        for(int j = 0 ; j <= C - c ; j++){
            int p = 0,k = i;
            while(a[k].substr(j,c) == b[p].substr(0,c)){
                if(k - i + 1 == b.size()){
                    found = true;
                    break;
                }
                k++;p++;
            }
        }
    }
    
    if(found == true){
        return "YES";
    }else{
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C, r, c;
        vector<string> a;
        vector<string> b;
        string s;
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            cin >> s;
            a.push_back(s);
        }

        cin >> r >> c;

        for (int i = 0; i < r; i++) {
            cin >> s;
            b.push_back(s);
        }
        
        cout << solve(a,b,R,r,C,c) << endl;
    }
}