#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;
long long int value;
void prime(long long int n)
{
    value=0;
    for(long long int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            value=1;
            return;
        }
    }
}
int main()
{
    long long int g,i,j,k,res,place,line;
    while(scanf("%lld",&g)!=EOF)
    {
        if(g==0)
            break;
        place=g;
        if(place<0)
        {
            place=-place;
        }

        prime(place);
        if(value==0 && g<0)
        {
            printf("%lld = -1 x %lld",g,-g);
        }
        else if(value==0 && g>0)
        {
            printf("%lld = %lld",g,g);
        }
        else
        {
            line=0;
            if(g<0)
            {
                printf("%lld = -1 x",g);
                g=-g;
            }
            else
            {
                printf("%lld =",g);
            }
            for(i=2; i<=g; i++)
            {
                j=0;
                while(g%i==0)
                {
                    if(line!=0)
                    {
                        printf(" x") ;
                    }
                    printf(" %lld",i);
                    g=g/i;
                    line++;
                    j++;

                }
            }
        }
        printf("\n");
    }
}
