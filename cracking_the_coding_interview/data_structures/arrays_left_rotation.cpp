#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0;i < n;++i) cin >> a[i];
    rotate(a.begin(),a.begin()+k,a.end());
    for(const auto& e : a) cout << e << " ";
    cout << endl;
    return 0;
}
