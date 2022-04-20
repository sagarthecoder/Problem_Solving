#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,y,cost;
};
struct data2
{
    int node,cost;
};
vector<data2>v[50005];
const int Sz=50000+5;
int baba[50002];
bool comp(data u,data u1)
{
    return u.cost<u1.cost;
}
int dada(int x)
{
    if(baba[x]==x)return x;
    return  baba[x]=dada(baba[x]);
}

int L[Sz],maxi,parValue[Sz],mx[Sz][17],bap[Sz][17],par[Sz];
bool seen[Sz];
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
    memset(bap,-1,sizeof(bap));
    for(int i=1;i<=n;i++)mx[i][0]=parValue[i],bap[i][0]=par[i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++){
            if(bap[j][i-1]==-1)continue;
            bap[j][i]=bap[bap[j][i-1]][i-1];
            mx[j][i]=max(mx[j][i-1],mx[bap[j][i-1]][i-1]);
        }
}
int  go(int n,int p,int q)
{
    if(L[p]<L[q])swap(p,q);
    int log=log2(L[p]);
    for(int i=log;i>=0;i--){
        if((L[p]-(1<<i))>=L[q]){
            maxi=max(maxi,mx[p][i]);
            p=bap[p][i];
        }
    }
    if(p==q){


            return p;

    }
    for(int i=log;i>=0;i--)
    {
        if(bap[p][i]!=-1 && bap[p][i]!=bap[q][i]){
            maxi=max(maxi,mx[p][i]);
            maxi=max(maxi,mx[q][i]);
            p=bap[p][i],q=bap[q][i];
        }
    }
    maxi=max(maxi,mx[p][0]);
    maxi=max(maxi,mx[q][0]);
    return par[p];
}

int main()
{
  ///  freopen("input.txt","r",stdin);
   /// freopen("output.txt","w",stdout);
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,m,q;scanf("%d %d",&n,&m);
        vector<data>kruskal;
        for(int i=1;i<=n;i++)baba[i]=i;
        int x,y,c;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&c);
            kruskal.push_back({x,y,c});
        }
        sort(kruskal.begin(),kruskal.end(),comp);
        int cnt=0;
        for(int i=0;i<m;i++){
            int x1=dada(kruskal[i].x),x2=dada(kruskal[i].y);
            int c1=kruskal[i].cost;
            if(x1!=x2){
                cnt++;
                baba[x2]=x1;
               /// cout<<"x1 "<<x1<<" ,y1 = "<<x2<<" , cost = "<<c1<<endl;
                v[x1].push_back({x2,c1});
                v[x2].push_back({x1,c1});
            }
            if(cnt==n-1)break;

        }
        dfs(1,0,0,0);
        LisCnt(n);
        scanf("%d",&q);int  s,t2;
        printf("Case %d:\n",a);
        while(q--)
        {
            scanf("%d %d",&s,&t2);maxi=0;
             int ans=go(n,s,t2);
             printf("%d\n",maxi);

        }
        for(int i=0;i<=n;i++){
            v[i].clear();seen[i]=0;
        }
    }
    return 0;
}
