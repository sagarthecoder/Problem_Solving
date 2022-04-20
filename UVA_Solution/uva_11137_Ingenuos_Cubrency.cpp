#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[25];
ll dp[19262][25];
ll go(ll i,ll start)
{
    ll p,q;
    if(i==21)return 0;
    if(dp[start][i]!=-1)return dp[start][i];
    if(start-ara[i]==0)return 1;
    if(start-ara[i]>=0)p=go(i,start-ara[i]);
    else p=0;
    q=go(i+1,start);
    return dp[start][i]=p+q;

}
int main()
{
    for(int i=1;i<=21;i++)ara[i-1]=i*i*i;
    ll n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld",&n)!=EOF)
    {
        ll res=go(0,n);
        printf("%lld\n",res);

    }
    return 0;
}
