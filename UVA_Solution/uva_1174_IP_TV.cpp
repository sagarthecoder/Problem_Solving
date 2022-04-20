#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    string v1,v2;
    int w1;
};
map<string,string>bap;
bool comp(data u,data u1)
{
    return u.w1<u1.w1;
}
string bapke(string x)
{
    if(bap[x]==x)return x;
    return bap[x]=bapke(bap[x]);
}
int main()
{
   int n,m,t;scanf("%d",&t);
   for(int a=1;a<=t;a++)
   {
       scanf("%d %d",&n,&m);

       char x[20],y[20];
       ll res=0;
       int w,cnt=0;
       vector<data>v;
       map<string,int>seen;
       for(int i=0;i<m;i++)
       {
          scanf("%s%s%d",x,y,&w);
          v.push_back({x,y,w});
          if(seen[x]==0){
            bap[x]=x;seen[x]=1;
          }
          if(seen[y]==0){
                seen[y]=1;bap[y]=y;
          }
       }
       sort(v.begin(),v.end(),comp);
       for(int i=0;i<m;i++)
       {
           string A=bapke(v[i].v1);
           string B=bapke(v[i].v2);
           if(A!=B)
           {
               cnt++;
               res+=v[i].w1;
               bap[B]=A;
               if(cnt==n-1)break;

           }
       }

       printf("%lld\n",res);
       seen.clear();
       if(a!=t)printf("\n");
   }
   return 0;
}
