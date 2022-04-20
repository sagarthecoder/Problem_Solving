#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=10000000000007;
int  main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll n,L,R;scanf("%lld %lld %lld",&n,&L,&R);
        ll ok=n*n;
        ll nilam=ok;
        ll ans=1;
        for(int i=1;i<=L;i++){
            ans=((ans)*(nilam))%mod;
            nilam--;
        }
        ll take=ans;
        for(int i=L+1;i<=R;i++)
        {
            ans=(ans*nilam)%mod;
            take=(take+ans)%mod;
            nilam--;
        }
        printf("Case %d: %lld\n",a,take);
    }
    return 0;
}
