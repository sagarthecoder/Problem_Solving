#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    bool left,right;
};

int main()
{
  int t;scanf("%d",&t);
  for(int a=1;a<=t;a++)
  {
      int n,x,y,c,one=0,two=0;scanf("%d",&n);
      data seen[n+1];
      for(int i=0;i<=n;i++)seen[i].left=0,seen[i].right=0;
      for(int i=0;i<n;i++)
      {
          scanf("%d %d %d",&x,&y,&c);
          if(seen[x].left==0 && seen[y].right==0){
            one+=c;
            seen[x].left=1,seen[y].right=1;
          }
          else
          {
              two+=c;
              seen[y].left=1,seen[x].right=1;
          }
      }
      two=min(one,two);
      printf("Case %d: %d\n",a,two);
  }
  return 0;
}
