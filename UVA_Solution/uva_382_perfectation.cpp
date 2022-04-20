#include <cstdio>
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    long long int  n,i,j,k,a[1000],b[1000],c[1000],sum_of_divisors,res,exponent;
        for(i=0; ;i++)
        {
            scanf("%lld",&a[i]);
            c[i]=a[i];
            if(a[i]==0)
                break;
                sum_of_divisors=1;
         res=1;
         for(j=2;j<=a[i];j++)
         {
             exponent=0;
             while(a[i]%j==0)
             {
                 exponent++;
                 a[i]=a[i]/j;
             }
             for(k=1;k<=exponent+1;k++)
             {
                 res=res*j;
             }
             sum_of_divisors*=(res-1)/(j-1);
             res=1;
         }
         b[i]=sum_of_divisors-c[i];

        }
        printf("PERFECTION OUTPUT\n");
        for(j=0;j<i;j++)
        {


                if(c[j]<10)
                {
                    printf("    ");
                }
                else if(c[j]<100)
                    printf("   ");
                else if(c[j]<1000)
                    printf("  ");
                else if(c[j]<10000)
                    printf(" ");
                else if(c[j]<100000)
                    printf("");
                printf("%lld",c[j]);
                if(b[j]==c[j])
                printf("  PERFECT\n");
                else if(b[j]<c[j])
                    printf("  DEFICIENT\n");
                else if(b[j]>c[j])
                    printf("  ABUNDANT\n");
        }
        printf("END OF OUTPUT\n");
    return 0;
}
