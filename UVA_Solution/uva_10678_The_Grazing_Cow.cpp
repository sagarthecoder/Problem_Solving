#include <bits/stdc++.h>
#define ll long long
using namespace std;
double pi=2*acos(0);
int main()
{
    int t;cin>>t;
    while(t--)
    {
        double d,l;cin>>d>>l;
        d=d/(double)(2);
        l=l/(double)2;
        double x=sqrt((l*l)-(d*d));
        double ans=pi*x*l;
        cout<<setprecision(3)<<fixed<<ans<<endl;

    }
    return 0;
}
