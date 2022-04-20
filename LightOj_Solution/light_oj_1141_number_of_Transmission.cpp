#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[10002];
int sz=0;
int m,n;
int dis[1002];
int bfs()
{
    queue<int>q;
    q.push(m);dis[m]=0;
    while(!q.empty())
    {
        int t=q.front();
        for(int i=0;i<v[t].size();i++)
        {
            int asus=t+v[t][i];
            if(asus>n)break;
            if(asus<=n && asus!=m)
            {
                if(dis[asus]==0){
                    dis[asus]=dis[t]+1;
                    if(asus==n)return dis[asus];
                    q.push(asus);
                }
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int t;scanf("%d",&t);
    for(int i=2;i<=1000;i++)
    {
        int take=i;
        for(int j=2;j*j<=take;j++)
        {
            if(take%j==0){
                while(take%j==0)take=take/j;
                v[i].push_back(j);
            }
        }
        if(take>1 && take!=i)v[i].push_back(take);

    }


    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&m,&n);int take=m;
        memset(dis,0,sizeof(dis));
        printf("Case %d: ",a);
        if(m==n){
            printf("0\n");continue;
        }
        else if(m>n)printf("-1\n");
        else
        {
            printf("%d\n",bfs());
        }
    }
    return 0;
}
