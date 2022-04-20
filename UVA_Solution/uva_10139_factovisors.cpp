#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool status[46350];
ll prime[46350];
ll p=0;
void siv()
{

    status[1]=1;
    status[0]=1;
    int M=46350;
     for(ll i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(int j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
int main()
{
    long long int n,i,j,m,sum1,sum2,value;
    siv();
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {

        if((n<=1 && m>1)){
            printf("%lld does not divide %lld!\n",m,n);continue;
        }
        else if(m<=1){
            printf("%lld divides %lld!\n",m,n);continue;
        }
        ll take=m,cnt=0,cnt2=0;
        bool ck=false;
        bool pri=false;
        for(ll i=0;prime[i]*prime[i]<=take && i<p;i++)
        {
             cnt=0,cnt2=0;

            if(take%prime[i]==0)
            {
                pri=true;
                while(take%prime[i]==0){
                    cnt++;
                    take=take/prime[i];
                }
                ll olala=prime[i];
                while(true)
                {
                    ll bhag=n/olala;
                    cnt2+=(bhag);
                    if(bhag==0)break;
                    olala*=prime[i];
                }
                //cout<<"prime = "<<prime[i]<<" cnt = "<<cnt<<" cnt2= "<<cnt2<<endl;
                if(cnt2<cnt){
                    ck=true;break;
                }
            }
        }
        if(!ck && take>1){
                cnt=1,cnt2=0;
                ll olala=take;
                    while(true)
                        {
                            ll bhag=n/olala;
                            cnt2+=(bhag);
                            if(bhag==0)break;
                            olala*=olala;
                        }
                    if(cnt2<cnt){
                        ck=true;
                    }
        }
        if(ck ||(pri==false && n<m))printf("%lld does not divide %lld!\n",m,n);
        else printf("%lld divides %lld!\n",m,n);
    }
    return 0;
}
