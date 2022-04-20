#include <bits/stdc++.h>
#define ll long long
using namespace std;
int d[13];
int dp[10004];
ll go(int n)
{
    if(n<10)return d[n];
    if(dp[n]!=0)return dp[n];
    if(((n/10)%10)%2==0)
    return dp[n]=(6*go(n/5)*d[(n%10)])%10;
    return dp[n]=(4*go(n/5)*d[(n%10)])%10;
}
int main()
{
    int n;
    d[0]=1,d[1]=1,d[2]=2,d[3]=6,d[4]=4,d[5]=2,d[6]=2,d[7]=4,d[8]=2,d[9]=8;
    while(cin>>n)
    {
        ll ans=go(n);
        int m=n;
        if(n==0)n=1;
        ///cout<<"ans = "<<ans<<endl;
        int sz=log10(n)+1;
        for(int i=1;i<=5-sz;i++)cout<<" ";
        cout<<m;
        cout<<" -> "<<ans<<endl;
    }
    return 0;
}
