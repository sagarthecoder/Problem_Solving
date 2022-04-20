#include <bits/stdc++.h>
#define ll  long long
using namespace std;
ll mod=1000000007;
ll  bigmod ( ll a, ll p, ll m )
{
    //ok++;
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p &1) // If power is odd
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
       ll tmp = bigmod ( a, p / 2, m );
        return ( tmp * tmp ) % m;
    }
}

ll inverse(ll a,ll m)
{

        return bigmod(a,mod-2,mod);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {

        ll n,m,ans=1;
        scanf("%lld %lld",&n,&m);
        printf("Case %d: ",a);
        if(m==0)
            printf("1\n");
        else
        {
            for(ll i=2; i*i<=n; i++)
            {

                if(n%i==0)
                {
                    ll cnt=0;
                    while(n%i==0)
                    {
                        cnt++;
                        n=n/i;
                    }
                    cnt=cnt*m;
                    ll p=bigmod(i,cnt+1,mod)-1;
                    ll inv=inverse(i-1,mod);
                    ll res=(((p+mod)%mod)*((inv+mod)%mod))%mod;
                    ans=((ans%mod)*(res%mod))%mod;
                }

            }
            if(n>1){
                ll p=bigmod(n,m+1,mod)-1;
                    ll inv=inverse(n-1,mod);
                    ll res=(((p+mod)%mod)*((inv+mod)%mod))%mod;
                    ans=((ans%mod)*(res%mod))%mod;
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
