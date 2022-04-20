#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<long long int,long long int> pii;
#define x first
#define y second

pii extendedEuclid(long long int a,long long int b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}
long long int gcd(long long int a,long long int b)
{

  return b == 0 ? a : gcd(b, a % b);

}
int main()
{
    long long int a,b,d,x,y,res;
    pair<long long int,long long  int> pii2;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        pii2=extendedEuclid(a,b);
        if(a<b)
            swap(a,b);
        d=gcd(a,b);
        printf("%lld %lld %lld\n",pii2.first,pii2.second,d);

    }
    return 0;

}
