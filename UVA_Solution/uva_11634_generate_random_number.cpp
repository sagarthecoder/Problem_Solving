#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool seen[10000];
ll cnt=0;
ll go(int n)
{
   while(true)
   {
       int sq=n*n;
       ///cout<<"n = "<<n<<endl;
       int len=log10(sq)+1;
       if(len<3){
        n=0;
        if(seen[n]==1)break;
        seen[n]=1;
       }
       else
       {
           sq=sq/10;
           sq=sq/10;
           vector<int>v;
           int ok=0;
           while(true)
           {
               int rem=sq%10;
               v.push_back(rem);
               ok++;
               if(ok==4)break;
               if(sq/10==0)break;
               sq=sq/10;
           }
           int value;
           for(int i=ok-1;i>=0;i--)
           {
               if(i==ok-1)value=v[i];
               else
                value=(value*10)+v[i];
           }
           n=value;
           if(seen[n]==1)break;
           seen[n]=1;
       }
       cnt++;
       ///if(cnt==12)break;
   }
   return cnt;
}
int main()
{

   int n;
   while(true)
   {
       scanf("%d",&n);
       memset(seen,0,sizeof(seen));
       seen[n]=1;
       if(n==0)break;
       cnt=1;
       printf("%lld\n",go(n));
   }
   return 0;
}
