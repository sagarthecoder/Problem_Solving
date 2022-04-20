
#include <bits/stdc++.h>
using namespace std;
int dp[(1<<16)+2],n,v,ara[20][20];
int Set(int n,int i)
{
    return n|(1<<i);
}
int reset(int n,int i)
{
    return n&(~(1<<i));
}
bool check(int n,int i)
{
    return n&(1<<i);
}
int go(int mark,int i)
{
    if(i==n || mark==v)return 0;
    if(dp[mark]!=-1)return dp[mark];
    ///if(mark==v)return 0;
    int ans=0;
    for(int j=0;j<n;j++)
    {
        if(!check(mark,j))
        {
            int res=ara[i][j]+go(Set(mark,j),i+1);
            ///cout<<"res  ="<<res<<endl;
            ans=max(ans,res);
        }
    }
    return dp[mark]=ans;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        v=(1<<n)-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)scanf("%d",&ara[i][j]);
        int ans=go(0,0);
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
