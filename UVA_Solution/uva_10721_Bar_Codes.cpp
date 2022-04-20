#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[52][52][52];
ll n,k,m;
ll go(ll b,ll cnt,ll mx)
{
    ll ans=0;
   //cout<<"b = "<<b<<" , cnt = "<<cnt<<endl;
    if(b==n && cnt==k)
    {
        if(cnt==k){
              //  cout<<"ok bro "<<endl;
                return 1;
        }
    }
    if(b>=n || mx>=m || cnt>k ||(cnt>=k && b!=n))return 0;
    if(dp[b][cnt][mx]!=-1)return dp[b][cnt][mx];

    ans=ans+go(b+1,cnt,mx+1)+go(b+1,cnt+1,0);
    return dp[b][cnt][mx]=ans;

}
int main()
{
    while(scanf("%lld %lld %lld",&n,&k,&m)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        ll ans2=go(0,0,0);
        printf("%lld\n",ans2);
    }
    return 0;
}
