#include <cstdio>
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int n,t,i,j,sum0,sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum0=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0;
            for(i=1;i<=n;i++)
            {
                int v=i;
                while(1)
                {
                    int k=v%10;
                    if(k==0)
                        sum0=sum0+1;
                    else if(k==1)
                        sum1=sum1+1;
                    else if(k==2)
                        sum2=sum2+1;
                    else if(k==3)
                        sum3=sum3+1;
                    else if(k==4)
                        sum4=sum4+1;
                    else if(k==5)
                        sum5=sum5+1;
                    else if(k==6)
                        sum6=sum6+1;
                    else if(k==7)
                        sum7=sum7+1;
                    else if(k==8)
                        sum8=sum8+1;
                    else
                        sum9=sum9+1;
                    if(v/10==0)
                        break;
                    v=v/10;
                }
            }
            printf("%d %d %d %d %d %d %d %d %d %d\n",sum0,sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9);
    }
    return 0;
}
