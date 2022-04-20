#include <bits/stdc++.h>
#define ll long long
using namespace std;
int  status[1000007];
int  prime[1000000];
int p=0,ara[1000007],seen[1000007];
void siv()
{

    status[1]=1;
    status[0]=1;
    int  M=1000003;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(ll j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
ll go(ll n)
{
    int  cnt=n;

    if(status[n]==0)return n-1;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)n=n/prime[i];
            cnt=cnt-(cnt/prime[i]);
        }
    }
    if(n>1)cnt=cnt-(cnt/n);
    return cnt;
}
int main()
{
    int t,j=0,mini=0;scanf("%d",&t);
    siv();
    for(int i=2;i<=1000003;i++){
        int ok=go(i);
        if(ok>mini){
            ara[j]=ok;mini=ok;
            seen[ok]=i;
            j++;
        }
    }
    for(int a=1;a<=t;a++)
    {
        int n,x;scanf("%d",&n);
        ll ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            int low=lower_bound(ara,ara+j,x)-ara;
            ans+=seen[ara[low]];

        }
        printf("Case %d: %lld Xukha\n",a,ans);
    }
    return 0;
}
