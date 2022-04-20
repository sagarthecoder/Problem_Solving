#include <bits/stdc++.h>
using namespace std;
vector<int>v[50005];
bool seen[50005];
int len[50005];
int dfs(int x)
{
    if(seen[x])return 0;
    seen[x]=1;
    int ok=0;
    for(int i=0;i<v[x].size();i++){
         ok+=(1+dfs(v[x][i]));
    }
    ////cout<<"xx = "<<x<<endl;
    seen[x]=0;
    return len[x]=ok;
    ///cout<<"len[x] = "<<len[x]<<endl;
    seen[x]=0;
    ///cout<<"x = "<<x<<endl;
    ///seen[x]=0;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y;scanf("%d",&n);
        memset(len,-1,sizeof(len));
        memset(seen,0,sizeof(seen));
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            ///len[i+1]=-1;
        }
        int maxi=INT_MIN,ans=1;
        for(int i=1;i<=n;i++)
        {
            if(len[i]==-1){
                int go=dfs(i);
                if(go>maxi){
                    ans=i;
                    maxi=go;
                    ///cout<<"len ="<<go<<", ind = "<<ans<<endl;
                    ///cout<<endl<<endl;
                }
            }
        }
        printf("Case %d: %d\n",a,ans);
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
    }
    return 0;
}
