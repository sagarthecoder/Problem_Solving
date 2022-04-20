#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
#define mx 10000005
#define mod 1000000000
#define pi 2*acos(0.0)
#define inf 0x3f3f3f3f3f3f3f
int main()
{
    int t;
    double r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        double area=(r*2*1.0)*(r*2*1.0);
        double res=(area)-(pi*r*r*1.0)+(1.0/(mod*1.0));
        printf("Case %d: %.2lf\n",i,res);
    }
    return 0;
}
