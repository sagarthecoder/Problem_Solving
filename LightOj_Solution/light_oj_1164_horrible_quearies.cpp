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
#define mx 100005
struct data
{
    ll value,propagate;
}tree[mx*4];
 ll ara[mx];
void segment(ll node,ll start,ll finish)
{
    if(start==finish){
            tree[node].value=ara[start];
    return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(start+finish)>>1;
    segment(left,start,mid);
    segment(right,mid+1,finish);
    tree[node].value=tree[left].value+tree[right].value;
    //cout<<"Node "<<node<<" :"<<tree[node].value<<endl;

}
void update(ll node,ll start,ll finish,ll q1,ll q2,ll add)
{
    if(start>q2 || finish<q1)return;
    if(start>=q1 && finish<=q2)
    {
        tree[node].value+=((finish-start+1)*add);
        tree[node].propagate+=add;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(start+finish)>>1;
    update(left,start,mid,q1,q2,add);
    update(right,mid+1,finish,q1,q2,add);
    tree[node].value=tree[left].value+tree[right].value+((tree[node].propagate)*(finish-start+1));
}
ll query(ll node,ll start,ll finish,ll q1,ll q2,ll carry)
{
    if(start>q2 || finish<q1)return 0;
    if(start>=q1 && finish<=q2)
    {
        return tree[node].value+((carry)*(finish-start+1));
    }
    ll left=node<<1;
   ll right=left+1;
   ll mid=(start+finish)>>1;
    ll x=query(left,start,mid,q1,q2,carry+tree[node].propagate);
    ll y=query(right,mid+1,finish,q1,q2,carry+tree[node].propagate);
    return x+y;
}
int main()
{
    ll t,n,q,ck,x,y,v;
    scanf("%lld",&t);
    for(ll a=1;a<=t;a++)
    {
        printf("Case %lld:\n",a);
        memset(ara,0,sizeof(ara));
        memset(tree,0,sizeof(tree));
        scanf("%lld %lld",&n,&q);
        segment(1,0,n-1);
        for(ll i=0;i<q;i++)
        {
            scanf("%lld",&ck);
            if(ck==0)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                scanf("%lld %lld",&x,&y);
               ll ans=query(1,0,n-1,x,y,0);
                printf("%lld\n",ans);
            }
        }

    }
    return 0;
}
