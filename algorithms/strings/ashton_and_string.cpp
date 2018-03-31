#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    for(int j=0; j<n; ++j)
    {
        string s;
        int k;
        cin >> s >> k;
        
        int i;
        vector<pair<int, int>> vv;
        auto it = vv.begin();
        for(char c='a'; c<= 'z' && k>0; ++c)
        {
            vv.clear();
            for (int j = 0; j<s.length(); ++j)
            {
                if(s[j] == c)
                   vv.push_back(pair<int, int>(j, s.length() - j));
            }

            sort(vv.begin(), vv.end(), [&](pair<int, int> &a, pair<int, int> &b){return s.substr(a.first, a.second) < s.substr(b.first, b.second);});

            for (it = vv.begin(); it != vv.end() && k >= 0; ++it)
            {
                i=1;
                while(it != vv.begin() && s[prev(it)->first+i-1] == s[it->first+i-1])
                       ++i;

                while(i <= it->second && k>0)
                    k -= i++;
            }
        }
        cout << s[prev(it)->first + k + i-2] << '\n';        
    }
    return 0;
}