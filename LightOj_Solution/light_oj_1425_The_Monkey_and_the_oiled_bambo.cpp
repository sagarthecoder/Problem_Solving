#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll n;scanf("%lld",&n);
        ll ara[n+2],maxi=0,mx=0;ara[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&ara[i]);
            maxi=max(maxi,ara[i]-ara[i-1]);
        }
        mx=maxi;
        for(int i=1;i<=n;i++)
        {
            if(ara[i]-ara[i-1]==maxi)maxi--;
            else if(ara[i]-ara[i-1]>maxi){
                maxi=-1;break;
            }
            if(maxi<0)break;
        }
        if(maxi<0)mx++;
        printf("Case %d: %lld\n",a,mx);
    }
    return 0;
}
