#include <bits/stdc++.h>
#define ll long long
#define e 2.71828182845904523536
double pi=(double)22/7;
using namespace std;
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        if(n==m)cout<<"1"<<endl;
        else{
        ll one=n-m;
        double  go=n* log10(( n/ e)) + log10(2*pi*n)/2;
        double go2=one* log10(( one/ e)) + log10(2*pi*one)/2;
        double go3=m* log10(( m/ e)) + log10(2*pi*m)/2;
        double bad=go-go2-go3;
        ll ans=ceil(bad);
        cout<<ans<<endl;
        }

    }
    return 0;
}




