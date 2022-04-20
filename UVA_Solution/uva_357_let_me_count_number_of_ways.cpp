#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ara[]={1,5,10,25,50};
ll dp[30500][10];
ll coin(int n,int i,int start)
{
    ll p,q;
    if(i==n)return 0;
    if(dp[start][i]!=-1)return dp[start][i];
    if(start==0)return 1;
    //cout<<"ok= "<<endl;
    if(start-ara[i]>=0){
        p=coin(n,i,start-ara[i]);
    }
    else p=0;
    q=coin(n,i+1,start);
    //s=coin(taka,n,i+1,start);
    //cout<<p+q<<endl;
    return dp[start][i]=p+q;
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)!=EOF)
    {
//        memset(dp,-1,sizeof(dp));
        //cnt=0;
        ll res=coin(5,0,n);
        //cout<<"res= "<<res<<endl;
        if(res==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",res,n);
        ///printf("%lld\n",coin(5,0,n));
        //cout<<"cnt = "<<cnt<<endl;
    }
    return 0;
}

