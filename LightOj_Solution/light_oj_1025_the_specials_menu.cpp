
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[62][62];
char x[63];
ll go(int i,int j)
{
    if(i==j)return 1;
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(x[i]==x[j])return dp[i][j]=1+go(i,j-1)+go(i+1,j);
    else return dp[i][j]=go(i,j-1)+go(i+1,j)-go(i+1,j-1);
}
int main()
{
        int t;scanf("%d",&t);
        for(int a=1;a<=t;a++)
        {
            scanf("%s",x);
            printf("Case %d: ",a);
            memset(dp,-1,sizeof(dp));
            int len=strlen(x);
            ll ans=go(0,len-1);
            printf("%lld\n",ans);
        }
        return 0;
}
