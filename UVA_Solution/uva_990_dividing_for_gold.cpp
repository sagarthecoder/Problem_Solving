#include <bits/stdc++.h>
using namespace std;
struct data
{
    int len,gold;
}ara[1005];
int dp[1003][1003],direction[1003][1003];
int main()
{
    int t,w;
    bool ck=false;
    while(scanf("%d %d",&t,&w)!=EOF)
    {
        if(ck==true)printf("\n");
        ck=true;
        int n,vx,gx;scanf("%d",&n);
        memset(direction,-1,sizeof(direction));
        w=w+w+w;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&vx,&gx);
            ara[i].len=vx*(w);
            ara[i].gold=gx;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=t;j++)
            {
                if(i==0 || j==0)dp[i][j]=0;
                else if(ara[i].len<=j){dp[i][j]=max(dp[i-1][j],dp[i-1][j-ara[i].len]+ara[i].gold);
                ///if(dp[i][j]==dp[i-1][j-ara[i].len]+ara[i].gold)direction[i][j]=1;
                ///if(dp[i][j]==dp[i-1][j])direction[i][j]=2;
                ///else direction[i][j]=1;
                }
                else dp[i][j]=dp[i-1][j];

            }

        }
        int ans=dp[n][t];
        ///cout<<"ans = "<<ans<<endl;
        int i=n,j=t;
        vector<int>omg;
        while(true){
            if(i==0 || j==0)break;
            if(dp[i][j]!=dp[i-1][j]){
                omg.push_back(i);
                j=j-ara[i].len;
                i--;
            }
            else i--;
        }
        printf("%d\n",ans);
        int sz=omg.size();
        printf("%d\n",sz);
        for(int i=sz-1;i>=0;i--){
            printf("%d %d\n",(ara[omg[i]].len)/w,ara[omg[i]].gold);
        }
    }
    return 0;
}
