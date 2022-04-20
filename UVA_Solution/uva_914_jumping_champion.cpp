#include <cstdio>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int nprime[1000009],seen[130];
vector<int>prime;
void sieve()
{
    int x=1000003;
    int i,j,k,sq;
    prime.push_back(2);
    sq=sqrt(x)+1;
    for(i=4; i<=x; i+=2)
        nprime[i]=1;
    for(i=3; i<=x; i+=2)
    {
        if(nprime[i]==0)
        {
            prime.push_back(i);
            if(i<=sq)
            {
                for(j=i*i; j<=x; j+=i*2)
                    nprime[j]=1;
            }
        }
    }
}
int main()
{
    int t,L,U,sum,i,ans,j,ck,ck2;
    sieve();
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        ck2=0;
        scanf("%d %d",&L,&U);
        int res=-1;
        memset(seen,0,sizeof(seen));
        if( L>=U)
            printf("No jumping champion\n");
        else if(L==2 && U==3)
            printf("The jumping champion is 1\n");
        else if(U-L<2 || U<3)
            printf("No jumping champion\n");
        else
        {
            for(i=0; i<prime.size(); i++)
            {
                if(prime[i]>=U)
                    break;
                if(prime[i]>=L && prime[i]<=U && prime[i+1]<=U)
                {
                    ck2=1;
                    int dif=prime[i+1]-prime[i];
                    seen[dif]=seen[dif]+1;
                    if(res<seen[dif])
                    {
                        res=seen[dif];
                        ck=0;
                        ans=dif;
                    }
                    else if(res==seen[dif])
                    {
                        ck=1;
                    }

                }
            }
            if(ck==1 || ck2==0)
            {
                printf("No jumping champion\n");
            }
            else
            {
                printf("The jumping champion is %d\n",ans);
            }
        }
    }
    return 0;
}
