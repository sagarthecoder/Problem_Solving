#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int P,D,u,v;
vector<int>adj[499700];
int seen[1200];
void dfs(int x)
{
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
      int f=q.front();
      for(int i=0;i<adj[f].size();i++)
      {
          int fec=adj[f][i];
          if(seen[fec]==0)
          {
              seen[fec]=seen[f]+1;
              q.push(fec);
          }
      }
      q.pop();
    }
}
int main()
{
   int i,j,t;
   scanf("%d",&t);
   for(j=1;j<=t;j++){
   scanf("%d %d",&P,&D);
   for(i=0;i<D;i++)
   {
       scanf("%d %d",&u,&v);
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   dfs(0);
   adj[0].clear();
   for(i=1;i<P;i++)
   {
       printf("%d\n",seen[i]);
       adj[i].clear();
       seen[i]=0;
       seen[0]=0;
   }
   if(j!=t)
    printf("\n");
   }
   return 0;
}
