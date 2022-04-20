#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
long long int status[20000003];
vector<long long int>v;
vector<pair<long long int,long long int> >v1;

void siv()
{
    long long int   N=20000000;
    long long int sq=sqrt(N);
    for(long long int i=4; i<=N; i+=2) status[i]=1;
    for(long long int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(long long int j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
void twin()
{
    for(long long int i=2;i<=20000000;i++)
    {
        if(status[i]==0 && status[i+2]==0)
        {
            v1.push_back(make_pair(i,i+2));

        }
    }

}
int main()
{
    long long int n,i,j;
    siv();
    twin();
    while(scanf("%lld",&n)!=EOF){
    printf("(%lld, %lld)\n",v1[n-1].first,v1[n-1].second);
    }
    return 0;
}

