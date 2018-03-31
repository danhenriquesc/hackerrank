#include <vector>
#include <iostream>

using namespace std;


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    int tot_apple = 0, tot_orange = 0;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
       if( (apple[apple_i]+a >= s) && (apple[apple_i]+a <= t)){
           tot_apple++;
       }
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
       if( (orange[orange_i]+b >= s) && (orange[orange_i]+b <= t)){
           tot_orange++;
       }
    }
    
    cout << tot_apple << endl << tot_orange << endl;
    return 0;
}