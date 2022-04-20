#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        int my,L;scanf("%d %d",&my,&L);
        ll ans=0;
        int baki=abs(my-L);
        ans=((4*baki)+3+5+3)+(my*4)+3+5;
        printf("Case %d: %lld\n",a,ans);
    }
    return 0;
}
