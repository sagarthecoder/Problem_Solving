#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return GCD(b,a%b);
}
int main()
{
    int t;cin>>t;
    string x;getline(cin,x);
    for(int a=1;a<=t;a++)
    {
        getline(cin,x);
        int len=x.size();
        int n,cnt=0,maxi=0;
        vector<int>v;
        for(int i=0;i<len;i++)
        {
            if(x[i]==' ' && n!=0)
            {
                v.push_back(n);
                n=0,cnt=0;
            }
            else if(cnt==0 && x[i]!=' ')
            {
                n=x[i]-'0';
                cnt=1;
            }
            else if(x[i]!=' ' && cnt!=0){
                n=(n*10)+(x[i]-'0');
            }
        }
        if(n!=0)v.push_back(n);
        int sz=v.size();
        for(int i=0;i<sz-1;i++)
        {
            for(int j=i+1;j<sz;j++){
                int x=v[i],y=v[j];
                if(y>x)swap(x,y);
                maxi=max(maxi,GCD(x,y));
            }
        }
        cout<<maxi<<endl;

    }
    return 0;
}
