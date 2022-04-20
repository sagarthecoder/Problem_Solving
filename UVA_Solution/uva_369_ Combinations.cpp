#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[101][101];
ll go(ll n,ll r)
{
    if(dp[n][r])return dp[n][r];
    if(r==0)return 1;
    if(r==n)return 1;
    if(r==1)return n;
     return dp[n][r]= go(n-1,r-1)+go(n-1,r);
}
int main()
{
    ll n,m;
    while(true)
    {
        scanf("%lld %lld",&n,&m);
        if(n==0 && m==0)break;
        ll ans=go(n,m);
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,ans);
    }
    return 0;
}
