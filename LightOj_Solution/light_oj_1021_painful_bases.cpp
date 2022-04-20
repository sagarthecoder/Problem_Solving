#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n1,k,len=0;
ll seen[20];
char x[20];
ll val;
ll Set(ll n,ll i)
{
    return n=(n|(1<<i));
}
ll reset(ll n,ll i)
{
    return (n&(~(1<<i)));
}
bool check(ll n,ll i)
{
    return (bool)(n&(1<<i));

}
ll dp[20][(1<<17)];
ll go(ll mask,ll ans)
{

    if(mask==val)
    {
        if(ans==0)
            return 1;
        else
           return 0;
    }
   if(dp[ans][mask]!=-1){
        ///cout<<"olala "<<endl;
        return dp[ans][mask];
   }
    ll vitore=0;
    for(ll i=0;i<len;i++)
    {
        if(check(mask,i)==0)
        {

                  ll olala=((ans*n1)+seen[i])%k;


                   vitore+=go(Set(mask,i),olala);
        }
    }
     return dp[ans][mask]=vitore;
}
int main()
{

    ll t;
    scanf("%lld",&t);
    for(ll a=1; a<=t; a++)
    {
        scanf("%lld %lld",&n1,&k);
        memset(dp,-1,sizeof(dp));

        scanf("%s",x);
        printf("Case %lld: ",a);
        len=strlen(x);
        for(int i=0;i<len;i++)
        {
            if(x[i]>='A' && x[i]<='F')seen[i]=10-('A'-x[i]);
            else seen[i]=x[i]-'0';
        }
        val=(1<<len)-1;

        ll ans=go(0,0);
        printf("%lld\n",ans);

    }
    return 0;
}
