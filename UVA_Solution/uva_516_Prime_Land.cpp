#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    ll x,power;
};
bool status[32780];
int prime[32780];
int p=0;
void siv()
{

    status[1]=1;
    status[0]=1;
    int M=32770;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(int j=i+i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
bool comp(data u,data u1)
{
    return u.x>u1.x;
}

int main()
{
    string x;
    siv();
    while(true)
    {
        getline(cin,x);
        if(x=="0")break;
        int len=x.size();
        vector<data>ok;
        vector<ll>v;
        ll ans=0;
        for(int i=0;i<len;i++)
        {
            if(x[i]==' '){
                if(ans)v.push_back(ans);
                ans=0;
            }
            else ans=(ans*10)+(x[i]-'0');

        }
        if(ans)v.push_back(ans);
        int sz=v.size();
        ll banabo=1;
        for(int i=0;i<sz;i++)
        {
            if(i%2==0)banabo*=v[i];
            else{
                for(ll j=1;j<v[i];j++)banabo*=(v[i-1]);
            }
        }
        banabo--;
        ///cout<<"banabo = "<<banabo<<endl;
        if(banabo==1){
            printf("2 0\n");continue;
        }
        for(ll i=0;prime[i]*prime[i]<=banabo;i++)
        {
            ll cnt=0;
            if(banabo%prime[i]==0){
                while(banabo%prime[i]==0){
                    cnt++;
                    banabo=banabo/prime[i];
                }
                ok.push_back({prime[i],cnt});
            }
        }
        if(banabo>1)ok.push_back({banabo,1});
        sort(ok.begin(),ok.end(),comp);
        sz=ok.size();
        for(int i=0;i<sz;i++){
            if(i>0)printf(" ");
            printf("%lld %lld",ok[i].x,ok[i].power);
        }
        printf("\n");

    }
    return 0;
}
