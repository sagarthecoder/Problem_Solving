#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll x,k,p,q;scanf("%lld %lld",&x,&k);
        q=x%k;
        if(x<k)p=0;
        else p=k-q;
        printf("%lld %lld\n",p,q);
    }
    return 0;
}
