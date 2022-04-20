#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define ll long long int
using namespace std;
///int dp[100][25002];
 ll dp[210][12][22];
///bool ck[202][12][22];
///unordered_map<int,unordered_map<int,int> >dp;
ll omg(ll d,ll cap)
{
   ll found;
   if(cap<0){
   ll bhag=(abs(cap)/d)+1;
     found=cap-(-bhag*d);
   }
   else found=cap%d;
    return found;
}
ll go(ll *ara,ll cap,ll n,ll m,ll i,ll j,ll d)
{
    ll p,q,k,rem;
    if(i==n+1)return 0;
    if(j==m){
        if(cap%d==0)return 1;
        else
            return 0;
    }

    if(cap<0)
         rem=omg(d,cap);
        else
             rem=cap%d;
    if(dp[i][j][rem]!=0)return dp[i][j][rem];
    p=go(ara,omg(d,rem+ara[i]),n,m,i+1,j+1,d);
    q=go(ara,cap,n,m,i+1,j,d);
    ///cout<<" p+q ="<<p+q<<endl;
    //ck[i][j][cap]=true;
    return dp[i][j][rem]=p+q;
}
int main()
{
    ll n,q,a=1;
    while(cin>>n>>q)
    {
        if(n==0 && q==0)break;
        cout<<"SET "<<a<<":"<<endl;
        ll ara[n+1],d,m;
        for(ll i=0;i<n;i++)cin>>ara[i];
        for(ll i=0;i<q;i++)
        {
            memset(dp,0,sizeof(dp));
           // memset(ck,false,sizeof(ck));
            cin>>d>>m;
            ll ans=go(ara,0,n,m,0,0,d);
            cout<<"QUERY "<<i+1<<": "<<ans<<endl;
        }
        a++;
    }
    return 0;
}
