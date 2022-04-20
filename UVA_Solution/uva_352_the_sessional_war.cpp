#include <bits/stdc++.h>
using namespace std;
char  str[30][30];
bool seen[30][30];
int n,row,col;
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,-1,1,-1,1,-1,1};
void dfs(int x,int y)
{
    if(seen[x][y])return;
    ///cout<<"fx = "<<x<<", fy = "<<y<<endl;
    seen[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int fx=x+dx[i];
        int fy=y+dy[i];
        if(fx>=0 && fy>=0 && fx<n && fy<n && (fx!=row || fy!=col))
        {
            if(str[fx][fy]=='1' && seen[fx][fy]==0){
                    ///cout<<"fx = "<<fx<<", fy = "<<fy<<endl;
                     //cout<<"fy = "<<fy<<endl;
                    dfs(fx,fy);
            }
        }
    }
}
int main()
{

    int a=1;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){cin>>str[i][j];
            seen[i][j]=0;
            }
            int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            if(str[i][j]=='1' & seen[i][j]==0){
                row=i,col=j;
                dfs(i,j);
                ///cout<<endl;
                cnt++;
            }
        }
        cout<<"Image number "<<a<<" contains "<<cnt<<" war eagles."<<endl;
        a++;
    }
    return 0;
}
