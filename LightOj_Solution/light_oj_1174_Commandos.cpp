#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,r,x,y,shuru,shes;scanf("%d %d",&n,&r);
        vector<int>v[n+4];int seen[n+4],seen2[n+4];
        memset(seen,0,sizeof(seen));
        memset(seen2,0,sizeof(seen2));
        for(int i=0;i<r;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        scanf("%d %d",&shuru,&shes);
        queue<int>q;
        q.push(shuru);
        while(!q.empty())
        {
            int top=q.front();
            for(int i=0;i<v[top].size();i++)
            {
                int asus=v[top][i];
                if(seen[asus]==0 && asus!=shuru){
                    seen[asus]=seen[top]+1;
                    q.push(asus);
                }
            }
            q.pop();
        }
        q.push(shes);
        while(!q.empty())
        {
            int top=q.front();
            for(int i=0;i<v[top].size();i++)
            {
                int asus=v[top][i];
                if(seen2[asus]==0 && asus!=shes){
                    seen2[asus]=seen2[top]+1;
                    q.push(asus);
                }
            }
            q.pop();
        }
        int maxi=0;
        for(int i=0;i<n;i++)maxi=max(maxi,seen[i]+seen2[i]);
        printf("Case %d: %d\n",a,maxi);

    }
    return  0;
}
