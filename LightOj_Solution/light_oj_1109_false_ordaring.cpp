#include <bits/stdc++.h>
using  namespace std;
struct data
{
    int num,nod;
    /*bool comp(data a,data b)
    {
        return a.num>b.num;
    }*/
};
bool comp(data a,data b)
{
    if(a.nod==b.nod)return a.num>b.num;
    else
    return a.nod<b.nod;
}
vector<data>sr;
void go()
{
    int exponent,num_of_divisors,num;
    for(int j=1;j<=1000;j++)
    {
        num=j,num_of_divisors=1;
        for(int i=2;i*i<=num;i++)
         {
             exponent=0;
             while(num%i==0)
             {
                 exponent++;
                 num=num/i;
             }
             num_of_divisors*=(exponent+1);
         }
         if(num>1)num_of_divisors*=(2);
         sr.push_back({j,num_of_divisors});
    }
    sort(sr.begin(),sr.end(),comp);
}
int main()
{
    int n,t;
    scanf("%d",&t);
    go();
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        int res=sr[n-1].num;
        printf("Case %d: %d\n",i,res);

    }
    return 0;
}
