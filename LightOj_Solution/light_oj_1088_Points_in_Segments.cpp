#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y,q;scanf("%d %d",&n,&q);
        int ara[n+2];
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        printf("Case %d:\n",a);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            int low=lower_bound(ara,ara+n,x)-ara;
            int high=upper_bound(ara,ara+n,y)-ara;
            printf("%d\n",high-low);
        }
    }
    return 0;
}
