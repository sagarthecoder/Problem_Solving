#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    ll x,val;
};
bool status[10000002];
ll prime[10000002];
int p=0;
void siv()
{

    status[1]=1;
    status[0]=1;
    ll M=10000000;
     for(ll i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(ll j=i+i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
bool comp(data u,data u1)
{
    return u.x<u1.x;
}
ll GCD(ll a,ll b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(a%b==0)
        return b;
    else
        return GCD(b,a%b);
}
int main()
{
    siv();
    int t;scanf("%d",&t);
    while(t--)
    {
        ll A,B;
        vector<data>v;
        scanf("%lld %lld",&A,&B);
        if(GCD(A,B)!=A){
            printf("NO SOLUTION\n");
        }
        else
        {
            for(ll i=0;prime[i]*prime[i]<=A;i++)
            {
                if(A%prime[i]==0)
                {
                    ll cnt=1;
                    while(A%prime[i]==0){
                        cnt*=prime[i];
                        A=A/prime[i];
                    }
                    v.push_back({prime[i],cnt});
                }
            }
            if(A>1){
                v.push_back({A,A});
            }

            for(ll i=0;prime[i]*prime[i]<=B;i++)
            {
                if(B%prime[i]==0)
                {
                    ll cnt=1;
                    while(B%prime[i]==0){
                        cnt*=prime[i];
                        B=B/prime[i];
                    }
                   v.push_back({prime[i],cnt});
                }
            }
            if(B>1)v.push_back({B,B});
            ll ok=1;
            sort(v.begin(),v.end(),comp);
            ll sz=v.size();
            v.push_back({-1,1});
            for(int i=0;i<=sz;i++)
            {
                if(v[i].x==-1)break;

                if(v[i].x==v[i+1].x){
                    if(v[i].val!=v[i+1].val)ok*=v[i+1].val;
                    i++;
                }
                else ok*=v[i].val;

            }
            printf("%lld\n",ok);
        }

    }
    return 0;

}
