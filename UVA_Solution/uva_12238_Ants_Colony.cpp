#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int node,cost;
};
vector<data>v[100003];
bool seen[100004];
int L[100004],par[100003];
int bap[100001][17];
ll dis[100003];
void dfs(int x,int p,int level,ll taka)
{
    if(seen[x])return;seen[x]=1;
    dis[x]=taka;
    par[x]=p;
    L[x]=level;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i].node,x,level+1,taka+v[x][i].cost);
}
void LCAcount(int n)
{
    memset(bap,-1,sizeof(bap));
    for(int i=0;i<n;i++)bap[i][0]=par[i];

    for(int i=1;(1<<i)<n;i++)
        for(int j=0;j<n;j++)bap[j][i]=bap[bap[j][i-1]][i-1];
}
int go(int n,int p,int q)
{
    int log;
    if(L[p]<L[q])swap(p,q);
    if(L[p]==0)log=0;
    else
    log=log2(L[p]);
    for(int i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])p=bap[p][i];
    }
    if(p==q)return p;
    for(int i=log;i>=0;i--)
    {
        if(bap[p][i]!=-1 && bap[p][i]!=bap[q][i])p=bap[p][i],q=bap[q][i];
    }
    return par[p];
}
int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(!n)break;
        int x,y;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&x,&y);
            v[i+1].push_back({x,y});
            v[x].push_back({i+1,y});
        }
        dfs(0,0,0,0);
        LCAcount(n);
        int q;scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&x,&y);
            if(i>1)printf(" ");
            int ans=go(n,x,y);
            ll res=(dis[x]+dis[y])-(2*dis[ans]);
            printf("%lld",res);

        }
        printf("\n");
        for(int i=0;i<=n;i++)v[i].clear();
        memset(seen,0,sizeof(seen));
    }
    return 0;
}
