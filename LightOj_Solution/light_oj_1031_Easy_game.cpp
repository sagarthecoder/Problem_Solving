#include <bits/stdc++.h>
#define ll long long
int dp[104][104][2];
int ara[104];
int sum[104][104];
int inf=10000000,n;
using namespace std;
int go(int left,int right,int turn)
{
    if(left+right==n)return 0;
    if(dp[left][right][turn]!=inf)return dp[left][right][turn];
    int prev;
    if(turn)prev=inf;
    else prev=-inf;

    for(int i=1;i<=n-left-right;i++)
    {
        if(turn)prev=min(prev,-sum[left+1][left+i]+go(left+i,right,1-turn));
        else prev=max(prev,sum[left+1][left+i]+go(left+i,right,1-turn));

        if(turn)prev=min(prev,-sum[n-right-i+1][n-right]+go(left,right+i,1-turn));
        else prev=max(prev,sum[n-right-i+1][n-right]+go(left,right+i,1-turn));

    }
    //cout<<"prev = "<<prev<<endl;
    return dp[left][right][turn]=prev;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=1;k++)dp[i][j][k]=inf;
    for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)sum[i][j]=sum[i][j-1]+ara[j];
    int ans=go(0,0,0);
    printf("Case %d: %d\n",a,ans);

    }
    return 0;
}
