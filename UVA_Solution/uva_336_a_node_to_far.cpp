#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include<string.h>
using namespace std;
map<int,int>seen;
int res=0,ck;
void bfs(int u,int v,map<int,vector<int> >graph)
{
    queue<int>q;
    q.push(u);
    while(!q.empty()==true)
    {
        ck=1;
        int font=q.front();
        if(seen[font]>=v)
            break;
        for(int i=0; i<graph[font].size(); i++)
        {
            int asus=graph[font][i];
            if(seen[asus]==0 && asus!=u)
            {
                seen[asus]=seen[font]+1;
                q.push(asus);
                res=res+1;
            }
        }
        seen[u]=1;
        q.pop();
    }
}
int main()
{
    int n,i,j,x,y,nod,ttl,sum,ans,cas=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        sum=0;
        map<int,vector<int> >graph;
        map<int,int>only;
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            if(only[x]==0)
            {
                sum=sum+1;
                only[x]=1;
            }
            if(only[y]==0)
            {
                sum=sum+1;
                only[y]=1;
            }
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        while(1)
        {
            scanf("%d %d",&nod,&ttl);
            res=0,ck=0;
            if(nod==0 && ttl==0)
                break;
            if(only[nod]==0)
            {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cas,sum,nod,ttl);
                cas++;
            }
            else{
            bfs(nod,ttl,graph);
            if(ck==1)
                ans=sum-(res+1);
            else
                ans=sum-res;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cas,ans,nod,ttl);
            cas++;
            }
            seen.clear();

        }
        graph.clear();
        only.clear();
    }
    return 0;
}
