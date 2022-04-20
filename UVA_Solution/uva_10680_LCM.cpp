#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool status[1000002];
ll prime[1000002];
ll p=0,mx[1000002],ok=1,ans[1000004],i1;
void siv()
{

    status[1]=1;
    status[0]=1;
    ll M=1000000;
    for(int i=2; i<=M; i++)
    {
        if(status[i]==false)
        {
            prime[p]=i;
            for(int j=i+i; j<=M; j=j+i)
            {
                status[j]=true;
            }
            p++;
        }
    }
}
void go2()
{
    ll omg=0;
    vector<ll>v;
    while(ok%10==0)
    {
        ok=ok/10;
    }
    while(true)
    {
        ll rem=ok%10;
        omg++;
        v.push_back(rem);
        if(ok/10==0 || omg==10)
            break;
        ok=ok/10;
    }
    ok=0;
    for(ll k=omg-1; k>=0; k--)
    {
        ok=(ok*10)+v[k];
    }

}
void go(ll x)
{
    for(ll i=0; prime[i]*prime[i]<=x; i++)
    {
        if(x%prime[i]==0)
        {
            ll cnt=0;
            while(x%prime[i]==0)
            {
                cnt++;
                x=x/prime[i];
            }
            if(cnt>mx[prime[i]])
            {
                ll bad=cnt-mx[prime[i]];
                for(ll j=1; j<=bad; j++)
                {
                    ok*=prime[i];
                    go2();
                }
                mx[prime[i]]=cnt;
            }
        }
    }
    if(x>1)
    {
        if(1ll>mx[x])
        {
            ok*=x;
            go2();
            mx[x]=1ll;
        }
    }
}
int main()
{
    ll n;
    siv();
    ok=1;
    ans[1]=1;
    for( i1=2; i1<=1000000; i1++)
    {
        go(i1);
        ll amar=ok;
        while(amar%10==0)amar=amar/10;
        ans[i1]=amar%10;
    }
     while(true)
     {
         scanf("%lld",&n);
         if(!n)break;
         printf("%lld\n",ans[n]);
     }
    return 0;
}
