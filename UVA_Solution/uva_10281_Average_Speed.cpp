#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;

    int h1=0,m1=0,s1=0;
    long double olala=0.0,ans=0.0,v=0.0;
    bool ck=false;
    while(getline(cin,x))
    {
        int len=x.size();
        int h=((x[0]-'0')*10)+(x[1]-'0');
        int m=((x[3]-'0')*10)+(x[4]-'0');
        int s=((x[6]-'0')*10)+(x[7]-'0');
        ll sec=(h-h1)*3600;
        if(m>m1)sec+=((m-m1)*60);
        else sec-=((m1-m)*60);
        if(s>s1)sec+=((s-s1));
        else sec-=((s1-s));
        ans+=((long double)sec/3600)*v;
        if(len<=8){
        for(int i=0;i<=7;i++)cout<<x[i];
        cout <<" "<<setprecision (2) << fixed <<ans<<" km"<<endl;
        olala=0;
        }
        int cnt=-1;
        bool dilam=false;
        if(len>8){
            v=0.0;
            for(int i=9;i<len;i++){
                if(x[i]!=' ' && x[i]!='.')v=(v*10)+(x[i]-'0');
                if(x[i]=='.')dilam=true;
                if(dilam==true)break;
            }
        }
        h1=h,m1=m,s1=s;

    }
    return 0;
}
