#include <bits/stdc++.h>
#define ll long long
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        char x[20];ll n;
        scanf("%lld",&n);
        scanf("%s",x);
        printf("Case %d: ",a);
        if(x[0]=='A')
        {
            if(n%3==1)printf("Bob\n");
            else printf("Alice\n");
        }
        else
        {
            if(n%3!=0)printf("Bob\n");
            else printf("Alice\n");
        }
    }
    return 0;
}
