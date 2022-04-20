#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
       int n,m;scanf("%d %d",&n,&m);
       ll ara[n+2];
       for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
       while(m--)
       {
           char ch;int m1,m2;
           scanf(" %c",&ch);
           if(ch=='S'){
            scanf("%d",&m1);
            for(int i=0;i<n;i++)ara[i]+=m1;
           }
           else if(ch=='M'){
            scanf("%d",&m1);
            for(int i=0;i<n;i++)ara[i]*=m1;
           }
           else if(ch=='D'){
            scanf("%d",&m1);
            for(int i=0;i<n;i++)ara[i]/=m1;
           }
           else if(ch=='R'){
            int bhag=n/2;
            for(int i=0;i<bhag;i++)swap(ara[i],ara[n-1-i]);
           }
           else{
            scanf("%d %d",&m1,&m2);
            swap(ara[m1],ara[m2]);
           }
       }
       printf("Case %d:\n",a);
       bool ck=false;
       for(int i=0;i<n;i++){
        if(ck)printf(" ");ck=true;
        printf("%lld",ara[i]);
       }
       printf("\n");
    }
    return 0;
}
