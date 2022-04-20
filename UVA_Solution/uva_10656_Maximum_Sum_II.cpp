#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    while(true)
    {
        int x;vector<int>v;
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(x>0)v.push_back(x);
        }
        int sz=v.size();
        if(!sz)printf("0\n");
        else
        {
            for(int i=0;i<sz;i++)
            {
                if(i>0)printf(" ");
                printf("%d",v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
