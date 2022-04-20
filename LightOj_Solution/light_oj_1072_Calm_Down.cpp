#include <bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        double R,n;cin>>R>>n;
        double gun=pi/(180*1.00);
        double degree=sin(((360*1.00)/(n*2))*gun);
        double r=(degree*R)/(1+degree);
        cout<<"Case "<<a<<": ";
        cout << setprecision (20) << fixed <<r<<endl;
    }
    return 0;
}
