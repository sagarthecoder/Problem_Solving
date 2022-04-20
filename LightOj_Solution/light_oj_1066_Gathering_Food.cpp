#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct data
{
    char ch;
    int pos1,pos2;
};
struct data2
{
    int x,y;
};
char str[13][13];
int dx[]={1,-1,0,0},n;
int dy[]={0,0,-1,1};
int seen[12][12];
bool comp(data u,data u1)
{
    return u.ch<u1.ch;
}
int bfs(int x,int y,char ch)
{
    queue<data2>q;
    q.push({x,y});
    while(!q.empty())
    {
        data2 t=q.front();
        for(int i=0;i<4;i++)
        {
            int fx=t.x+dx[i];
            int fy=t.y+dy[i];
            if(fx>=0 && fy>=0 && fx<n && fy<n &&(fx!=x || fy!=y))
            {
                if(str[fx][fy]!='#' && seen[fx][fy]==0 && (str[fx][fy]=='.' || str[fx][fy]==ch)){
                    seen[fx][fy]=seen[t.x][t.y]+1;
                    //cout<<"x = "<<fx<<"  y =  "<<fy<<endl;
                    if(str[fx][fy]==ch){
                            str[x][y]='.';
                            return seen[fx][fy];
                    }
                    q.push({fx,fy});
                }
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
   int t;scanf("%d",&t);
   for(int a=1;a<=t;a++)
   {
       scanf("%d",&n);
       vector<data>v;
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
        scanf(" %c",&str[i][j]);
        if(str[i][j]!='.' && str[i][j]!='#')
         v.push_back({str[i][j],i,j});
       }
       printf("Case %d: ",a);
       sort(v.begin(),v.end(),comp);
       int sz=v.size();
       if(sz==1){
        printf("0\n");continue;
       }
       int cnt=0;
       for(int i=0;i<sz-1;i++)
       {
           memset(seen,0,sizeof(seen));
           //cout<<"v = "<<v[i].ch<<endl;
           int ans=bfs(v[i].pos1,v[i].pos2,v[i+1].ch);
           if(ans==-1){
            cnt=-1;break;
           }
           cnt+=ans;
       }
       if(cnt==-1){
        printf("Impossible\n");
       }
       else printf("%d\n",cnt);
   }
   return 0;

}
