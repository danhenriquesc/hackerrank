#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    vector <int> r;
    int bmin = 0, bmax = 0, min = s.front(), max = s.front();
    
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] > max){
            max = s[i]; bmax++;
        }
        
        if(s[i] < min){
            min = s[i]; bmin++;
        }
    }
    
    r.push_back(bmax);
    r.push_back(bmin);
    
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}