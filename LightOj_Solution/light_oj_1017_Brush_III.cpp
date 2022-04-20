#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[103];
int dp[102][102],n,k,w;
int go(int i,int m)
{
    if(i==n || m==k)return 0;
    if(dp[i][m]!=-1)return dp[i][m];
    int pos=i;
    for(;i<n;i++){if(ara[pos]+w>=ara[i])continue;
    else break;
    }
    return dp[pos][m]=max(i-pos+go(i,m+1),go(pos+1,m));
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d %d",&n,&w,&k);
        int x;
        for(int i=0;i<n;i++)scanf("%d %d",&x,&ara[i]);
        sort(ara,ara+n);
        memset(dp,-1,sizeof(dp));
        int ans=go(0,0);
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
