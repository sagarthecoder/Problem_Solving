#include <bits/stdc++.h>
using namespace std;
struct data
{
    int n1,n2;
};
vector<data>v[30002];
int maxi=0,node;
bool seen[30002];
void dfs(int x,int taka)
{
   if(seen[x])return;
   if(maxi<taka){
    maxi=taka;
    node=x;
   }
   seen[x]=true;
   for(int i=0;i<v[x].size();i++)dfs(v[x][i].n1,taka+v[x][i].n2);
}
int main()
{
    int t,x,y,n,w;
    cin>>t;
    for(int a=1;a<=t;a++){
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>x>>y>>w;
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        maxi=0;
        dfs(0,0);
        maxi=0;
        memset(seen,0,sizeof(seen));
        dfs(node,0);
        cout<<"Case "<<a<<": "<<maxi<<endl;
        for(int i=0;i<=n;i++){v[i].clear();
        seen[i]=0;
        }
    }
    return 0;
}
