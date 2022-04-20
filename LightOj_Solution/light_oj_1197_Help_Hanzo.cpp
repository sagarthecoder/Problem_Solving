#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool status[100005];
ll prime[100005];
int p=0;
bool ara[100005];
void siv(ll M1)
{

    status[1]=1;
    status[0]=1;
    ll M=sqrt(M1);
    p=0;
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
int  segment_sieve(ll a,ll b)
{
    ll  sq=sqrt(b);
    for(ll i=0;i<p;i++)
    {
        if(prime[i]>sq)break;
        ll low=((a)/prime[i])*prime[i];
        if(a>low)low+=prime[i];
        if(low==prime[i])low+=prime[i];
        for(ll j=low;j<=b;j+=prime[i])ara[j-a]=true;
    }
    int cnt=0;
    for(ll i=a;i<=b;i++){
        if(ara[i-a]==false){cnt++;
        ///cout<<"prime = "<<i<<endl;
        }
    }
    return cnt;
}
int main()
{

    int t;scanf("%d",&t);
    for(int a1=1;a1<=t;a1++){
    ll a,b,cnt=0;scanf("%lld %lld",&a,&b);
    if(a<2)a=2;
    if(b<2)cnt=0;
    else{
    siv(b);
     cnt=segment_sieve(a,b);
    }
    printf("Case %d: %d\n",a1,cnt);
    memset(prime,0,sizeof(prime));
    memset(status,0,sizeof(status));
    memset(ara,0,sizeof(ara));
    }

    return 0;
}
