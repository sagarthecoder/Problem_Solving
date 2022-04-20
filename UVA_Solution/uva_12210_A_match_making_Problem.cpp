#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,m,a=1;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)break;
        int ara[n+2],x;
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=0;i<m;i++)scanf("%d",&x);
        printf("Case %d: ",a);
        sort(ara,ara+n,greater<int>());
        if(m>=n)printf("0\n");
        else
        {
            int ok=n-m;
            printf("%d %d\n",ok,ara[n-1]);
        }
        a++;
    }
    return 0;
}
