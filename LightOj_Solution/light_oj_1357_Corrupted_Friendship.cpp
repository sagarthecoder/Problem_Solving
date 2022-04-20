#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[100008];ll ans=0;
bool seen[100004];
int cnt=0,n;
int sz[100003];
void dfs(int x,int p)
{
    if(seen[x])return;seen[x]=1;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],x);
    if(p!=-1){
    sz[p]+=sz[x];
    }
}
void dfs2(int x)
{
    if(seen[x]==0)return;seen[x]=0;
    cnt++;
    ans+=(n-cnt-sz[x]+1);
   // cout<<"x ="<<x<<endl;
   // cout<<"ans = "<<(n-sz[x]+1-cnt)<<endl;
    for(int i=0;i<v[x].size();i++)dfs2(v[x][i]);

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int x,y;scanf("%d",&n);
        for(int i=1;i<=n;i++)sz[i]=1;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);

        }
        dfs(1,-1);
       // for(int i=1;i<=n;i++)cout<<"sz of  "<<i<<" = "<<sz[i]<<endl;
         ans=0;
         cnt=0;
         dfs2(1);
         printf("Case %d: %d %lld\n",a,n-1,ans);
       for(int i=0;i<=n;i++){
        v[i].clear();
       }
    }
    return 0;
    /*
    9
    1 2
    1 3
    1 4
    4 5
    5 9
    4 6
    6 7
    6 8
    */
}
