#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt;
ll pass(ll a,ll b,ll x,ll N)
{
    ///return ((((a%N)*(x%N)*(x%N)))+(b%N))%N;
    return ((((a%N)*((x*x)%N))%N) +(b%N))%N;
     ///return ((a*x*x)+b)%N;
}
ll final_ans(ll a,ll b,ll tort,ll N)
{
    ll take=tort;
    while(true)
    {
        ll huh=pass(a,b,tort,N);
       /// cout<<"final ="<<huh<<endl;
        if(huh==take)break;
        tort=huh;
        cnt++;
        /*
        ll huh=pass(Z,tort,I,M);
        if(huh==take)break;
        tort=huh;
        cnt++;
        */
    }
    return cnt;
}
ll go(ll a,ll b,ll x,ll N)
{
    ll hare1=x,tort1=x;
    while(true)
    {
        ll tort=pass(a,b,tort1,N);
        ll hare=pass(a,b,pass(a,b,hare1,N),N);
        ///cout<<"tort = "<<tort<<endl;
        ///cout<<"hare = "<<hare<<endl<<endl;
        if(tort==hare){
           ///cout<<"ha= "<<hare<<endl;
                final_ans(a,b,hare,N);
        break;
        }
        ///cout<<"ok =  "<<endl;
        tort1=tort,hare1=hare;
    }
    return cnt;
}
int main()
{
    ll N,a,b;
    while(true)
    {
        scanf("%lld",&N);
        cnt=1;
        if(N==0)break;
        scanf("%lld %lld",&a,&b);
        ll x=0;
        ///cout<<"ans = "<<pass(a,b,38,N)<<endl;;
       /// cout<<N-go(a,b,x,N)<<endl;
        printf("%lld\n",N-go(a,b,x,N));



    }
    return 0;
}
