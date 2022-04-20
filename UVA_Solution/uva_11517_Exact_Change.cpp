#include <bits/stdc++.h>
using namespace std;
int dp[20002];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int total,n;scanf("%d %d",&total,&n);
        int ara[n+3];
       for(int i=0;i<=20000;i++)dp[i]=100000000;
        for(int i=1;i<=n;i++)scanf("%d",&ara[i]);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=20000;j>=1;j--){
                if(j>=ara[i])
                dp[j]=min(dp[j],dp[j-ara[i]]+1);
            }
        }
        int take;
        for(int i=total;i<=20000;i++){
            if(dp[i]!=100000000){
                take=i;break;
            }
        }
        printf("%d %d\n",take,dp[take]);
    }
    return 0;
}
