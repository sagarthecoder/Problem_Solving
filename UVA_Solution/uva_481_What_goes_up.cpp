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
#include <unordered_map>
#define ll long long int
#define mx 1000000
int n,i=0,ara[1000000],ans[1000000],LIS[1000000],temp[1000000],res[1000000],low=0,len=0;
using namespace std;
int main()
{
    ///memset(res,-1,sizeof(res));
    while(scanf("%d",&n)!=EOF)
    {
        ara[i]=n;
        if(i==0){
           LIS[len]=ara[i];
           temp[i]=i;
           res[i]=-1;
        }
        else if(ara[i]>LIS[len]){
            len++;
            LIS[len]=ara[i];
            temp[len]=i;
            res[i]=temp[len-1];
        }
        else
        {
            low=lower_bound(LIS,LIS+len+1,n)-LIS;
            LIS[low]=ara[i];
            temp[low]=i;
            if(low==0)res[i]=-1;
            else res[i]=temp[low-1];

        }
        i++;
    }
    printf("%d\n",len+1);
    printf("-\n");
    int index=temp[len],k=0;
    ans[0]=ara[index];
    while(res[index]!=-1)
    {
        k++;ans[k]=ara[res[index]];
        index=res[index];
    }
    for(int u=len;u>=0;u--)printf("%d\n",ans[u]);
    return 0;

}
