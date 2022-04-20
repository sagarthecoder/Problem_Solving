#include <bits/stdc++.h>
#define ll long long
#define pi acos(-1)
#define bad 1e-7
using namespace std;
double p,q,r,s,t,u;
double go(double x)
{
    double redi=x;
    double res=(p*exp(-redi))+(q*sin(redi))+(r*cos(redi))+(s*tan(redi))+(t*x*x)+u;
    return res;
}
double ans()
{
    double low=0,high=1,mid;
    int cnt=0;
    while(low+bad<high){
    mid=(low+high)/(double)2;
    double omg=go(low)*go(mid);
    if(omg<=0)high=mid;
    else low=mid;

    }
    return mid;
}
int main()
{

    ///double bhag=sin(0.5236);
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        ///cin>>p>>q>>r>>s>>t>>u;

        double ck=go(0)*go(1);
        if(ck>0){
            cout<<"No solution"<<endl;
            continue;
        }
        double dilaw=fabs(ans());
        cout<<setprecision(4)<<fixed<<dilaw<<endl;
    }
   /// cout<<setprecision(5)<<fixed<<pi<<endl;
    return 0;
}
