#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    int min, vmin, max, vmax;
    if(x1>x2){
        min = x2;
        vmin = v2;
        max=x1;
        vmax=v1;
    }else{
        min = x1;
        vmin = v1;
        max=x2;
        vmax=v2;
    }
    
    while(min < max){
        min += vmin;
        max += vmax;
    }
    
    return (min == max) ? "YES" : "NO";
}

int main() {
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    string result = kangaroo(x1, v1, x2, v2);
    cout << result << endl;
    return 0;
}