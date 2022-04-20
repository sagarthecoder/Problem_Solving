#include <bits/stdc++.h>
using namespace std;
int ara[]={1,5,10,25,50};
int dp[8500][10];
int coin(int n,int i,int start)
{
    int p,q;
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
        printf("%d\n",coin(5,0,n));
        //cout<<"cnt = "<<cnt<<endl;
    }
    return 0;
}
