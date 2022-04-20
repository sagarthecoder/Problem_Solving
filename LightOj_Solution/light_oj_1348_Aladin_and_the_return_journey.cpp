#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll bap[30002][17];
ll seen[30002];
ll par[30002];
ll L[30002],val[30003];
vector<ll>v[30002];
ll sTime[30003],ETime[30004];
ll ara[60005],contain[60005],somoy=0;
ll tree[4*60005];
void dfs(ll x,ll p,ll level)
{
    if(seen[x])return;seen[x]=1;
    sTime[x]=somoy;ara[somoy]=x;contain[somoy]=val[x];
    somoy++;
    par[x]=p;
    L[x]=level;
    for(ll i=0;i<v[x].size();i++)dfs(v[x][i],x,level+1);
    ara[somoy]=x;contain[somoy]=-val[x];
    ETime[x]=somoy;somoy++;
}
void LCAcount(ll n)
{
    memset(bap,-1,sizeof(bap));
    for(ll i =0;i<n;i++)bap[i][0]=par[i];

    for(ll i=1;(1ll<<i)<n;i++)
        for(ll j=0;j<n;j++){
                if(bap[j][i-1]==-1)continue;
                bap[j][i]=bap[bap[j][i-1]][i-1];
        }
}
ll go(ll n,ll p,ll q)
{
    ll log;
    if(L[p]<L[q])swap(p,q);
    if(L[p]==0)log=0;
    else
    log=log2(L[p]);
    for(ll i=log;i>=0;i--){
        if(L[p]-(1<<i)>=L[q])p=bap[p][i];
    }
    if(p==q)return p;
    for(ll i=log;i>=0;i--)
    {
        if(bap[p][i]!=-1 && bap[p][i]!=bap[q][i])p=bap[p][i],q=bap[q][i];
    }
    return par[p];
}

void build(ll node,ll i,ll j)
{
    if(i==j){
        tree[node]=contain[i];return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(i+j)>>1;
    build(left,i,mid);
    build(right,mid+1,j);
    tree[node]=tree[left]+tree[right];
}
ll query(ll node,ll i,ll j,ll q1,ll q2)
{
    if(i>q2 || j<q1)return 0;
    if(i>=q1 && j<=q2)return tree[node];
    ll left=node<<1;
    ll right=left+1;
    ll mid=(i+j)>>1;
    return query(left,i,mid,q1,q2)+query(right,mid+1,j,q1,q2);


}
void update(ll node,ll i,ll j,ll pos,ll value)
{
    if(i==j && i==pos){
        contain[pos]+=value;
        tree[node]+=value;return;
    }
    if(i>pos || j<pos)return;
    ll left=node<<1;
    ll right=left+1;
    ll mid=(i+j)>>1;
    update(left,i,mid,pos,value);
    update(right,mid+1,j,pos,value);
    tree[node]=tree[left]+tree[right];
}
int main()
{

//#ifdef LOCAL
//            freopen("input.txt","r",stdin);
//            freopen("output.txt","w",stdout);
//#endif

    ll t,n;scanf("%lld",&t);
    for(ll a=1;a<=t;a++)
    {
        ll x,y,q;scanf("%lld",&n);
        somoy=0;
        ll  ck;
        for(ll i=0;i<n;i++){scanf("%lld",&val[i]);
        }
        for(ll i=0;i<n-1;i++){
            scanf("%lld %lld",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(0,0,0);
        LCAcount(n);
        build(1,0,n+n-1);
        scanf("%lld",&q);
        printf("Case %lld:\n",a);
        while(q--)
        {
            scanf("%lld %lld %lld",&ck,&x,&y);
            if(ck==0){
                ll ans1=query(1,0,n+n-1,sTime[0],sTime[x]);
                ll ans2=query(1,0,n+n-1,sTime[0],sTime[y]);
                ll getLCA=go(n,x,y);
                ll LCAxy=2*query(1,0,n+n-1,sTime[0],sTime[getLCA]);
                ll res=ans1+ans2-LCAxy+contain[sTime[getLCA]];
                printf("%lld\n",res);
            }
            else{
                ll bad=y-contain[sTime[x]];
                update(1,0,n+n-1,sTime[x],bad);
                update(1,0,n+n-1,ETime[x],-bad);
            }

        }
        for(ll i=0;i<=n;i++){v[i].clear();
        seen[i]=0;
        }
    }
    return 0;
}
