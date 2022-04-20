#include <bits/stdc++.h>
#define mx 1000000000000000000
#define ll  long long
using namespace std;
ll len,cnt,tort,hare,t;
bool comp(char ch)
{
    if(ch=='+' || ch=='*' || ch=='%')return true;
    return false;
}
ll go(char ch,ll top1,ll top2,ll n)
{
    if(ch=='+')return ((top1%n)+(top2%n))%n;
    if(ch=='*')return ((top1%n)*(top2%n))%n;
    if(ch=='%')return top2%top1;
}
ll func(ll x,string y,ll v,ll n)
{
    stack<ll>s;
    ll barbe=0,num=mx,top1,top2;
    for(ll i=v+1; i<len; i++)
    {
        if(y[i]==' ' && num!=mx)
        {
            s.push(num);
            num=mx,barbe=0;
        }
        else if(comp(y[i]))
        {
            top1=s.top();
            s.pop();
            top2=s.top();
            s.pop();
            s.push(go(y[i],top1,top2,n));
        }
        else if(y[i]=='N' || y[i]=='x')
        {
            if(y[i]=='N')s.push(n);
            else if(y[i]=='x') s.push(x);
        }
        else if(y[i]>='0' && y[i]<='9')
        {
            if(barbe==0)num=y[i]-'0';
            else num=(num*10)+(y[i]-'0');
            barbe++;
        }
    }
    //cout<<s.top()<<endl;
    return s.top();
}
ll go(ll hare2,ll tort2,string y,ll i,ll n)
{
     ///cout<<"tort = "<<hare2<<endl;
     while(true)
     {
         cnt++;
         ll period=func(tort2,y,i,n);
         if(period==hare2)break;
         tort2=period;
     }
     return cnt;
}
ll pos(string y,ll i,ll x,ll n)
{
    ll hareX=x,tortX=x,output;
    while(true)
    {
        //cnt++;
        tort=func(tortX,y,i,n);
        tortX=tort;
        hare=func(func(hareX,y,i,n),y,i,n);
        hareX=hare;
       /// cout<<"tort = "<<tort<<" , hare = "<<hare<<endl;
        if(hare==tort){
                 output=go(hare,tort,y,i,n);
                break;
        }

    }
    return cnt;
}
int main()
{
    string y;
    ll n,x;
    while(true)
    {
        getline(cin,y);
        cnt=0;
        len=y.size();
        ll u,v;
        if(y[0]=='0')break;
        for(u=0;; u++)
        {
            if(y[u]==' ')break;
            if(u==0)n=y[u]-'0';
            else n=(n*10)+(y[u]-'0');
        }
        for(v=u+1;; v++)
        {
            if(y[v]==' ')break;
            if(v==u+1)x=y[v]-'0';
            else x=(x*10)+(y[v]-'0');
        }
        //ll t=func(x,y,v);
        ll pos2=pos(y,v,x,n);
        ///cout<<"pos = "<<pos2<<endl;
        cout<<pos2<<endl;
    }
    return 0;
}
