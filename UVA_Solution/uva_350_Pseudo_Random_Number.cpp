#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt;
ll pass(ll Z,ll L,ll I,ll M)
{
    return ((((Z%M)*(L%M))%M)+(I%M))%M;
}
ll final_ans(ll Z,ll tort,ll I,ll M)
{
    ll take=tort;
    while(true)
    {
        ll huh=pass(Z,tort,I,M);
        if(huh==take)break;
        tort=huh;
        cnt++;
    }
    return cnt;
}
ll go(ll Z,ll L,ll I,ll M)
{
    ll hare1=L,tort1=L;
    while(true)
    {
        ll tort=pass(Z,tort1,I,M);
        ll hare=pass(Z,pass(Z,hare1,I,M),I,M);
        if(tort==hare){final_ans(Z,tort,I,M);
        break;
        }
        tort1=tort,hare1=hare;
    }
    return cnt;
}
int main()
{
    ll Z,I,M,L,a=1;
    while(true)
    {
        scanf("%lld %lld %lld %lld",&Z,&I,&M,&L);
        cnt=1;
        if(Z+I+M+L==0)break;
        printf("Case %lld: %lld\n",a,go(Z,L,I,M));
        a++;


    }
    return 0;
}
