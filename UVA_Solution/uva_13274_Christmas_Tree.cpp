#include <bits/stdc++.h>
using namespace std;

int par[1003],seen[1003],k;
vector<int>v[1003];
vector<int>v2[1003];
int ans[1003];
void dfs(int x,int p)
{
    if(seen[x])return;
    v2[p].push_back(x);
    seen[x]=1;par[p]++;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],x);
    ///cout<<"x = "<<x<<endl;

}
void dfs2(int x)
{
    if(seen[x])return;
    seen[x]=1;
    for(int i=0;i<v2[x].size();i++)dfs2(v2[x][i]);
    if(par[x]<k){ans[x]=1;
    ///cout<<"chuto = "<<x<<" = "<<ans[x]<<endl;
    }
    else{
        priority_queue<int>q;
        for(int j=0;j<v2[x].size();j++){
         ///cout<<" connec = "<<v2[x][j]<<endl;
        /// cout<<"ans of conec = "<<ans[v2[x][j]]<<endl;
         q.push(ans[v2[x][j]]);
        }
        int L=0;
        ///cout<<"in x   ="<<x<<endl;
        ///cout<<"size of  x = "<<v2[x].size()<<endl;
        while(!q.empty())
        {
            int t=q.top();
            ///cout<<"t = "<<t
            ///cout<<"top = "<<ans[t]<<endl;
            ans[x]+=t;
            ///cout<<"ans = "<<ans[x]<<endl;
            L++;
            if(L==k)break;
            q.pop();
        }
        ans[x]++;
    }
    ///cout<<"x = "<<x <<" = "<<ans[x]<<endl;

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y;scanf("%d %d",&n,&k);
        memset(par,0,sizeof(par));
        memset(seen,0,sizeof(seen));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0);
        ///for(int i=1;i<=n;i++)cout<<"par = "<<i<<", = "<<par[i]<<endl;
        memset(seen,0,sizeof(seen));
        dfs2(1);
        printf("Case %d: %d\n",a,ans[1]);
        for(int i=0;i<=n;i++){
            v[i].clear();
            v2[i].clear();
        }
    }
    return 0;
}
