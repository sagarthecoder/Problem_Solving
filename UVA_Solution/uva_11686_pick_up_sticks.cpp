#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[1000002];
vector<int>rev[1000002];
vector<int>ans;
stack<int>s;
bool seen[1000003];
int cnt=0;
void dfs(int x)
{
    if(seen[x])return;seen[x]=1;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
    s.push(x);
}
void dfs2(int x)
{
    if(!seen[x])return;seen[x]=0;
    cnt++;
    ans.push_back(x);
    for(int i=0;i<rev[x].size();i++)dfs2(rev[x][i]);
}
int main()
{

    int n,m;
    while(true)
    {
        scanf("%d %d",&n,&m);if(!n && !m)break;
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            rev[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(seen[i]==0)dfs(i);
        }
        bool ck=false;
        while(!s.empty())
        {
            int t=s.top();cnt=0;
            if(seen[t]==1 && !ck){
                dfs2(t);
                if(cnt>1){
                    ck=true;
                }
            }
            s.pop();
        }
        if(ck)printf("IMPOSSIBLE\n");
        else{
            for(int i=0;i<n;i++)printf("%d\n",ans[i]);
        }
        ans.clear();
        for(int i=1;i<=n;i++){
            seen[i]=0;rev[i].clear();v[i].clear();
        }

    }
    return 0;
}
