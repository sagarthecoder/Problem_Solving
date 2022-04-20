#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll go(ll x)
{
    ll ans=0,five=5;
    for(int i=0;;i++)
    {
        if(five>x)break;
        ans+=(x/five);
        five*=5;
    }
    return ans;
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {

        ll  n;scanf("%lld",&n);
        printf("Case %d: ",a);
        ll low=5,mid,high=25*n;
        bool ck=false;
        while(low<=high)
        {
            mid=(low+high)/2;
            ll get=go(mid);
            if(get==n){
                    ck=true;
                    break;
            }
            if(get>n)high=mid-1;
            else low=mid+1;
        }
        if(!ck)printf("impossible\n");
        else{
        ll bhag=mid/5;
        ll ans=bhag*5;
        printf("%lld\n",ans);
        }

    }
    return 0;
}
