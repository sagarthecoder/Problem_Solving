#include <bits/stdc++.h>
using namespace std;
char str[50][50];
///vector<data>v;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool seen[25][25];
char land;
int n,abal1,abal2,m,cnt;
void dfs(int x1,int y1)
{

    if(seen[x1][y1])return;
    seen[x1][y1]=1;
    if(y1==0 && str[x1][y1]==land && str[x1][m-1]==land && seen[x1][m-1]==0)dfs(x1,m-1);
    else if(y1==m-1 && str[x1][y1]==land && str[x1][0]==land && seen[x1][0]==0)dfs(x1,0);
    //seen[x1][y1]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int fx=x1+dx[i];
        int fy=y1+dy[i];
        if(fx>=0 && fx<n && fy>=0 && fy<m && seen[fx][fy]==0 && (fx!=abal1 || fy!=abal2) && str[fx][fy]==land )dfs(fx,fy);
    }
}
int main()
{
    int t;
    bool ok=false;
    while(cin>>n>>m){
        int x1,y1;

        ///if(ok)cout<<endl;
        ok=true;
        memset(seen,false,sizeof(seen));
         cnt=0;
         int res=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>str[i][j];
            ///if(str[i][j]=='x')v.push_back({i,j});
        }
        ///int sz=v.size();
        cin>>x1>>y1;
        land=str[x1][y1];
        abal1=x1,abal2=y1;
        dfs(x1,y1);
        ///cout<<"cnt1= "<<cnt<<endl;
        cnt=0;
        ///land=str[x1][y1];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(seen[i][j]==0 && str[i][j]==land){
                cnt=0;
                abal1=i,abal2=j;
                dfs(i,j);
               ///cout<<"cnt = "<<cnt<<endl;
                res=max(res,cnt);
            }
        }
        cout<<res<<endl;
        }
    return 0;
}
