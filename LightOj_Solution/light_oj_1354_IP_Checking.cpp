#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll go1(ll a,ll n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ans=go1(a,n/2);
    if(n%2==0)return ans*ans;
    else return ans*ans*a;

}
int main()
{
    int t;cin>>t;
    for(int a1=1;a1<=t;a1++)
    {
        ll a,b,c,d;
        char ch;
        string x;
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        cin>>x;int len=x.size();
        cout<<"Case "<<a1<<": ";
        int i=0,j=0;
        ll ans=0;
        bool ck=false;
        for( i=len-1,j=0;i>=0;i--,j++)
        {
            if(x[i]=='.'){
               if(ans!=d)ck=true;break;
            }
            if(x[i]=='1')
            ans+=go1(2,j);
        }
        i--;
        if(!ck){
            ans=0;
            for(j=0;i>=0;i--,j++){
                if(x[i]=='.'){
               if(ans!=c)ck=true;break;
            }
            if(x[i]=='1')
            ans+=go1(2,j);
            }
        }
        i--;
         if(!ck){
            ans=0;
            for(j=0;i>=0;i--,j++){
                if(x[i]=='.'){
               if(ans!=b)ck=true;break;
            }
            if(x[i]=='1')
            ans+=go1(2,j);
            }
        }
        i--;
         if(!ck){
            ans=0;
            for(j=0;i>=0;i--,j++){
            if(x[i]=='1')
            ans+=go1(2,j);
            }
        }
        if(ans!=a)ck=true;
        if(ck)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
