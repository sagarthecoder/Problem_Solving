#include <bits/stdc++.h>
using namespace std;
int ara[220][103];
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;scanf("%d",&n);
        /*for(int i=0;i<(n*2);i++)
            for(int j=0;j<=101;j++)ara[i][j]=0;*/
            for(int i=0;i<=n;i++){
                ara[i][0]=0;
                ara[i][i+1]=0;
            }
            int m=(n*2)-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)cin>>ara[i][j];
        for(int i=n+1,k=1;i<=m;i++,k++){
            for(int j=1;j<=n-k;j++){cin>>ara[i][j];
            }
            }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){ara[i][j]=ara[i][j]+max(ara[i-1][j-1],ara[i-1][j]);
            ///cout<<"i ="<<i<<", j = "<<j<<endl;
            ///cout<<ara[i][j]<<endl<<endl;
            }
        }
       for(int i=n+1,k=1;i<=m;i++,k++)
        for(int j=1;j<=n-k;j++){ara[i][j]=ara[i][j]+max(ara[i-1][j],ara[i-1][j+1]);
        ///cout<<"i ="<<i<<", j = "<<j<<endl;
            ///cout<<ara[i][j]<<endl<<endl;
        }
       printf("Case %d: %d\n",a,ara[m][1]);


    }
    return 0;
}
