#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ara[10000];
int main()
{
    ll a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        int cnt=0;swap(a,b);
        while(true)
        {
            ll bhag=b/a;
            ara[cnt]=bhag;cnt++;
            ll nilam=a;
            a=b%a;
            b=nilam;if(a==0)break;

        }
        printf("[");
        printf("%d",ara[0]);
        if(cnt>1){
            printf(";");
        }
        for(int i=1;i<cnt;i++)
        {
            if(i>1)printf(",");
            printf("%d",ara[i]);
        }
        printf("]\n");
    }
    return 0;
}
