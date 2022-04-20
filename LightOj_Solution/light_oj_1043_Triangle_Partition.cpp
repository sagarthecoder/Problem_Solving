#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        double AB,AC,BC,R;
        ///scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&R);
        cin>>AB>>AC>>BC>>R;
        double ans=AB*sqrt((double)R/(double)(R+1));
       /// printf("Case %d: %.10lf\n",ans);
       cout<<"Case "<<a<<": "<<setprecision(10)<<fixed<<ans<<endl;
    }
    return 0;
}
