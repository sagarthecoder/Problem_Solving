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
#define ll long long
#define sf scanf
#define pf printf
#define pb push_back
using namespace std;

int lazy[100000*4];
int cnt=0;
char x[100009];
void query(int node,int i,int j,int rng1,int rng2)
{
    if(i>=rng1 && j<=rng2){
        lazy[node]+=1;
        return;
    }
    ///cout<<"wow "<<endl;
    if(i>rng2 || j<rng1)return;
    int mid=(i+j)>>1;
    int left=node<<1;
    int right=left+1;
    query(left,i,mid,rng1,rng2);
    query(right,mid+1,j,rng1,rng2);

}
void  ans(int node,int i,int j,int point)
{
   if(i>point || j<point)return;
    if(i>=point && j<=point){
    cnt+=lazy[node];
    return;
   }
   /*if(i==j){
        //cnt+=lazy[node];
        return;
   }*/
   ///cout<<" cnt "<<cnt<<endl;
   ///if(i<0 || j<rng1)return;
   ///cout<<"wow "<<endl;
   cnt+=lazy[node];
   int mid=(i+j)>>1;
   int left=node<<1;
   int right=left+1;
    ans(left,i,mid,point);
    ans(right,mid+1,j,point);
}
int main()
{
    char ch;
    int t,q,shuru,shes;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int len,point;scanf("%s",x);
        memset(lazy,0,sizeof(lazy));
        len=strlen(x);
        scanf("%d",&q);
        printf("Case %d:\n",a);
        ///cout<<"Case "<<a<<":"<<endl;
        for(int i=0;i<q;i++){
            scanf(" %c",&ch);
            if(ch=='I'){
                scanf("%d %d",&shuru,&shes);
                query(1,0,len-1,shuru-1,shes-1);
            }
            else{
                scanf("%d",&point);
                cnt=0;
                ans(1,0,len-1,point-1);
                if(cnt%2==0)printf("%c\n",x[point-1]);
                else
                {
                    if(x[point-1]=='1')printf("0\n");
                    else printf("1\n");
                }
            }
        }
    }
    return 0;
}

