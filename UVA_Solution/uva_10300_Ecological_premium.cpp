#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)

    {
        ll n;scanf("%lld",&n);
        ll x,y,z,ans=0;
        while(n--){
            scanf("%lld %lld %lld",&x,&y,&z);
            ans+=(x*z);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
