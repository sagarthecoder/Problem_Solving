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
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
int ara[1000002];
bool ok[1000002];
int bsearch(int x,int y)
{
    int low=0,high=y-1;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(ara[mid]==x)return mid;
        if(ara[mid]<x)low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int m,n;
    while(true)
    {
        int x,i=0,j,cnt=0;
        memset(ok,false,sizeof(ok));
        scanf("%d %d",&m,&n);
        if(m==0 && n==0)break;
        if(m==0 || n==0)
        {
            for(int i=0;i<m;i++)scanf("%d",&x);
            for(int i=0;i<n;i++)scanf("%d",&x);
            printf("0\n");
        }
        else{
        for(i=0;i<m;i++){
            scanf("%d",&x);
            ara[i]=x;
        }
        sort(ara,ara+i);
        for( j=0;j<n;j++){
            scanf("%d",&x);
           int ck=bsearch(x,i);
           if(ck!=-1 && ok[ck]==false){cnt++;ok[ck]=true;}

            //if(ck)cnt++;
        }
        printf("%d\n",cnt);
        }
    }
    return 0;
}
