#include <bits/stdc++.h>
using namespace std;
int dp[(1<<14)+5];
int ara[16][16];
int v,n;
int Set(int n,int i)
{
    return n=n|(1<<i);
}
int reset(int n,int i){
return n=n&(~(1<<i));
}
bool check(int n,int i)
{
    return n&(1<<i);
}
int go(int mark)
{
    if(dp[mark]!=-1)return dp[mark];
    if(mark==v)return 0;
    int ans=1<<28;
    for(int i=0;i<n;i++)
    {
        if(check(mark,i)==0){
        int p=ara[i][i];
        for(int j=0;j<n;j++){
            if(i!=j && check(mark,j))p+=ara[i][j];
        }
        int res=p+go(Set(mark,i));
        ans=min(ans,res);
        }
    }
    return dp[mark]=ans;

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        v=(1<<n)-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)scanf("%d",&ara[i][j]);
        int res=go(0);
        printf("Case %d: %d\n",a,res);
    }
    return 0;
}
