#include <bits/stdc++.h>
using namespace std;
struct data{
    int v,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};

vector<data>edges[100002];
int cost[123];

void djk(int n)
{
    priority_queue<data>Q;
    Q.push({n, 0});
    cost[n]=0;
    while(!Q.empty())
    {
        data t=Q.top();
        Q.pop();
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
    int t,n,k,m,x1,y,c,cnt,t1;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        ///vector<int>edges[100002];
        cnt=1;
        cin>>n>>k>>t1>>m;
        ///for(int i=0;i<=n;i++)cost[i]=1000000000;
        for(int i=0;i<m;i++){
            cin>>x1>>y>>c;
            edges[x1].push_back({y,c});
        }
        for(int i=1;i<=n;i++)
        {
            for(int u=0;u<=n;u++)cost[u]=1000000000;

            if(i!=k){
                djk(i);
                if(cost[k]<=t1)cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<=n;i++)edges[i].clear();
        if(a!=t)cout<<endl;
    }
    return 0;
}
