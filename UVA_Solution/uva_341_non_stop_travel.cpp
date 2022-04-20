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
using namespace std;
struct data
{
    int v,cost;
    friend bool operator < (data a,data b)
    {
        return a.cost>b.cost;
    }
};
map<int,int>path;
vector<data>sagar[100];
vector<int>taken;
void dk(int s,int *cost)
{
    priority_queue<data>q;
    q.push({s,0});
    while(!q.empty())
    {
        data t=q.top();
        for(int i=0;i<sagar[t.v].size();i++)
        {
            int x=sagar[t.v][i].v;
            if(cost[x]>cost[t.v]+sagar[t.v][i].cost)
            {
                cost[x]=cost[t.v]+sagar[t.v][i].cost;
                path[x]=t.v;
                q.push({x,cost[x]});
            }
        }
        q.pop();
    }
}
void sPath(int z)
{
    if(path[z]==-1)return;
    sPath(path[z]);
    taken.push_back(z);

}
int main()
{
    int t,q,x,y,s,d,cas=1;
    while(1)
    {
        cin>>t;
        int cost[t+2];
        if(t==0)break;
        for(int i=0;i<=t;i++)cost[i]=1000000000;

        for(int i=1;i<=t;i++)
        {
            cin>>q;
            for(int j=1;j<=q;j++)
            {
                cin>>x>>y;
                sagar[i].push_back({x,y});
            }
        }
        cin>>s>>d;
        cost[s]=0;
        dk(s,cost);
        path[s]=-1;
        taken.push_back(s);
        sPath(d);
        cout<<"Case "<<cas<<": Path = ";
        for(int i=0;i<taken.size();i++)
        {
            cout<<taken[i];
            if(i!=taken.size()-1)cout<<" ";
            else
            {
                cout<<"; "<<cost[d]<<" second delay"<<endl;
            }
        }
        cas++;
        for(int i=0;i<=t;i++)sagar[i].clear();
        path.clear();
        taken.clear();
    }
    return 0;
}
