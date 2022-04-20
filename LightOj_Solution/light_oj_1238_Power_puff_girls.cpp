#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int p1,p2;
};
char str[25][25];
int seen[22][22];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int n,m,t,a1,a2,b1,b2,c1,c2,h1,h2;
int maxi=0;
void bfs(int x1,int y1)
{
    queue<data>q;
    if(x1==h1 && y1==h2)return;
    q.push({x1,y1});bool ck=false;
    while(!q.empty())
    {
        data top=q.front();
        for(int i=0;i<4;i++)
        {
            int fx=top.p1+dx[i];
            int fy=top.p2+dy[i];
            if(seen[fx][fy]==0 && fx>=0 && fy>=0 && fx<n && fy<m && (fx!=x1 || fy!=y1))
            {
                if(str[fx][fy]!='#' && str[fx][fy]!='m'){
                    seen[fx][fy]=seen[top.p1][top.p2]+1;
                    if(fx==h1 && fy==h2){
                        maxi=max(maxi,seen[fx][fy]);ck=true;
                        break;
                    }
                    q.push({fx,fy});
                }
            }
        }
        if(ck){
           break;
        }
        q.pop();
    }
}
int main()
{
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&n,&m);
        maxi=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            scanf(" %c",&str[i][j]);
            if(str[i][j]=='a')a1=i,a2=j;
            else if(str[i][j]=='b')b1=i,b2=j;
            else if(str[i][j]=='c')c1=i,c2=j;
            else if(str[i][j]=='h')h1=i,h2=j;
        }
        memset(seen,0,sizeof(seen));
        bfs(a1,a2);
        memset(seen,0,sizeof(seen));
        bfs(b1,b2);
        memset(seen,0,sizeof(seen));
        bfs(c1,c2);
        printf("Case %d: %d\n",a,maxi);
    }
    return 0;
}

