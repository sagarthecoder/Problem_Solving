
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
#define pi 3.1416
using namespace std;
int main()
{
   int t,n,b,ans;
   scanf("%d",&t);
   for(int i=1;i<=t;i++)
   {
       scanf("%d %d",&n,&b);
       if(n==0)ans=1;
       else{
       double x=((n+0.5)*log(n))-n+log(sqrt(pi*2));
       x=x/log(b*1.00);
        ans=ceil(x);
       }
       printf("Case %d: %d\n",i,ans);
   }
   return 0;
}
