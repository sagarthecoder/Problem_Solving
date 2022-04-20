#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long int  dp[35][35];
long long int go(long long int n,long long r)
{
    if(r==1)return n;
    if(r==n || r==0)return 1;
    if(dp[n][r]!=0)return dp[n][r];
    else
    return dp[n][r]=go(n-1,r-1)+go(n-1,r);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,k;scanf("%d %d",&n,&k);
        printf("Case %d: ",a);
        if(k>n)printf("0\n");
        else
        {
            ll ans=1;
            for(int j=n,i=1;i<=k;i++){
                ans*=j;
                j--;
            }
            ll bad=n-k;
            ans*=go(n,bad);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
