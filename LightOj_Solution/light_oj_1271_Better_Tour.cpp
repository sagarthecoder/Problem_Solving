
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dis[50002];
bool seen[50003];
vector<int>rev[50003];
void dfs(int x)
{
    if(seen[x])return;seen[x]=1;
    for(int i=0;i<rev[x].size();i++)dfs(rev[x][i]);
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y,shuru,shes;scanf("%d",&n);
        vector<int>v[50002];
        for(int i=0;i<=50001;i++){
            rev[i].clear();seen[i]=0;dis[i]=0;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(i==0){
                shuru=x;
                y=x;
                continue;
            }
            v[x].push_back(y);
            v[y].push_back(x);
            y=x;
        }
        shes=y;
        printf("Case %d:\n",a);
        if(shuru==shes){
            printf("%d\n",shuru);continue;
        }
        queue<int>q;q.push(shuru);
        bool ck=false;
        int mini2=100000000;
        while(!q.empty())
        {
            int top=q.front();
            if(dis[top]==mini2)break;
            for(int i=0;i<v[top].size();i++)
            {
                int asus=v[top][i];
                if(dis[asus]==0 && asus!=shuru){
                    dis[asus]=dis[top]+1;
                    rev[asus].push_back(top);
                    //cout<<"asus = "<<asus<<endl;
                    q.push(asus);
                    if(asus==shes)mini2=dis[asus];
                }
                else if(dis[asus]==dis[top]+1 && dis[asus]<=mini2){
                    rev[asus].push_back(top);
                }
            }
            q.pop();
        }
        dfs(shes);
        vector<int>sagar;
        sagar.push_back(shuru);int cnt=0,take=shuru;
        while(true)
        {
            int mini=10000000;
            for(int i=0;i<v[take].size();i++){
                int asus=v[take][i];
                if(cnt+1==dis[shes]){
                    mini=shes;break;
                }
                if(seen[asus]==1 && dis[asus]==cnt+1 && mini>asus){
                  mini=asus;
                }
            }
            cnt++;
            sagar.push_back(mini);
            take=mini;
            if(mini==shes)break;
        }
        for(int i=0;i<=dis[shes];i++){
            if(ck==true)printf(" ");ck=true;
            printf("%d",sagar[i]);
        }
        printf("\n");

    }
    return 0;
}
