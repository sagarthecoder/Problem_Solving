#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,w;
};
bool seen[30004];
int maxi=0,z,b1,a1;
vector<data>v[30004];
int dis1[30004],dis2[30004];
bool ck=1;
void dfs(int x,int cost)
{
    if(seen[x]==ck)return;seen[x]=ck;
    dis1[x]=cost;
    if(cost>maxi){
        maxi=cost;z=x;
        //cout<<"maxi = "<<maxi<<" node = "<<z<<endl;
    }
    for(int i=0;i<v[x].size();i++)dfs(v[x][i].x,cost+v[x][i].w);

}
void dfs2(int x,int cost)
{
    if(seen[x])return;seen[x]=1;
    dis2[x]=cost;
    for(int i=0;i<v[x].size();i++)dfs2(v[x][i].x,cost+v[x][i].w);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int x,y,n,w;scanf("%d",&n);
        ck=1,maxi=0;
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&x,&y,&w);
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        dfs(0,0);a1=z;ck=0,maxi=0;//cout<<"a1 = "<<z<<endl;
        dfs(a1,0);b1=z;
        dfs2(b1,0);
        printf("Case %d:\n",a);
        for(int i=0;i<n;i++){
            int ans=max(dis1[i],dis2[i]);
            printf("%d\n",ans);
            v[i].clear();
            seen[i]=0;
        }
    }
    return 0;
}
