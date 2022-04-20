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
#define ll unsigned long long int
int main()
{
    ll t,n;
    scanf("%lld",&t);
    for(ll a=1;a<=t;a++)
    {
        scanf("%lld",&n);
        ll ans=1;
        while(true)
        {
            if(n%2!=0)break;
            ans*=2;
            n=n/2;
        }
        if(ans==1)printf("Case %lld: Impossible\n",a);
        else
            printf("Case %lld: %lld %lld\n",a,n,ans);
        //if(n%2!=0)printf("Case %lld: Impossible\n",a);
            //printf("Case %lld: %lld %lld\n",a,odd,res);
    }
    return 0;
}
