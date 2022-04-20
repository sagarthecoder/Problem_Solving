#include <bits/stdc++.h>
using namespace std;
char str[101][101];
struct data
{
    int i,j;
};
vector<data>v;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool seen[101][101];
int n,abal1,abal2;
void dfs(int x1,int y1)
{
    if(seen[x1][y1])return;
    seen[x1][y1]=1;
    for(int i=0;i<4;i++){
        int fx=x1+dx[i];
        int fy=y1+dy[i];
        if(fx>=0 && fx<n && fy>=0 && fy<n && seen[fx][fy]==0 && (fx!=abal1 || fy!=abal2) && str[fx][fy]!='.' )dfs(fx,fy);
    }
}
int main()
{
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)
    {
        cin>>n;
        memset(seen,false,sizeof(seen));
        int cnt=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>str[i][j];
            if(str[i][j]=='x')v.push_back({i,j});
        }
        int sz=v.size();
        for(int i=0;i<sz;i++){
            int x1=v[i].i;
            int y1=v[i].j;
            if(seen[x1][y1]==0){
                abal1=x1,abal2=y1;
                dfs(x1,y1);
                cnt++;
            }
        }
        cout<<"Case "<<a<<": "<<cnt<<endl;
        v.clear();

    }
    return 0;
}
