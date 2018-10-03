#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a.size())
#define pll pair<ll,ll>
#define LL long long int 
LL a[1000010];
LL count1=0;
void merge(LL a[],LL x[],LL y[],LL l,LL r)
{
		LL i=0;
		LL j=0;
		LL k=0;
		while(i<l && j<r)
		{
				if(x[i]>y[j])
				{
						count1+=l-i;
						j++;
				}
				else 
						i++;
		}
		i=0;
		j=0;
		while(i<l && j<r)
		{
				if(x[i]<=y[j])
				{
						a[k]=x[i];
						k++;
						i++;
				}
				else
				{
						a[k]=y[j];
						k++;
						j++;
				}
		}
		while(i<l)
		{
				a[k]=x[i];
				k++;
				i++;
		}
		while(j<r)
		{
				a[k]=y[j];
				k++;
				j++;
		}

}
void mergesort(LL a[],LL n)
{
		if(n<2)
				return;
		LL mid=n/2;
		LL x[mid];
		LL y[n-mid];
		LL i,j;
		for(i=0;i<mid;i++)
				x[i]=a[i];
		for(j=0;j<n-mid;j++)
		{
				y[j]=a[i];
				i++;
		}
		mergesort(x,mid);
		mergesort(y,n-mid);
		merge(a,x,y,mid,n-mid);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	LL t;
		scanf("%lld",&t);
		LL n;
		LL i;
		while(t--)
		{
				count1=0;
				scanf("%lld",&n);
				for(i=0;i<n;i++)
						scanf("%lld",&a[i]);
				mergesort(a,n);
				printf("%lld\n",count1);
		}
		return 0;
}