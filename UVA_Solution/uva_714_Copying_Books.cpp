#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ara[510],sum=0;
int seen[510];
bool sagar(ll banabo)
{
    ll cnt=0,jug=0;
    for(int i=0;i<n;i++)
    {
        jug+=ara[i];
        if(ara[i]>banabo)return false;
        if(i==n-1){
            if(jug>banabo)cnt++;
            break;
        }
        /*if(i==n-1){
            cout<<"banabo  ="<<banabo<<"  jug ="<<jug<<endl;
            if(jug>banabo)return false;
            break;
        }*/
        if(jug==banabo){
            cnt++;jug=0;
        }
        else if(jug>banabo){
            cnt++;
            jug=ara[i];
        }
    }
    if(cnt<m)return true;
    return false;
    ///return (cnt<=m);
}
ll go()
{
    ll low=0,high=sum,mid,saikat;
    while(low<=high)
    {
         mid=(low+high)>>1;
        bool taken=sagar(mid);
        if(taken){
            saikat=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return saikat;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        sum=0;scanf("%lld %lld",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&ara[i]);
            sum+=ara[i];seen[i]=0;
        }
        seen[n]=0;
        if(m==1){
            for(int i=0;i<n;i++){
                if(i>0)printf(" ");
                printf("%lld",ara[i]);
            }
            printf("\n");
            continue;
        }
       ll ans=go();
       ///cout<<"ans = "<<ans<<endl<<endl;;
       ll ok=0,sum2=0;int sz=0;
      /// vector<ll>v;
       for(int i=n-1;i>=0;i--)
       {
            sum2+=ara[i];
            ///cout<<"aar = "<<ara[i]<<endl;
           // cout<<"sum2 = "<<sum2<<endl;
            if(i==0){
                if(sum2>ans){
                sz++;seen[1]=1;
                }
                break;
            }
            if(sum2==ans){

                ///cout<<"down = "<<sum2<<" i = "<<i<<endl;
                sum2=0;sz++;seen[i]=1;
            }
            else if(sum2>ans){
                sz++;seen[i+1]=1;
                ///cout<<"sum2In = "<<sum2<<"  i = "<<i<<endl;
                sum2=ara[i];
            }
       }
       if(sz!=m-1){
         for(int i=1;i<n;i++)
         {
             if(sz<m-1)
             {
                 if(seen[i]==0){
                    sz++;seen[i]=1;
                 }
             }
             else break;
         }
       }
       ///for(int i=0;i<v.size();i++)cout<<"v = "<<v[i]<<endl;
       ok=0;
       for(int i=0;i<n;i++){
         if(seen[i]){
            printf(" /");ok++;
         }
         if(i>0)printf(" ");
         printf("%lld",ara[i]);

       }
       printf("\n");

    }
    return 0;
}

