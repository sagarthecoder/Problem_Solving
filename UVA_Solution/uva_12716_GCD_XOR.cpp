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
#define ll long long
using namespace std;


ll mx=30000000,sum[30000002];
int main()
{
    for(ll i=1;i<mx;i++)
    {
        for(ll j=1;(i*j)+i<=mx;j++)
        {
            ll b=((i*j)+i)^(i*j);
            if(b==i)sum[(i*j)+i]++;
        }
    }
    for(ll i=1;i<=mx;i++)sum[i]+=sum[i-1];
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll x;scanf("%lld",&x);
        printf("Case %d: %lld\n",a,sum[x]);

    }
    return 0;
}

