#include <iostream>

using namespace std;

int main(){
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    
    int p1 = 0, p2 = 0;
    if(a0>b0) p1++;
    else if(b0>a0) p2++;
    
    if(a1>b1) p1++;
    else if(b1>a1) p2++;
    
    if(a2>b2) p1++;
    else if(b2>a2) p2++;
        
    cout << p1 << " " << p2;
    
    return 0;
}
