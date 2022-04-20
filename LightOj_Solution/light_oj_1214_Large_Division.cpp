#include <bits/stdc++.h>
#define ll long long
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        char x[300];
        ll d,ans=0;scanf("%s",x);
        scanf("%lld",&d);
        printf("Case %d: ",a);
        d=abs(d);int len=strlen(x);
        for(int i=0;i<len;i++)
        {
           if(x[i]=='-')continue;
           ans=((ans*10)%d+(x[i]-'0')%d)%d;
        }
        if(ans==0)printf("divisible\n");
        else printf("not divisible\n");
    }
    return 0;
}
