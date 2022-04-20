#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
#define mx 10000005
#define mod 10000007
ll a,b,c,d,e,f;
map<ll,ll>seen;
//ll seen[100002];
ll fn(ll n)
{
    if( n == 0 ) return a%mod;
    if( n == 1 ) return b%mod;
    if( n == 2 ) return c%mod;
    if( n == 3 ) return d%mod;
    if( n == 4 ) return e%mod;
    if( n == 5 ) return f%mod;
    if(seen[n]!=0)return seen[n]%mod;
    //return( ((((fn(n-1))+ (fn(n-2)))%mod + (fn(n-3)))%mod) + (fn(n-4)) + (fn(n-5))%mod + (fn(n-6))%mod )%mod;
    return seen[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main()
{
    ll n,cas=0,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);
        ll res=fn(n)%mod;
        printf("Case %lld: %lld\n",++cas,res);
        seen.clear();
    }
    return 0;
}
