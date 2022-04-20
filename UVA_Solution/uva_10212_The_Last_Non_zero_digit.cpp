#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        if(m==0)printf("1\n");
        else
        {
            ll ans=1;
            ll g=(n-m+1);
            for(ll i=n;i>=g;i--)
            {
                ans=(ans*i);
                while(ans%10==0){
                    ans=ans/10;
                }
                ans=ans%100000000000;
            }
            while(ans%10==0)ans=ans/10;
            ans=ans%10;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
