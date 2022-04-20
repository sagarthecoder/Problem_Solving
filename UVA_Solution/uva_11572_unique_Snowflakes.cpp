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
int pos[10000002];
int main()
{
    int t,n,x,res;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d",&n);int maxi=0,res=0,i;
        map<int,int>seen;
       for( i=1;i<=n;i++){
        scanf("%d",&x);
        pos[i]=seen[x];seen[x]=i;
       }
        int prev=1;
        for( i=1;i<=n;i++)
        {
            if(pos[i]>=prev){
                maxi=max(maxi,i-prev);
                prev=pos[i]+1;
            }
        }
        maxi=max(maxi,i-prev);
        printf("%d\n",maxi);
    }
    return 0;
    /*
    7
    132
    132
    123
    132
    123
    144
    566
*/
}
