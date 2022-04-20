#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll power(ll a,ll n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ans=power(a,n/2);
    if(n%2==0)return ans*ans;
    else return ans*ans*a;

}
ll go(ll M,ll i,ll x)
{
    ll ans=(M*power(x,i));
    return ans;
}
int main()

{
    ll t;cin>>t;
    while(t--)
    {
        ll M,d,k;cin>>M;
        ll ara[M+2];
        for(ll i=0;i<=M;i++)cin>>ara[i];
        cin>>d>>k;
        long double sq=sqrt(d*d+(8*d*k));
        ///cout<<"sq = "<<sq<<endl;
         double x=(sqrt((d*d)+(8*d*k))-d)/(2*d*1.00);
        ll cel=ceil(x),ans=0;
        ///cout<<"cel = "<<cel<<endl;
        for(ll i=0;i<=M;i++)
        {
            if(ara[i]!=0)
            ans+=go(ara[i],i,cel);
           /// cout<<"ans = "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
