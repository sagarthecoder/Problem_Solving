#include <bits/stdc++.h>
#define ll long long
using namespace std;
int par[100004];
vector<int>v[100003];
int dis[100003],L[100003];
int bap[100001][17];
bool seen[100003];
void dfs(int x,int level)
{
    if(seen[x])return;seen[x]=1;
    L[x]=level;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],level+1);
}
void LisCnt(int n)
{
    memset(bap,-1,sizeof(bap));

    for(int i=0;i<n;i++)bap[i][0]=par[i];

    for(int i=1;(1<<i)<n;i++)
        for(int j=0;j<n;j++)bap[j][i]=bap[bap[j][i-1]][i-1];

}
int go(int n,int x,int k)
{
    int p=x;

    int log=0;
    if(L[x]!=0)log=(log2(L[x]));
   /// cout<<"log = "<<log<<endl;
    for(int i=log;i>=0;i--)
    {
        if( (L[p]-(1<<i))>=0 )
        {
            if(dis[bap[p][i]]>=k){
                p=bap[p][i];
                ///cout<<"P= "<<ans<<endl;
               /// p=ans;
            }
        }
    }
    return p;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y,q;scanf("%d %d",&n,&q);
        memset(seen,0,sizeof(seen));
        dis[0]=1;
        par[0]=0;
        for(int i=1;i<=n-1;i++){
            scanf("%d %d",&x,&y);
            par[i]=x;
            v[x].push_back(i);
            dis[i]=y;
        }
        dfs(0,0);
        LisCnt(n);
        printf("Case %d:\n",a);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            int ans=go(n,x,y);
            printf("%d\n",ans);
        }
        for(int i=0;i<n;i++)v[i].clear();
    }
    return 0;
}
