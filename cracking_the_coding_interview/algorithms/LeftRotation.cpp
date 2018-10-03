#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a.size())
#define pll pair<ll,ll>
ll a[1000005];
ll b[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,d,i;
	cin>>n>>d;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		ll temp = (i-d+n)%n;
		b[temp]=a[i];
	}
	for(i=0;i<n;i++)
		cout<<b[i]<<' ';
	cout<<endl; 
	return 0;
}