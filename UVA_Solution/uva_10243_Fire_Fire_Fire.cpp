#include <bits/stdc++.h>
using namespace std;
vector<int>v[1003];
int dp[1002][2],par[1002];
int dfs(int x,int ck)
{
    ////if(v[x].size()==0)return 0;
    if(dp[x][ck]!=-1)return dp[x][ck];
    int sum=0;
    ///seen[x]=1;
    for(int i=0;i<v[x].size();i++){
        int p=v[x][i];
        if(p!=par[x]){
            par[p]=x;
            if(ck==0)sum+=dfs(p,1);
            else sum+=min(dfs(p,1),dfs(p,0));
        }
    }
    return dp[x][ck]=sum+ck;
}
int main()
{
    while(true)
    {
        int n,x,y;scanf("%d",&n);
        if(!n)break;
        for(int i=1;i<=n;i++){
            int m;scanf("%d",&m);
            memset(dp,-1,sizeof(dp));
            memset(par,0,sizeof(par));
           /// memset(seen,0,sizeof(seen));
            for(int j=1;j<=m;j++){
                scanf("%d",&x);v[i].push_back(x);
                ///v[x].push_back(i);
            }
        }
        int ans=0;
       /// for(int i=1;i<=n;i++){
        /// if(seen[i]==0)
         ans=min(dfs(1,0),dfs(1,1));
        ///}
        printf("%d\n",max(1,ans));
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}
