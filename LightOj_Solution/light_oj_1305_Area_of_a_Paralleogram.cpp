#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {
        ll a1,a2,b1,b2,c1,c2,d1,d2;
        scanf("%lld %lld %lld %lld %lld %lld",&a1,&a2,&b1,&b2,&c1,&c2);
        d1=(a1+c1)-b1;
        d2=(a2+c2)-b2;
        ///cout<<"b2 + c2 = "<<b2+c2<<endl;
       /// printf("values all   %lld %lld %lld %lld %lld %lld %lld %lld\n",a1,a2,b1,b2,c1,c2,d1,d2);

        ll ans=(a1*b2)+(b1*c2)+(c1*d2)+(d1*a2);
        ll ans2=(b1*a2)+(c1*b2)+(d1*c2)+(a1*d2);
        ll res=(ans-ans2)/2;
        printf("Case %d: %lld %lld %lld\n",a,d1,d2,abs(res));
    }
    return 0;
}
