#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long int n,i,sum,arr[100000];
    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        if(n==0)
            break;
            i=0;
        while(1)
        {
            arr[i]=n%2;
            if(n%2==1)
            {
                sum=sum+1;
            }
            if(n/2==0)
                break;
            n=n/2;
            i++;
        }
        printf("The parity of ");
               for(int j=i;j>=0;j--)
                printf("%lld",arr[j]);
               printf(" is %lld (mod 2).\n",sum);
    }
    return 0;
}
