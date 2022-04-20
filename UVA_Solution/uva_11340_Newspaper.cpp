#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,v,q;cin>>n;
        string x;
        char ch;
        map<char,int>ara;
        ll ans=0;
        while(n--)
        {
            getchar();
            ch=getchar();
            cin>>v;
            ara[ch]=v;
        }
        cin>>q;
       getline(cin,x);
       while(q--)
       {
           getline(cin,x);
           int len=x.size();
           for(int i=0;i<len;i++){
            ans+=ara[x[i]];
           }
       }
        double bhag=( double)ans/100.0;
       cout<<setprecision(2)<<fixed<<bhag<<"$"<<endl;
    }
    return 0;
}
