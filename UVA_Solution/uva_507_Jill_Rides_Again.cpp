#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int b,cnt=0,L=0,x,k1=1,M=1,k2;scanf("%d",&b);
        int maxi=INT_MIN,mx=0;
        for(int i=1;i<b;i++)
        {
           scanf("%d",&x);
           L++;
           cnt+=x;
           ///maxi=max(cnt,maxi);
           if(cnt<0){
            cnt=0;
            M=i+1;
            L=0;
           }
           else if(cnt==maxi && L>mx)
           {
               mx=L,k2=i+1,k1=M;
           }
           else if(cnt>maxi)
           {
               mx=L,k2=i+1,k1=M;
               maxi=cnt;
           }
        }
        if(maxi<=0)printf("Route %d has no nice parts\n",a);
        else
        printf("The nicest part of route %d is between stops %d and %d\n",a,k1,k2);
    }
    return 0;
}
