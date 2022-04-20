#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
struct data{
    int v,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};

vector<data>edges[105];
int cost[105];

void go(int n)
{
    priority_queue<data>Q;
    Q.push({n, 0});
    cost[n]=0;
    while(!Q.empty())
    {
        data t=Q.top();
        Q.pop();
        if(t.cost>cost[t.v])continue;
        for(int i=0;i<edges[t.v].size();i++){
            int x=edges[t.v][i].v;
            if(cost[x]>cost[t.v]+edges[t.v][i].cost){
               cost[x]=cost[t.v]+edges[t.v][i].cost;
               Q.push({x,cost[x]});
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,m,x,y,w;scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)cost[i]=100000000;
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            edges[x].push_back({y,w});
            edges[y].push_back({x,w});
        }
        go(1);
        if(cost[n]==100000000)printf("Case %d: Impossible\n",a);
        else printf("Case %d: %d\n",a,cost[n]);
        for(int i=0;i<=n;i++)edges[i].clear();
    }
    return 0;
}
