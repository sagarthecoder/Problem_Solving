#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll val=1000000000000,A,B;
map<ll,ll>seen;
int barao=0,olala=0;
vector<ll>v,v2;
int sz=0;
void go(ll number)
{
    if(number>val)return;
    if(number!=0)v.push_back(number);
    seen[number]=1;
    go((number*10)+(4));go((number*10)+(7));
}
void go1(ll number,int i)
{

    //if(i>=sz)return;
    for(int j=i;j<sz;j++)
    {
        ll take=number*v[j];
        if(take>val || take<=0)return;
       /// olala++;
        if(seen[take]==0){
               /// if(take==196 || take==28)
        ///cout<<"number = "<<number<<", v[j]="<<v[j]<<", take = "<<take<<" , j = "<<j<<endl;
        v.push_back(take);seen[take]=1;
       /// barao++;
        //cout<<"ok"<<endl;
        }
        go1(take,j);
    }
}
int main()
{

    go(0);sort(v.begin(),v.end());

    sz=v.size();//cout<<sz<<endl;
    /*
    int cnt=0;
    for(int i=0;i<sz;i++){
            if(seen[v[i]]==0){
            cout<<v[i]<<endl;seen[v[i]]=1;cnt++;

            }

    }*/
    go1(1,0);sort(v.begin(),v.end());
   /// cout<<"olala= "<<olala<<endl;
   /// cout<<"baraw = "<<barao<<endl;
    /*sz=v2.size();
    cout<<"newsz = "<<sz<<endl;
    for(int i=0;i<sz;i++)cout<<"v = "<<v2[i]<<endl;
    // for(int i=0;i<sz;i++)seen[v[i]]=1;*/
   /// for(int i=0;i<=30;i++)cout<<v[i]<<endl;
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%lld %lld",&A,&B);
        int low=lower_bound(v.begin(),v.end(),A)-v.begin();
        int high=upper_bound(v.begin(),v.end(),B)-v.begin();
        printf("Case %d: %d\n",a,high-low);
    }
    return 0;
   // int cnt=0;




}
