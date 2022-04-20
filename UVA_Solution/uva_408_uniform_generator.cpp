#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int GCD(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return GCD(b,a%b);
}
void rules(int res)
{
    int line;
    if(res<=9)
        line=8;
     else    if(res<=99)
            line=7;
        else if(res<=999)
            line=6;
        else if(res<=9999)
            line=5;
        else if(res<=99999)
            line=4;
        else if(res<=999999)
            line=3;
        else if(res<=9999999)
            line=2;
        else
            line=1;
        for(int i=1;i<=line+1;i++)
            printf(" ");
}
int main()
{
    int m,n,res,line,ck;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        int a=m;
        int b=n;
        if(n>m)
            swap(m,n);
        res=GCD(m,n);
        if(res==1)
            ck=0;
            else
            ck=1;
        rules(a);
        printf("%d",a);
        rules(b);
        printf("%d",b);
        if(ck==0)
            printf("    Good Choice\n");
        else
            printf("    Bad Choice\n");
            printf("\n");

    }
    return 0;

}
