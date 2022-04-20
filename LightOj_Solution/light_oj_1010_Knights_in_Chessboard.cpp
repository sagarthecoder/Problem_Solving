#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,m;scanf("%d %d",&n,&m);
        int mini=min(n,m);
        int maxi=max(n,m);
        n=mini,m=maxi;
        if(mini==1)printf("Case %d: %d\n",a,maxi);
        else if(n<3 && m<3)printf("Case %d: %d\n",a,maxi*mini);
        else if(mini==2){

                int ara[n+4][m+4],ans=0;
                memset(ara,0,sizeof(ara));
                for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                {

                    if(ara[i][j]==0){

                       /// cout<<"one"<<endl;
                        if(j+2<=m)ara[i+1][j+2]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        if(j-2>=1)ara[i+1][j-2]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        ara[i][j]=1;
                        ans++;
                        ///cout<<"i & j = "<<i<<" ,  "<<j<<endl;
                    }
                    if(ara[i][j+1]==0 && j+1<=m){

                       /// cout<<"two"<<endl;
                        if(j+3<=m)ara[i+1][j+3]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        if(j-3>=1)ara[i+1][j-3]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        ara[i][j+1]=1;

                        ans++;
                    }
                    if(ara[i+1][j]==0 && i+1<=n){

                        ///cout<<"three"<<endl;
                        if(j+2<=m)ara[i][j+2]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        if(j-2>=1)ara[i][j-2]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        ara[i+1][j]=1;
                        ///cout<<"i & j = "<<i<<" ,  "<<j<<endl;
                        ans++;
                    }
                    if(ara[i+1][j+1]==0 && i+1<=n && j+1<=m){

                       ///cout<<"four"<<endl;
                        if(j+3<=m)ara[i][j+3]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        if(j-3>=1)ara[i][j-3]=1;//cout<<"i & j = "<<i<<" ,  "<<j<<endl;;
                        //cout<<"i & j = "<<i<<" ,  "<<j<<endl;
                        ans++;
                        ara[i+1][j+1]=1;
                    }
                    ///cout<<endl;
                }
                printf("Case %d: %d\n",a,ans);

        }

        else
        {
            int colEven=m/2;
            int  colOdd=m-colEven;
             int k1=colEven;

             int rowEven=n/2;
             int RowOdd=(n-rowEven);
             int ans=(rowEven*colEven)+(RowOdd*colOdd);
             printf("Case %d: %d\n",a,ans);
        }
    }
    return 0;
}
