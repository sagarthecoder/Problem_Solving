#include <stdio.h>
#include <math.h>
#define sf scanf
#define ll long long
#define pf printf
int prime[1000009],p=0;
bool status[1000009];
void siv()
{
       ///vector<int>prime;
    status[1]=1;
    status[0]=1;
    int M=1000005,i,j;
     for( i=2;i<=M;i++){
        if(status[i]==0){
            prime[p]=i;
            p++;
            for( j=2*i;j<=M;j=j+i){
                status[j]=1;
            }
        }
    }
}
int main()
{
    ll t,i,n,a;sf("%lld",&t);
    siv();
    for(a=1;a<=t;a++)
    {
        sf("%lld",&n);
        ll ex=1,cnt,k;
        for( k=0;k<p && prime[k]*prime[k]<=n;k++)
        {
            cnt=0;
            if(n%prime[k]==0)
            {
                while(n%prime[k]==0){
                    cnt++;
                    n=n/prime[k];
                }
            }
            ex*=(cnt+1);
        }
        if(n>1)ex*=2;
        printf("Case %lld: %lld\n",a,ex-1);
    }
    return 0;
}
