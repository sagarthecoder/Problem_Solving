#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    int x,y,k;
};
char str[14][14];
int n,m,dis[14][14][14],seen[14][14],res[14][14];
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
void bfs(int x,int y,int k)
{
    queue<data>q;
    ///cout<<"XX = "<<x<<" YY = "<<y<<" KK = "<<k<<endl;
   for(int i=0;i<14;i++)
   {
       for(int j=0;j<14;j++)
       {
           for(int j1=0;j1<14;j1++)dis[i][j][j1]=10000000;
       }
   }
    dis[x][y][k+1]=1;
    q.push({x,y,k+1});
    ///memset(dis,)
    while(!q.empty())
    {
        data f=q.front();
        int x1=f.x,y1=f.y,k1=f.k;
        int bad=k1-1;
        if(bad==0)bad=k;
        for(int i=0;i<8;i++)
        {
            int fx=x1+dx[i],fy=y1+dy[i];
            ///cout<<"ok "<<endl;
            if(fx>=0 && fy>=0 && fx<n && fy<m && (fx!=x || fy!=y))
            {
               /// cout<<"go = "<<endl;
                int asus=dis[x1][y1][k1];
                if(k1==1)asus++;
                if(asus<dis[fx][fy][bad]){dis[fx][fy][bad]=asus;
                q.push({fx,fy,bad});
               /// cout<<"fx  = "<<fx<<" fy  = "<<fy<<" dis = "<<asus<<endl;
                }
            }
        }
        q.pop();



    }
    dis[x][y][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int mx=10000000;
            for(int ok=0;ok<=10;ok++)
            {
                if(dis[i][j][ok]<mx){
                    mx=dis[i][j][ok];
                }
            }
            if(mx!=10000000){res[i][j]+=mx;
            seen[i][j]++;
            }
        }
    }
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&n,&m);memset(res,0,sizeof(res));memset(seen,0,sizeof(seen));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)scanf(" %c",&str[i][j]);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='.')continue;
                int val=str[i][j]-'0';cnt++;
                bfs(i,j,val);

            }
        }
        int ans=10000000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(seen[i][j]==cnt)ans=min(ans,res[i][j]);
            }
        }
        printf("Case %d: ",a);
        if(ans==10000000)printf("-1\n");
        else printf("%d\n",ans);
    }
}
