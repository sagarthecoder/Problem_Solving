#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
       int n;scanf("%d",&n);
       printf("Case %d: ",a);
       int ans=__builtin_popcount(n);
       if(ans%2!=0)printf("odd\n");
       else printf("even\n");

    }
    return 0;
}
