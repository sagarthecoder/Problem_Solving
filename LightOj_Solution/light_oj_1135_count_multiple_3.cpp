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
#define maxi 100005

struct data{
   int propagate,x,y,z;
}tree[4*maxi];
int ara[maxi];
int x1,c1,z1;
void segment(int node,int start,int finish)
{
    if(start==finish){tree[node].x=1;
    return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(start+finish)>>1;
    segment(left,start,mid);
    segment(right,mid+1,finish);
    tree[node].x=tree[left].x+tree[right].x;

}
void interchange(int node,int a,int b,int c)
{
    int u=a;
    int v=b;
    int w=c;
    tree[node].y=u;
    tree[node].z=v;
    tree[node].x=w;
    //cout<<"accha = "<<tree[node].x<<" "<<tree[node].y<<" "<<tree[node].z<<" "<<endl;
}
void interchange2(int a,int b,int c)
{
    int u=a;
    int v=b;
    int w=c;
    c1=u;
    z1=v;
    x1=w;
}
void update(int node,int start,int finish,int A,int B)
{
    if(start>B || finish<A)return;
    if(start>=A && finish<=B)
    {
        tree[node].propagate+=1;
        interchange(node,tree[node].x,tree[node].y,tree[node].z);
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(start+finish)>>1;
    update(left,start,mid,A,B);
    update(right,mid+1,finish,A,B);
    tree[node].x=tree[left].x+tree[right].x;
    tree[node].y=tree[left].y+tree[right].y;
    tree[node].z=tree[left].z+tree[right].z;
    if(tree[node].propagate%3==1)interchange(node,tree[node].x,tree[node].y,tree[node].z);
    else if(tree[node].propagate%3==2)
    {
        interchange(node,tree[node].x,tree[node].y,tree[node].z);
        interchange(node,tree[node].x,tree[node].y,tree[node].z);
    }
}
int query(int node,int start,int finish,int A,int B,int carry)
{
    x1=tree[node].x;
        c1=tree[node].y;
        z1=tree[node].z;
    if(start>B || finish<A)return 0;
    if(start>=A && finish<=B)
    {
        ///x1=tree[node].x;
       /// c1=tree[node].y;
       /// z1=tree[node].z;
        if(carry%3==1)interchange2(tree[node].x,tree[node].y,tree[node].z);
        else if(carry%3==2){
        interchange2(tree[node].x,tree[node].y,tree[node].z);
        interchange2(x1,c1,z1);
        }
        return x1;

    }
    int left=node<<1;
    int right=left+1;
    int mid=(start+finish)>>1;
    int p=query(left,start,mid,A,B,carry+tree[node].propagate);
    int q=query(right,mid+1,finish,A,B,carry+tree[node].propagate);
    return p+q;
}
int main()
{
    int n,q,A,B,ck,t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++){
    printf("Case %d:\n",a);
    memset(tree,0,sizeof(tree));
    memset(ara,0,sizeof(ara));
    scanf("%d %d",&n,&q);
    segment(1,0,n-1);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d %d",&ck,&A,&B);
        if(ck==0)update(1,0,n-1,A,B);
        else
        {
            int ans=query( 1,0,n-1,A,B,0);
            printf("%d\n",ans);
        }

    }
    }
    return 0;
}

