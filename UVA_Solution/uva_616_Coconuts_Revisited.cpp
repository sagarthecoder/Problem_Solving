#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool ck=false;
bool go(ll j,ll n)
{
    for(ll i=1;i<=j;i++)
    {
        if(n%j!=1){
            ck=true;break;
        }
        n-=((n/j)+(n%j));
    }
    if(ck==false && n%j==0)return true;
    return false;

}
int main()
{
    ll n;
    while(true)
    {
       scanf("%lld",&n);
       if(n<0)break;
       if(n==0){
        printf("0 coconuts, no solution\n");
       }
       else
       {

           bool mairala=false;
           ll maxi=0;
           for(ll i=1;i<=10;i++){
             ck=false;
             bool ans=go(i,n);
             if(ans==true){
                maxi=max(maxi,i);

                ///printf("%lld coconuts, %lld people and 1 monkey\n",n,i);
                mairala=true;
             }
           }

           if(!mairala)printf("%lld coconuts, no solution\n",n);
           else printf("%lld coconuts, %lld people and 1 monkey\n",n,maxi);
       }

    }
    return 0;

}
