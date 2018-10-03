#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    if(s[s.length()-2]=='P'){
        if(s[1]=='2' && s[0]=='1'){
            s.erase(s.begin()+8);s.erase(s.begin()+8);
            return s;   
        }
        int time=((int)s[0]-48)*10+(int)s[1]-48+12;
        if(time==24) time=00;
        s[0] = time/10+48;
        s[1] = time%10+48;
        
        s.erase(s.begin()+8);s.erase(s.begin()+8);
        return s;
    }
    else{
        if(s[1]=='2' && s[0]=='1') {
            s[1]='0';
            s[0]='0';
        }
        s.erase(s.begin()+8);s.erase(s.begin()+8);
        return s;
    }
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}

