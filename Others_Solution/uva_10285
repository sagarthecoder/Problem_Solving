#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;int seen[102][102],ara[102][102],dis[102][102];
int dfs(int x,int y,int preX)
{
    if(x>=n || y>=m || x<0 || y<0)return 0;
    if(preX<=ara[x][y])return 0;
    if(seen[x][y])return dis[x][y];
    seen[x][y]=1;
    return dis[x][y]=1+max(max(dfs(x-1,y,ara[x][y]),dfs(x+1,y,ara[x][y])),max(dfs(x,y+1,ara[x][y]),dfs(x,y-1,ara[x][y])));

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        char x[100002];
        scanf("%s",x);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){scanf("%d",&ara[i][j]);
            dis[i][j]=0,seen[i][j]=0;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(seen[i][j]==0){
                    mx=max(mx,dfs(i,j,INT_MAX));
                }
            }
        }
        printf("%s: ",x);
        printf("%d\n",mx);


    }
    return 0;
}
