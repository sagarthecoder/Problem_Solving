#include <bits/stdc++.h>
#define ll long long
using namespace std;
char x[120];
int dp[102][102];
int go(int i,int j)
{
    if(i==j)return 1;
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(x[i]==x[j])return dp[i][j]=2+go(i+1,j-1);
    else return dp[i][j]=max(go(i+1,j),go(i,j-1));
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%s",x);
        memset(dp,-1,sizeof(dp));
        int len=strlen(x);
        int ans=go(0,len-1);
        printf("Case %d: %d\n",a,len-ans);
    }
    return 0;
}
