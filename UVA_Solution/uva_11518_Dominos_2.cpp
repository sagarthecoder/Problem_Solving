#include <bits/stdc++.h>
using namespace std;
vector<int>v[10008];
bool seen[10008];
int cnt=0;
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=1;
    cnt++;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,ans=0,x,y,L;scanf("%d %d %d",&n,&m,&L);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        for(int i=0;i<L;i++)
        {
            scanf("%d",&x);
            if(seen[x]==0){
                cnt=0;
                dfs(x);
                ans+=cnt;
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=n;i++){
            v[i].clear();
            seen[i]=0;
        }

    }
    return 0;
}
