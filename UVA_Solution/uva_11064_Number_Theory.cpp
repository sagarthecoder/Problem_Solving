#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
        ll euler=n,nod=1,take=n;
        for(ll i=2;i*i<=n;i++)
        {
            ll cnt=0;
            if(n%i==0)
            {
                while(n%i==0)
                {
                    cnt++;
                    n=n/i;
                }
                nod*=(cnt+1);
                euler=euler-(euler/i);
            }
        }
        if(n>1){
            nod*=2;
            euler=euler-(euler/n);
        }
        ll ans=take-(nod+euler)+1;
        printf("%lld\n",ans);
    }
    return 0;
}
