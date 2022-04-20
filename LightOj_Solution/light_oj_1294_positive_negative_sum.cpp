#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll n,m;scanf("%lld %lld",&n,&m);
        n=(n/2)*m;
        printf("Case %d: %lld\n",a,n);
    }
    return 0;
}
