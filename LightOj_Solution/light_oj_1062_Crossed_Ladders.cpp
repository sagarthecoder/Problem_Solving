#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        double x,y,ans,c;///scanf("%f %f %f",&x,&y,&c);
        cin>>x>>y>>c;
        double L=0,H=x,mid;
        if(H>y)H=y;
        ///cout<<"min = "<<H<<endl;
        int cnt=0;
        while(L<=H && cnt<=1000)
        {
            mid=(L+H)/2.0;
            double h1=sqrt((x*x)-(mid*mid));
            double h2=sqrt((y*y)-(mid*mid));
             ans=(h1*h2)/(h1+h2);
            if(ans>c){
                L=mid;
            }
            else H=mid;
            cnt++;
        }
        cout<<"Case "<<a<<": ";
        cout<<setprecision(10)<<fixed<<mid<<endl;///othoba L or H print dileo accepted hobe
       /// printf("Case %d: %.10f\n",a,L);
    }
    return 0;
}
