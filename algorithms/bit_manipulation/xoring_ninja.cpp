#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000000007;
ll cal(ll a,ll n){
    ll ans=1LL;
    while(n>0LL){
        if(n&1LL){
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        n/=2LL;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    ll ans,a;
    cin>>ans;
    for(int i=1;i<n;i++){
        cin>>a;
        ans=ans|a;
    }
    ans=ans%M;
    n--;
    cout<<(ans*cal(2LL,(ll)n))%M<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}