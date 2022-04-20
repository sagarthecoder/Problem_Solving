#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int node,cost;
};

struct data2{
    int node,cost;
    friend bool operator < (data2 a,data2 b)
    {
        return a.cost>b.cost;
    }
};
vector<data>v[108];
int dp[108],y;
void go(int x)
{
    priority_queue<data2>q;
    q.push({x,0});
    while(!q.empty())
    {
        int vertex=q.top().node;
        int val=q.top().cost;
        q.pop();
        if(val>dp[vertex])continue;
        for(int i=0;i<v[vertex].size();i++)
        {
            int khoroc=max(v[vertex][i].cost,val);
            int node=v[vertex][i].node;
            if(dp[node]>khoroc)
            {
                dp[node]=khoroc;
                q.push({node,khoroc});
            }

        }

    }
}
int main()
{
    int n,m,q,x,c,a=1;
    while(true)
    {
        scanf("%d %d %d",&n,&m,&q);
        if(!n && !m && !q)break;
        if(a>1)printf("\n");
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            v[x].push_back({y,c});
            v[y].push_back({x,c});
        }
        printf("Case #%d\n",a);
        while(q--)
        {
            for(int i=0;i<=n;i++){dp[i]=1000000000;
            }
            scanf("%d %d",&x,&y);
            dp[x]=0;
            go(x);
            if(dp[y]==1000000000)printf("no path\n");
            else
            printf("%d\n",dp[y]);
        }

        for(int i=0;i<=n;i++)v[i].clear();
        a++;
    }
    return 0;
}
