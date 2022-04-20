#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   ll t;scanf("%lld",&t);
    ll ara[20];
    ara[0]=1;
    ll ans=1;
    for(ll i=1;i<=19;i++){
        ans*=i;
        ///cout<<"ans = "<<ans<<endl;
        ara[i]=ans;
    }
    for(ll a=1;a<=t;a++)
    {
        ll n;scanf("%lld",&n);
        printf("Case %lld: ",a);
        ///if(n>ara[19])printf("impossible\n");
        ///else
        ///{
            ll low=lower_bound(ara,ara+20,n)-ara;
            if(low==20)low--;
           /// cout<<"low="<<low<<endl;
            bool ck=false;
            vector<ll>v;
            for(ll i=low;i>=0;i--)
            {
               ///cout<<"ara = "<<ara[i]<<endl;
                if(n>=ara[i]){
                    n-=ara[i];
                   /// cout<<"nm="<<n<<endl;
                    v.push_back(i);
                }
                if(n==0){
                    ck=true;break;
                }
            }
            if(ck){
                ll sz=v.size();
                ck=false;
                for(ll i=sz-1;i>=0;i--)
                {
                    if(ck)printf("+");
                    printf("%lld!",v[i]);
                    ck=true;
                }
                printf("\n");
            }
            else printf("impossible\n");
       /// }
    }
    return 0;
}
