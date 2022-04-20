#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,d,m;
ll ara[203];
ll dp[201][21][11];
ll omg=0;
 ll go(ll i,ll cnt,ll sum)
{
    if(sum<0)sum+=d;
    if(cnt==m){
        //cout<<"sum = "<<sum<<endl;
       // cout<<" i = "<<i<<endl;
        if(sum%d==0)return 1;return 0;
    }
    if(i==n)return 0;
    if(dp[i][sum%d][cnt]!=-1)return dp[i][sum%d][cnt];

    ll ret=0,ret2=0;
    ret=ret+go(i+1,cnt+1,(sum+ara[i])%d);
    ret2=ret2+go(i+1,cnt,sum%d);
    return dp[i][sum%d][cnt]=(ret+ret2);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%lld %lld",&n,&q);
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
        ara[n]=0;
        printf("Case %d:\n",a);
        for(int j=1;j<=q;j++)
        {
            scanf("%lld %lld",&d,&m);
            omg=0;
             ll ans=0;memset(dp,-1,sizeof(dp));
            ans+=go(0,0,0);
            printf("%lld\n",ans);
            //cout<<"omg = "<<omg<<endl;
        }

    }
    return 0;
}
