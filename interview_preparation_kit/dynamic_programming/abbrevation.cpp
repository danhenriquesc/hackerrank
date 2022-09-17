#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <ctype.h>
using namespace std;

bool recurse(string & a, string & b, int i, int j, map<long, bool> & m) {
    long comb = ((long)i << 32) | j;
    auto find_comb = m.find(comb);
    
    if(find_comb != m.end())
        return find_comb->second;
    
    if (j == b.length()) {
        for (; i < a.length();i++) {
            if(isupper(a[i])) {
                m[comb] = false;
                return false;
            }
        }
        m[comb] = true;
        return true;
    }
    
    if(i == a.length())
        return false;
    
    if(isupper(a[i]) && a[i] != b[j])
        return false;
    
    if(toupper(a[i]) != b[j])
        m[comb] = recurse(a, b, i + 1, j, m);
    else {
        if (isupper(a[i]))
            m[comb] = recurse(a, b, i + 1, j + 1, m);
        else
            m[comb] = recurse(a, b, i + 1, j + 1, m) || recurse(a, b, i + 1, j, m);
    }
    
    return m[comb];
}

bool find_ans(string & a, string & b) {
    int first_occ;
    for(int j = 0; j < a.length(); j++) {
        if(toupper(a[j]) == b[0]) {
            first_occ = j;
            break;
        }
        if (isupper(a[j]))
            return false;
    }
    
    map<long, bool> m;
    return recurse(a,b,first_occ,0,m);
}

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string a;
        string b;
        cin >> a >> b;
        cout << (find_ans(a,b) ? "YES" : "NO") << endl;
    }
    return 0;
}