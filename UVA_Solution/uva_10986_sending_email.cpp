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
#define inf 0x3f3f3f3f3f3f3f
#define ll long long
using namespace std;
struct data{
    ll node,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};
vector<data>v[20006];
void dks(ll s,ll *costi)
{
    priority_queue<data>q;
    q.push({s,0});
    while(!q.empty())
    {
        data t=q.top();
        for(ll i=0;i<v[t.node].size();i++)
        {
            ll asus=v[t.node][i].cost;
            ll node2=v[t.node][i].node;
            if(costi[node2]>costi[t.node]+asus)
            {
                costi[node2]=costi[t.node]+asus;
                q.push({node2,costi[node2]});
            }
        }
        q.pop();
    }
}

int main()
{
    ll t,n,w,m,s,x,y,cost;
    cin>>w;
    for(ll j=1;j<=w;j++)
    {
        ll costi[20006];
        cin>>n>>m>>s>>t;
        for(int i=0;i<=n;i++)costi[i]=inf;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>cost;
            v[x].push_back({y,cost});
            v[y].push_back({x,cost});
        }
        costi[s]=0;
        dks(s,costi);
        if(costi[t]==inf)
        {
            cout<<"Case #"<<j<<": "<<"unreachable"<<endl;
        }
        else
            cout<<"Case #"<<j<<": "<<costi[t]<<endl;

        for(ll i=0;i<n;i++)v[i].clear();

    }
    return 0;
}
