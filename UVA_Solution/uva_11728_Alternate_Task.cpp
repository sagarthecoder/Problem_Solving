#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool status[1005];
int prime[1005];
int p=0;
int ara[500508];
void siv()
{

    status[1]=1;
    status[0]=1;
    int M=1002;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime[p]=i;
            for(int j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
            p++;
        }
    }
}
int power(int a,int n)
{
    if(n==0)return 1;
    if(n==1)return a;
    int ans=power(a,n/2);
    if(n%2==0)return ans*ans;
    else return ans*ans*a;

}
int SOD(int num)
{
        int sum_of_divisors=1,exponent;
         for(int i=0;prime[i]*prime[i]<=num;i++)
         {
             exponent=0;
             while(num%prime[i]==0)
             {
                 exponent++;
                 num=num/prime[i];
                /// cout<<"num"<<endl;
             }
             sum_of_divisors*=(power(prime[i],exponent+1)-1)/(prime[i]-1);
         }
         if(num>1)sum_of_divisors*=(power(num,2)-1)/(num-1);
         return sum_of_divisors;
}

int main()
{
    siv();
    for(int i=1;i<=1000;i++){
        int ans=SOD(i);
        ara[ans]=i;
    }
    int n,a=1;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)break;
        printf("Case %d: ",a);
        if(ara[n]==0)printf("-1\n");
        else printf("%d\n",ara[n]);
        a++;

    }
    return 0;
}
