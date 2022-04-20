#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ll long long
#define vec vector<int>
#define vec2 vector<data>
using namespace std;
struct data
{
    int x,y,z;
};
bool comp(data u,data u1)
{
    if(u.x==u1.x)return u.y<u1.y;
    return u.x<u1.x;
}
int main()
{
    int t;sf("%d",&t);
    while(t--)
    {
        int A,B,C;sf("%d %d %d",&A,&B,&C);
        vec2 v;
        int sq=sqrt(C)+1;
        for(int i=1;i<=sq;i++)
            for(int j=i+1;j<=sq;j++)
            for(int k=j+1;k<=sq;k++)
        {
            if((i+j+k==A) && (i*j*k==B) && (((i*i)+(j*j)+(k*k))==C) ){
                int ara[3];
                ara[0]=i,ara[1]=j,ara[2]=k;
                sort(ara,ara+3);
                v.push_back({ara[0],ara[1],ara[2]});

            }
        }
        for(int i=-1;i>=(-1*sq);i--)
            for(int j=i-1;j>=(-1*sq);j--)
            for(int k=1;k<=sq;k++)
        {
            ///cout<<"i ,j ,k= "<<i<<" "<<j<< " "<<k<<endl;
            if((i+j+k==A) && (i*j*k==B) && (((i*i)+(j*j)+(k*k))==C) ){
                int ara[3];
                ara[0]=i,ara[1]=j,ara[2]=k;
                sort(ara,ara+3);
                v.push_back({ara[0],ara[1],ara[2]});

            }
        }
        sort(v.begin(),v.end(),comp);
        int sz=v.size();
        if(sz==0)pf("No solution.\n");
        else {
           pf("%d %d %d\n",v[0].x,v[0].y,v[0].z);
        }
    }
    return 0;
}
