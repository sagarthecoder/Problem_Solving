#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int seen[3009]={0},x;
        int ara[n+2];
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        for(int i=0;i<n-1;i++){
            seen[abs(ara[i]-ara[i+1])]=1;
        }
        bool ck=false;
        for(int i=1;i<n;i++){
            if(seen[i]==0){
                ck=true;break;
            }
        }
        if(ck)printf("Not jolly\n");
        else printf("Jolly\n");
    }
    return 0;
}
