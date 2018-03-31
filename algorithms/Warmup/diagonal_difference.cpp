#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n;
    int s1=0,s2=0;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
          
           if(a_i == a_j) s1+=a[a_i][a_j];
           if(a_i == n-1-a_j) s2+=a[a_i][a_j];
           
       }
    }
    
    cout << abs(s1-s2);
    return 0;
}
