#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
bool status[101];
void siv()
{
    int N=100;
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2) status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=N; j+=i) status[j]=1;
        }
    }
    status[1]=1;

}
int main()
{
    int t,n;
    siv();
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&n);
        bool ck=false;
        printf("Case %d: %d = ",i,n);
        for(int j=2; j<=n; j++)
        {
            if(status[j]==0)
            {

                int taken=j;
                int total=0;
                if(ck==true)printf(" * ");
                while(taken<=n)
                {
                    total=total+(n/taken);
                    taken=j*taken;
                }
                //cout<<total<<endl;
                printf("%d (%d)",j,total);
                ck=true;
            }
        }
        printf("\n");
    }
    return 0;
}
