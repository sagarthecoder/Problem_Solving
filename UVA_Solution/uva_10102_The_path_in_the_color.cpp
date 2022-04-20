#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,y;
};
int n;
char ara[10003][1003];
int seen[1003][1003];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int bfs(int x,int y)
{
    queue<data>q;
    q.push({x,y});
    while(!q.empty())
    {
        data top=q.front();
        for(int i=0;i<4;i++)
        {
            int fx=top.x+dx[i];
            int fy=top.y+dy[i];
            if(fx>=0 && fy>=0 && fx<n && fy<n && seen[fx][fy]==0 &&(fx!=x || fy!=y))
            {
                seen[fx][fy]=seen[top.x][top.y]+1;
                if(ara[fx][fy]=='3')return seen[fx][fy];
                q.push({fx,fy});
            }
        }
        q.pop();
    }

}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        vector<data>v;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf(" %c",&ara[i][j]);
            if(ara[i][j]=='1')v.push_back({i,j});
        }
        int maxi=0;
        int sz=v.size();
        for(int i=0;i<sz;i++){
            memset(seen,0,sizeof(seen));
            int ans=bfs(v[i].x,v[i].y);
            maxi=max(ans,maxi);
        }
        printf("%d\n",maxi);
    }
}
