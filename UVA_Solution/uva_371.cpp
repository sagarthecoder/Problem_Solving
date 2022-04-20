#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long int shuru,shes,i,j,sum,res,taken,ans,maxi;
    while(scanf("%lld %lld",&shuru,&shes)!=EOF)
    {
        maxi=0;
        if(shuru==0 && shes==0)
            break;
        if(shuru>shes)
        {
            long long int temp=shuru;
            shuru=shes;
            shes=temp;
        }
        for(i=shuru; i<=shes; i++)
        {
            res=0;
            taken=i;
            while(1)
            {

                if(taken%2==0)
                {
                    taken=taken/2;
                    res++;
                }
                else
                {
                    taken=(3*taken)+1;
                    res++;
                }
            }
            if(taken==1)
            {

                break;
            }
        }
        if(maxi<res)
        {
            maxi=res;
            ans=i;
        }
    }
    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",shuru,shes,ans,maxi);
}
return 0;
}
