#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0;
ll ara[12],sz[12];
vector<ll>v[12];
ll dp[12][12];
ll go(ll value,ll cnt)
{
    //cout<<"value = "<<value<<endl;
    if(cnt==m)return 1;
    if(dp[value][cnt]!=-1)return dp[value][cnt];
    ll ret=0;
    for(int i=0;i<sz[value];i++)ret=ret+go(v[value][i],cnt+1);
    return dp[value][cnt]=ret;
}
int main()
{

    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ans=0;ll ok=0;
        memset(dp,-1,sizeof(dp));
        scanf("%lld %lld",&n,&m);
        for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(ara[i]-ara[j])<3)v[ara[i]].push_back(ara[j]);
            }
        }
        /*for(int i=0;i<n;i++){
           // cout<<ara[i]<<":"<<endl;
            for(int j=0;j<v[ara[i]].size();j++)cout<<v[ara[i]][j]<<" ";
            cout<<endl;
        }*/
        for(int i=0;i<n;i++)sz[ara[i]]=v[ara[i]].size();
        for(int i=0;i<n;i++)
        {
            ans+=go(ara[i],1);
        }
        for(int i=0;i<=12;i++)v[i].clear();
        printf("Case %d: %lld\n",a,ans);
    }

}
