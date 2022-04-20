#include <bits/stdc++.h>
using namespace std;
vector<string>v;
string go(string x,char y,int cnt)
{
    string ok;
    int len=x.size();
    ////reverse(x.begin(),x.end());
    if(len==0){
        ok+=y;
        return ok;
    }
    for(int i=1;i<=cnt;i++)ok+='0';
    int carry=0;
    for(int i=0;i<len;i++)
    {
        int gun=((y-'0')*(x[i]-'0'))+carry;
        carry=gun/10;
        int rem=gun%10;
        ok+=(rem+'0');

    }
    if(carry!=0)ok+=(carry+'0');
    return ok;

}
string addition(string x,string y)
{
    int sz1=x.size(),sz2=y.size();
    string ok;
    int maxi=max(sz1,sz2),carry=0,i;
    for( i=0;i<maxi;i++)
    {
        int num1=0,num2=0;
        if(i<sz1){
            num1=x[i]-'0';
        }
        if(i<sz2)num2=y[i]-'0';
        int add=num1+num2+carry;
         ///ara[i]=add%10;
         ok+=((add%10)+'0');
        carry=add/10;

    }
    if(carry!=0)
    {
        ///ara[i]=carry;i++;
        ok+=(carry+'0');
    }
    return ok;
}
int main()
{
    int n=1000,m;
    ///while(cin>>n)
    ///{
        ////cout<<n<<"!"<<endl;
        ///if(n<2)cout<<1<<endl;
       /// else
       ///{
            string x="";
            v.push_back("1");v.push_back("1");
            for(int i=2;i<=n;i++)
            {
                int taken=i,cnt=0;
                string prev,pluss,ans;
                while(true)
                {
                   int rem=taken%10;
                   ///cout<<"x= "<<x<<endl;
                   ///cout<<"rem = "<<rem<<endl;
                    ans=go(x,rem+'0',cnt);
                   ///cout<<"ans = "<<ans<<endl;
                   if(cnt>0)pluss=addition(prev,ans);
                   ///x=ans;
                   cnt++;
                   if(taken/10==0)break;
                   if(cnt==1)
                   prev=ans;
                   else prev=pluss;
                   taken=taken/10;
                }
                if(cnt>1)x=pluss;
                else x=ans;
                string finally=x;
                reverse(finally.begin(),finally.end());
                v.push_back(finally);

                ///x=ans;
                ///cout<<"outer loop x  = "<<ans<<endl;
            }
            ///reverse(x.begin(),x.end());
            ////cout<<x<<endl;
        ///}
    ///}
    while(cin>>m)
    {
        cout<<m<<"!"<<endl;
        cout<<v[m]<<endl;
    }
    return 0;
}
