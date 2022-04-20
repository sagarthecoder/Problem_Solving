#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool status[2000005];
ll prime[2000005];
ll p=0;
ll ara[2000009],sum[2000009];
void siv()
{

    status[1]=1;
    status[0]=1;
    ll M=2000000;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(int j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
ll euler(ll n)
{

    if(n==1)return 1;
    if(status[n]==0)return n-1;
    ll cnt=n;
    for(ll i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)n=n/prime[i];
            cnt=cnt-(cnt/prime[i]);
        }
    }
    if(n>1)cnt=cnt-(cnt/n);
    return cnt;
}
int main()
{
    siv();
    ara[1]=1,ara[2]=1,sum[1]=0,sum[2]=1;
    for(ll i=3;i<=2000000;i++)
    {
        ara[i]=ara[euler(i)]+1;
        ///cout<<"i = "<<i<<" = "<<ara[i]<<endl;
        sum[i]=sum[i-1]+ara[i];
        ///cout<<"sum = "<<sum[i]<<endl;
    }
   /// cout<<"sum 10 "<<sum[1]<<endl;
    ll t;scanf("%lld",&t);
    while(t--)
    {
        ll n,m;scanf("%lld %lld",&m,&n);
        ///cin>>m>>n;
        ///cout<<"sum = "<<sum[n]<<endl;
        ll ans=sum[n]-sum[m-1];
        printf("%lld\n",ans);
    }
    return 0;

}
