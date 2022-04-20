#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NX = 1e6 + 10 ;
ll prime[ NX ] ;

int check[ NX ] , idx ;

void ini()
{
    prime[idx++] = 2 ;
    int i , j ;
    for ( i = 3 ; i * i < NX ; i += 2 )
    {
        if( check[i] == 0 )
        {
            prime[idx++] = i ;
            for ( j = i * i ; j < NX ; j += (  2 * i ) ) check[j] = 1 ;
        }
    }
    while( i < NX )
    {
        if( check[i] == 0 ) prime[idx++] = i ;
        i += 2 ;
    }
}


int main()
{
    ini();
    int t;scanf("%d",&t);
    for(int a1=1;a1<=t;a1++)
    {
        ll a,b;scanf("%lld %lld",&a,&b);
        ll ans=1;ll take=a;
        ll sq=sqrt(a);
        if(sq<b){
            printf("Case %d: 0\n",a1);continue;
        }
       // cout<<"ok = "<<sq<<endl;
        for(int i=0;prime[i]<=sqrt(a) && i<idx;i++){
            ll cnt=0;

                while(a%prime[i]==0){
                    a=a/prime[i];
                    cnt++;
                }
                ans*=(cnt+1);

        }
        if(a>1){
            ans*=2;
        }
        ans=(ans/2);
       // cout<<"before = "<<ans<<endl;
        for(int i=1;i<b;i++){
           // cout<<"bb"<<endl;
            if(take%i==0)ans--;
        }
        printf("Case %d: %lld\n",a1,ans);
    }
    return 0;
}
