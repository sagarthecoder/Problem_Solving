#include<cstdio>
#include<sstream>
#include<cstdlib>
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
#define mx 10000005
#define pii pair<int,int>
#define mod 100000007
#define inf 0x3f3f3f3f3f3f3f
map<int,int>seen;
int ck;
int cost[10][10];
int value(string s)
{
    if(s[0]=='a')return 1;
    else if(s[0]=='b')return 2;
    else if(s[0]=='c')return 3;
    else if(s[0]=='d')return 4;
    else if(s[0]=='e')return 5;
    else if(s[0]=='f')return 6;
    else if(s[0]=='g')return 7;
    else
        return 8;
}
void bfs(int sx,int sy,int dx,int dy,string u,string v)
{
    int fx[]={2,2,1,1,-1,-1,-2,-2};
    int fy[]={-1,1,-2,2,-2,2,-1,1};
    ck=0;
    memset(cost,0,sizeof(cost));
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty()==true)
    {
        pii top=q.front();
        for(int i=0;i<8;i++)
        {
            int f1=top.first+fx[i];
            int f2=top.second+fy[i];
            if(f1>=1 && f1<=8 && f2>=1 && f2<=8)
            {

                cost[f1][f2]=cost[top.first][top.second]+1;
                if(f1==dx && f2==dy)
                {
                    ck=1;
                    cout<<"To get from "<<u<<" to "<<v<<" takes "<<cost[f1][f2]<<" knight moves."<<endl;
                    break;
                }
              q.push(pii(f1,f2));


            }
        }
        if(ck==1)
            break;
        q.pop();
    }
}
int main()
{
   int i,j,n,res,x1,y1,x2,y2,num1,num2;
   string  u, v;
   while(cin>>u>>v)
   {
       y1=value(u);
       y2=value(v);
       x1=u[1]-'0';
       x2=v[1]-'0';
       if(u==v)
        cout<<"To get from "<<u<<" to "<<v<<" takes 0 knight moves."<<endl;
       else{
       bfs(x1,y1,x2,y2,u,v);
       }

   }
   return 0;
}
