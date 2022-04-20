#include <bits/stdc++.h>
using namespace std;
int seen[1002];
vector<int>v[1001];
int cnt[1002];
void dfs(int x)
{
    if(seen[x])return;seen[x]=1;
    cnt[x]++;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int k,n,ans=0,m,x,y;scanf("%d %d %d",&k,&n,&m);
        int ara[k+2];
        for(int i=0;i<k;i++)scanf("%d",&ara[i]);
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
        }
        for(int i=0;i<k;i++)
        {
            dfs(ara[i]);
            memset(seen,0,sizeof(seen));
        }
        for(int i=1;i<=n;i++)if(cnt[i]==k)ans++;
        printf("Case %d: %d\n",a,ans);
        for(int i=1;i<=n;i++)v[i].clear(),cnt[i]=0;
    }
    return 0;
}
