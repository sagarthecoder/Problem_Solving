#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[102][102],n,k;
ll mod=1000000;
ll go(ll cnt,ll sum)
{
    ll ans=0;
    if(sum>n)return 0;
    if(sum==n && cnt==k)
    {
        return 1;
    }
    if(cnt>=k || sum>n || (cnt>=k && sum!=n))return 0;
    if(dp[cnt][sum]!=-1)return dp[cnt][sum];
    for(int i=0;i<=n;i++)
    {
        ans=((ans%mod)+(go(cnt+1,sum+i))%mod)%mod;
    }
    return dp[cnt][sum]=ans;
}
int main()
{
    while(true){
    scanf("%lld %lld",&n,&k);
    if(!n && !k)break;
    memset(dp,-1,sizeof(dp));
    ll  ans=go(0,0);
    printf("%lld\n",ans);

    }
    return 0;
}
