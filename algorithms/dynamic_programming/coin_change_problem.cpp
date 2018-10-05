#include <bits/stdc++.h>
using namespace std;

long getWays(long n, vector<long> c) 
{
    long m = c.size();
    vector <vector <long> > dp(m+1,vector<long> (n+1));
    for(long i=0; i<=m; i++)
        dp[i][0] = 1;
    for(long j=1; j<=n; j++)
        dp[0][j] = 0;
    for(long i=1; i<=m ;i++)
    {
        for(long j=1; j<=n ; j++)
        {
            if(c[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j-c[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main()
{
    long n,m;
    cin>>n>>m;
    vector <long> c(m);
    for(long i=0; i<m; i++)
        cin>>c[i];
    long res = getWays(n,c);
    cout << res;
    return 0;
}