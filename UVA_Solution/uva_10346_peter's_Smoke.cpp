#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
       ll ans=n;
       while(true)
       {
           ll bhag=n/m;
           ans+=bhag;
           n=bhag+(n%m);
           if(n<m)break;
       }
       cout<<ans<<endl;
    }
    return 0;

}
