#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
int ara[52],seen[56];
int dp[2001][52];


ll go(int n,int i,int start,int s)
{


     ll ans;
     ans=0;

    if(start==s)return 1;
    //if(i==n)return 0;
    if(dp[start][i]!=-1)
    {
        return dp[start][i];
    }
    if(i==n)return 0;
    /*if(start==s){
            return 1;
    }*/
    for(int j=0;j<=seen[i] && start+(j*ara[i])<=s;j++)
    {
        ans+=go(n,i+1,start+(j*ara[i]),s);
        ///cout<<"ans = "<<ans<<endl;
        ans=ans%mod;
    }
    return dp[start][i]=ans;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,k,x;scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=0;i<n;i++){
            scanf("%d",&seen[i]);
        }
        memset(dp,-1,sizeof(dp));

        printf("Case %d: %lld\n",a,go(n,0,0 ,k));
        ///cout<<"dp = "<<dp[0][0]<<endl;
    }
    return 0;
}
