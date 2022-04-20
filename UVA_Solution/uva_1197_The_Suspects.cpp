#include <bits/stdc++.h>
using namespace std;
bool seen[30004];
vector<int>v[30004];
int res;
void dfs(int x)
{
    if(seen[x])return;
    seen[x]=1;
    res++;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
}
int main()
{
    int n,e;
    while(true)
    {
        cin>>n>>e;
        if(n==0 && e==0)break;
        for(int i=0;i<e;i++)
        {
            int m,x,prev;cin>>m;
            for(int j=0;j<m;j++){
                cin>>x;
                if(j!=0){
                    v[prev].push_back(x);
                    v[x].push_back(prev);
                }
                prev=x;
            }
        }
        res=0;
        dfs(0);
        cout<<res<<endl;
        for(int i=0;i<=n;i++){v[i].clear();
        seen[i]=0;
        }

    }
    return 0;
}
