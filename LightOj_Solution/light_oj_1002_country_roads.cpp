#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define ll long long
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;
struct data
{
   int v1,v2,w;
};
struct node
{
    int n1,taka;
};
int cost[20001],maxi=0;
bool seen[501];
vector<data>v;
int weight[501][501];
int res[501];
vector<int>ok[501];
bool comp(data u,data u1)
{
    return u.w<u1.w;
}
int bapke(int x)
{
    if(cost[x]==x)return x;
    return cost[x]=bapke(cost[x]);
}
void dfs(int x)
{
     maxi=0;
    queue<node>q;
    node z;
    z.n1=x;
    z.taka=0;
    q.push(z);
    while(!q.empty())
    {
      node t=q.front();
      for(int i=0;i<ok[t.n1].size();i++)
      {
          if(seen[ok[t.n1][i]]==false && ok[t.n1][i]!=x ){
            seen[ok[t.n1][i]]=true;
            maxi=max(t.taka,weight[t.n1][ok[t.n1][i]]);
            ///cout<<" node = "<<ok[t.n1][i]<<endl;
            ///cout<<"weight = "<<weight[t.n1][ok[t.n1][i]]<<endl;
            res[ok[t.n1][i]]=maxi;
            z.n1=ok[t.n1][i];
            z.taka=maxi;
            q.push(z);
          }
      }
      q.pop();
    }
}
int main()
{
    int t,n,e,c,x,y,start;
    sf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        sf("%d %d",&n,&e);
        int cnt=0;
        maxi=0;
        for(int i=0;i<=n;i++)cost[i]=i;
        for(int i=0;i<e;i++){
            sf("%d %d %d",&x,&y,&c);
            data olala;
            olala.v1=x,olala.v2=y,olala.w=c;
            v.pb(olala);
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<e;i++){
           int A=bapke(v[i].v1);
           int B=bapke(v[i].v2);
           if(A!=B){
            cost[B]=A;
            cnt++;
            weight[v[i].v1][v[i].v2]=v[i].w;
            weight[v[i].v2][v[i].v1]=v[i].w;
            ok[v[i].v1].pb(v[i].v2);
            ok[v[i].v2].pb(v[i].v1);
            if(cnt==n-1)break;

           }
        }
        sf("%d",&start);
        pf("Case %d:\n",a);
        dfs(start);
        for(int i=0;i<n;i++){
            if(i==start)pf("0\n");
            else if(res[i]==0)pf("Impossible\n");
            else
                pf("%d\n",res[i]);
            ok[i].clear();
            seen[i]=false;
            res[i]=0;
        }
        memset(weight,0,sizeof(weight));
        v.clear();
    }
    return 0;

}
