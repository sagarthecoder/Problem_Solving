#include <bits/stdc++.h>
#define ll long  int
using namespace std;
struct data
{
    ll u,v,w;
};
int main()
{
    ll t,n;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        ll n,q,m,x,w,y;cin>>n;
        vector<data>v1;
        ll cost[n+1],d[n+1];
        for(int i=1;i<=n;i++){cin>>cost[i];
        d[i]=10000000000000;
        }
        d[1]=0;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v1.push_back({x,y,(cost[y]-cost[x])*(cost[y]-cost[x])*(cost[y]-cost[x])});
            ///cout<<"weight = "<<(cost[y]-cost[x])*(cost[y]-cost[x])*(cost[y]-cost[x])<<endl;
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            x=v1[j].u;
            y=v1[j].v,w=v1[j].w;
            if(d[y]>d[x]+w && d[x]!=10000000000000)d[y]=d[x]+w;
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
           x=v1[j].u;
            y=v1[j].v,w=v1[j].w;
            if(d[y]>d[x]+w && d[x]!=10000000000000){
              d[y]=d[x]+w;
              cost[y]=-1;
            }
        }
        cin>>q;
        cout<<"Case "<<a<<":"<<endl;
        for(int i=0;i<q;i++){
            cin>>x;
            if(d[x]<3 || d[x]==10000000000000 || cost[x]==-1)cout<<"?"<<endl;
            else cout<<d[x]<<endl;
        }

    }
    return 0;
}
