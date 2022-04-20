#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int p1,p2;
};
char str[505][505];
int n,m,q,t,cnt=0,dp[1059],ok;
int seen[505][505];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void dfs(int x,int y)
{
    if(seen[x][y]!=0)return;seen[x][y]=ok;
    if(str[x][y]=='C')cnt++;
    for(int i=0;i<4;i++)
    {
        int fx=x+dx[i];
        int fy=y+dy[i];
        if(fx>=0 && fy>=0 && fx<n && fy<m && seen[fx][fy]==0){
            if(str[fx][fy]!='#')dfs(fx,fy);
        }
    }

}
int main()
{
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d %d",&n,&m,&q);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)scanf(" %c",&str[i][j]);
            printf("Case %d:\n",a);
        memset(seen,0,sizeof(seen));ok=1;
        while(q--)
        {
            int x,y;scanf("%d %d",&x,&y);x--;y--;
            if(seen[x][y]!=0){
                printf("%d\n",dp[seen[x][y]]);
            }
            else{
              cnt=0;
            dfs(x,y);
            printf("%d\n",cnt);
            dp[ok]=cnt;
            ok++;
            }


        }
    }
    return 0;
}

