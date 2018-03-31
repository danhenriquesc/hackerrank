#include <iostream>
using namespace std;


void kadane(int *v, int n, int & x, int &y , int & max_total){
    int max_atual;
    int xtemp;
    int i;
    max_atual = 0;
    max_total = -1;
    xtemp = 0;
    for(i=0;i<n;i++){
        max_atual = max_atual + v[i];
        if(max_atual < 0) { 
            max_atual = 0;
            xtemp = i+1;
        }
        if(max_atual > max_total){
            max_total = max_atual;
            x = xtemp;
            y = i;
        } 
    }
}

int main() {
    int x,y,max,count;
 
    int T,C, v[200000];
    cin >> T;
    while (T--){
        cin >> C;
        count = 0;
        for(int i = 0; i<C;i++){
            cin >> v[i];
            if(v[i] > 0) count += v[i];
        }
        if(count == 0){
            count = v[0];
            for(int i = 1; i<C;i++){
                if(v[i] > count) count = v[i];
            }
            cout << count << " " << count << endl;
        }else{
        kadane(v,C,x,y,max);
        cout << max << " " << count << endl;
        }
    }
    
    return 0;
}
