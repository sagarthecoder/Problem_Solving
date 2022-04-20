#include <cstdio>
#include <iostream>
using namespace std;
int ara[50009];
int main()
{
    int n,i,res,sum,t,j,x,mini,maxi,ck;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ara[i]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        j=0,ck=0;
        mini=x;
        maxi=x;
        for(i=0;i<n;i++)
        {
           if(ara[0]>=x)
           {
               mini=x;
               ck=1;
               break;
           }
           else if(ara[i]>=x)
           {
               mini=ara[i-1];
               ck=2;
               j=i;
               break;
           }

        }
        if(ck==0)
            printf("%d ",ara[n-1]);
        else if(mini==x)
            printf("X ");
        else
            printf("%d ",mini);
        for(i=j;i<n;i++)
        {
            if(ara[i]>maxi)
            {
                maxi=ara[i];
                break;
            }

        }
        if(maxi==x)
            printf("X\n");
        else
            printf("%d\n",maxi);
    }
    return 0;
}
