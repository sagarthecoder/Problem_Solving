#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool status[1000009];
ll prime[1000009];
ll p=0,mu[1000009],ans[1000009];
void siv()
{

    status[1]=1;
    status[0]=1;
    ll M=1000000;
     for(ll i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(ll j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
ll go(ll x)
{
    ll cnt=0;
    for(int i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0){
            ll ans=0;
            while(x%prime[i]==0){
                ans++;
                x=x/prime[i];
               /// cout<<"ok"<<endl;
                if(ans>1)return 0;
            }
            cnt++;
        }
    }
    if(x>1)cnt++;
    if(cnt%2==0)return 1;
    else return -1;
}
void sagar(ll x)
{
    for(int i=1;i<=x;i++)printf(" ");
}
int main()
{
    siv();
    mu[1]=1,ans[1]=1;
    for(ll i=2;i<=1000000;i++)
    {
       ll olala=go(i);
       mu[i]=olala;
       ans[i]=ans[i-1]+mu[i];
       ///cout<<"i = "<<i<<endl;
    }
    ll n;
    bool ck=false;
    while(true)
    {
        scanf("%lld",&n);
        if(n==0)break;
        printf("%8d%8d%8d\n",n,mu[n],ans[n]);
        ///if(ck==true)printf("\n");
        ///ck=true;
        ///cout<<n<<endl;
        //printf(" ");
        ///ll sp=log10(n)+1;
        ///sagar(8-sp);
        //printf("%lld",n);
        ///printf("      ");
       /// if(mu[n]>=0)printf(" ");
        ///printf("%lld",mu[n]);
        /////if(ans[n]==0)sp=1;
        ///else
        ///sp=log10(abs(ans[n]))+1;
        ///cout<<"sp = "<<sp<<endl;
        ///if(ans[n]<0)sp++;
        ///printf(" ");
        ///sagar(8-sp);
        ///printf("%lld",ans[n]);
    }
    return 0;
      /*20       9 1234568
      20       0      -3*/
}
