#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dx[]={10,100,1000,10000};
vector<int>v[5];
int main()
{
    for(int i=0;i<=10000;i++){
        int gun=i*i;
        for(int j=0;j<4;j++)
        {
            int omg=(gun/dx[j])+(gun%dx[j]);
            if(omg==i)v[j].push_back(gun);
        }

    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int bhag=(n/2)-1;
        int sz=v[bhag].size();
        for(int i=0;i<sz;i++)
        {
            int num=v[bhag][i];
            int log=1;
            if(num!=0){
                log=log10(num)+1;
            }
            if(log<=n){
                int baki=n-log;
                for(int z=0;z<baki;z++)printf("0");
                printf("%d\n",num);
            }
        }
    }
    return 0;
}
