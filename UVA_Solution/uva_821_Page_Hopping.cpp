#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

    int a=1;
    while(true)
    {
        int x,y,maxi=0;
        int dis[101][101];
        for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++){
            if(i==j)dis[i][j]=0;
            else
            dis[i][j]=1000000000;
        }

        scanf("%d %d",&x,&y);

        if(x==0 && y==0)break;
        maxi=max(maxi,max(x,y));
        dis[x][y]=1;
        int seen[101];memset(seen,0,sizeof(seen));
        int ans=0,cnt=0;
        while(true)
        {
            scanf("%d %d",&x,&y);
            if(x==0 && y==0)break;
            maxi=max(maxi,max(x,y));
            dis[x][y]=1;
        }
        for(int i=1;i<=maxi;i++)
        {
            for(int j=1;j<=maxi;j++){
                for(int k=1;k<=maxi;k++)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
        for(int i=1;i<=maxi;i++)
        {
            for(int j=1;j<=maxi;j++)
            {
                ///cout<<i<<" "<<j<<" = "<<dis[i][j]<<endl;
                if(dis[i][j]!=0 && dis[i][j]!=1000000000){
                    ans+=dis[i][j];
                    if(dis[i][j]!=0 && seen[j]==0){
                        cnt++;seen[j]=1;
                    }
                }
            }
        }
        cnt=cnt*(cnt-1);
       /// cout<<"ans = "<<ans<<endl;
        double bhag=(double)ans/(double)cnt;
        printf("Case %d: average length between pages = %.3f clicks\n",a,bhag);
        a++;

    }
    return 0;
}
