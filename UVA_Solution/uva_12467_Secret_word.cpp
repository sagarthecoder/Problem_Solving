#include <bits/stdc++.h>
using namespace std;
int ara[1000000*2];
int go(string x,int len)
{
    int j=0,i=1,maxi=0;
    bool ck=false;
    while(i<len)
    {
        if(x[i]=='#')ck=true;
        if(j==0 && x[i]!=x[j]){i++;
        ara[i]=j;
        }
        else if(x[i]==x[j]){
            ara[i]=j+1;
            i++,j++;
        }
        else j=ara[j-1];
        if(ck==true)
        maxi=max(maxi,j);
        ///cout<<ara[len-1]<<endl;
    }
    return maxi;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string x,y,z,suff;cin>>x;
        memset(ara,0,sizeof(ara));
        y=x;
        reverse(y.begin(),y.end());
        z+=x;z+='#';z+=y;
        ///cout<<"z ="<<z<<endl;
        int len=z.size();
        int ans=go(z,len);
        suff=x.substr(0,ans);
        reverse(suff.begin(),suff.end());
        cout<<suff<<endl;
        ///cout<<"ans = "<<ans<<endl;
    }
    return 0;
}
