#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int node,cost;
};
vector<data>v[100002];
int L[100002],maxi,mini,parValue[100002],mx[100001][17],mn[100001][17],bap[100001][17],par[100003];
bool seen[100002];
void dfs(int x,int p,int level,int value)
{
    if(seen[x])return;seen[x]=1;
    par[x]=p;
    L[x]=level;
    parValue[x]=value;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i].node,x,level+1,v[x][i].cost);

}
void LisCnt(int n)
{
    memset(mx,-1,sizeof(mx));
    memset(mn,-1,sizeof(mn));
    memset(bap,-1,sizeof(bap));
    for(int i=1;i<=n;i++)mx[i][0]=parValue[i],mn[i][0]=parValue[i],bap[i][0]=par[i];

    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++){
            bap[j][i]=bap[bap[j][i-1]][i-1];
            mx[j][i]=max(mx[j][i-1],mx[bap[j][i-1]][i-1]);
            mn[j][i]=min(mn[j][i-1],mn[bap[j][i-1]][i-1]);
        }
}
int  go(int n,int p,int q)
{
    ///cout<<"L of  "<<p<<" = "<<L[p]<<endl;
    ///cout<<"L of "<<q<<" = "<<L[q]<<endl;
    if(L[p]<L[q])swap(p,q);
    int log=log2(L[p]);
    for(int i=log;i>=0;i--){
        if((L[p]-(1<<i))>=L[q]){
            maxi=max(maxi,mx[p][i]);
            mini=min(mini,mn[p][i]);
            p=bap[p][i];
        }
    }
    if(p==q){


            return p;

    }
    ///cout<<"mx & mn = "<<maxi<<" , "<<mini<<endl;
    ///cout<<"PP= "<<p<< " , q = "<<q<<endl;;
    for(int i=log;i>=0;i--)
    {
        if(bap[p][i]!=-1 && bap[p][i]!=bap[q][i]){
            maxi=max(maxi,mx[p][i]);
            mini=min(mini,mn[p][i]);
            maxi=max(maxi,mx[q][i]);
            mini=min(mini,mn[q][i]);
            p=bap[p][i],q=bap[q][i];
        }
    }
    maxi=max(maxi,mx[p][0]);
    mini=min(mini,mn[p][0]);
    maxi=max(maxi,mx[q][0]);
    mini=min(mini,mn[q][0]);
    return par[p];
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,q,y,c;scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&x,&y,&c);
            v[x].push_back({y,c});
            v[y].push_back({x,c});
        }
        dfs(1,1,0,0);
        ///for(int i=1;i<=n;i++)cout<<"par value = "<<parValue[i]<<endl;

        LisCnt(n);
        scanf("%d",&q);
        printf("Case %d:\n",a);
        while(q--)
        {
            scanf("%d %d",&x,&y);
             maxi=INT_MIN,mini=INT_MAX;
            int ans=go(n,x,y);
            ///cout<<"ans = "<<ans<<endl;
            printf("%d %d\n",mini,maxi);
        }
        for(int i=0;i<=n;i++)v[i].clear();
        memset(seen,0,sizeof(seen));
    }
    return 0;
}
