#include <bits/stdc++.h>
#define ll long long
using namespace std;
string x,y,z,u;
vector<string>v;
void go()
{
    z=y;
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int sz1=x.size(),sz2=y.size();
     u="";
    int maxi=max(sz1,sz2),carry=0,i;
    for(i=0;i<maxi;i++)
    {
        int num1=0,num2=0;
        if(i<sz1){
            num1=x[i]-'0';
        }
        if(i<sz2)num2=y[i]-'0';
        int add=num1+num2+carry;
         ///ara[i]=add%10;
         u+=((add%10)+'0');
        carry=add/10;

    }
    if(carry!=0)
    {
        ///ara[i]=carry;
        i++;
        u+=(carry+'0');
    }
    reverse(u.begin(),u.end());
    ///for(int j=i-1;j>=0;j--)cout<<ara[j];

}
int main()
{


    int n;

    x="1";
    y="1";
    v.push_back("0");v.push_back("1");v.push_back("1");
    for(int i=3;i<=5000;i++)
    {
        go();
        v.push_back(u);
        x=z;
        y=u;

    }
    while(cin>>n)
    {
        cout<<"The Fibonacci number for "<<n<<" is "<<v[n]<<endl;
       /// cout<<v[n]<<endl;
    }
    return 0;
}
