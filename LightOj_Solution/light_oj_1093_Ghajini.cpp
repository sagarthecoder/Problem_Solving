#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[100005];
int bap[100005][17];
int bap2[100005][17];
void sparse(int n)
{
    for(int i=0;i<n;i++)bap[i][0]=ara[i],bap2[i][0]=ara[i];
    int log=ceil((double)log2(n)*1.0);
    for(int i=1;i<=log;i++){
        for(int j=0;(j+(1<<i))<=n;j++){
            bap[j][i]=max(bap[j][i-1],bap[j+(1<<(i-1))][i-1]);
            bap2[j][i]=min(bap2[j][i-1],bap2[j+(1<<(i-1))][i-1]);
           /// cout<<"mx1 = "<<bap[j][i]<<endl;

        }
    }
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,d;scanf("%d %d",&n,&d);
        ///memset(bap,0,sizeof(bap));
        ///memset(bap2,0,sizeof(bap2));
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        sparse(n);
        int maxi=0;

        for(int i=0;i+d<=n;i++){
            int L1=i,R1=i+d-1;
            ///cout<<"L1 = "<<L1<<",  R1 = "<<R1<<endl;
            int log=log2(R1-L1+1);
            int mn=min(bap2[L1][log],bap2[R1-(1<<log)+1][log]);
            int mx=max(bap[L1][log],bap[R1-(1<<log)+1][log]);
            ///cout<<"mx = "<<mx<<endl;
           /// cout<<"mn = "<<mn<<endl<<endl;
            maxi=max(maxi,mx-mn);
        }
        printf("Case %d: %d\n",a,maxi);

    }
    return 0;
}
