#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define INF 10000000
using namespace std;
struct data
{
   int x,y;
};
bool ara[1001][1001];
int seen[1000+1][1000+1];
int r,c,cnt,source1, source2;
void bfs(int s1,int s2,int d1,int d2)
{
    queue<data>q;
    int dis;
    bool ck=false;
    ///map<int,map<int,int> >seen;
    memset(seen,0,sizeof(seen));
    q.push({s1,s2});
    while(!q.empty())
    {
        data top=q.front();
        for(int i=0;i<4;i++)
        {

            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            int fx=top.x+dx[i];
            int fy=top.y+dy[i];
            if(fx>=0 && fy>=0 && fx<r && fy<c && seen[fx][fy]==0 && (fx!=source1 || fy!=source2) && ara[fx][fy]!=true && seen[fx][fy]==0)
            {
                ///if(ara[fx][fy]!=true && seen[fx][fy]==0)
                ///{
                    seen[fx][fy]=seen[top.x][top.y]+1;
                     dis=seen[fx][fy];
                    if(fx==d1 && fy==d2)
                    {
                        ck=true;
                        ///cout<<dis<<endl;
                        printf("%d\n",dis);
                        break;
                    }
                    q.push({fx,fy});

                ///}
            }
        }
        q.pop();
        if(ck==true)break;
    }
    //return dis;

}
int main()
{
    int g,rowName,bomb,colName,s1,s2,d1,d2;
    while(true)
    {
        scanf("%d %d",&r,&c);
        if(r==0 && c==0)break;
        ///cin>>g;
        scanf("%d",&g);
        cnt=0;
        memset(ara,false,sizeof(ara));
        for(int a=0;a<g;a++)
        {
            ///cin>>rowName>>bomb;
            scanf("%d %d",&rowName,&bomb);
            for(int i=0;i<bomb;i++)
            {
                ///cin>>colName;
                scanf("%d",&colName);
                ara[rowName][colName]=1;
            }
        }
        ///cin>>s1>>s2;
        scanf("%d %d %d %d",&s1,&s2,&d1,&d2);
        source1=s1;
        source2=s2;
        ///cin>>d1>>d2;
        if(s1==d1 && s2==d2)printf("0\n");
        else
        bfs(s1,s2,d1,d2);
        //cout<<res<<endl;

    }
    return 0;
}

