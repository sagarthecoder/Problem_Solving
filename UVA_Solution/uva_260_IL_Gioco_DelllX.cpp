#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0,-1,1};
int dy[]={0,0,-1,1,-1,1};
char str[202][202];
int seen[202][202],n;
bool ck;
int col,row;
void dfs(int x,int y)
{
    if(ck)return;
    if(seen[x][y])return ;
    seen[x][y]=1;
    for(int i=0;i<6;i++)
    {
        int fx=x+dx[i];
        int fy=y+dy[i];

        if(fx>=0 && fy>=0 && fx<n && fy<n &&(fx!=row || fy!=col))
        {
            if(str[fx][fy]=='w' && seen[fx][fy]==0)
            {
                ///cout<<"fx = "<<fx<<endl;
                ///cout<<"fy = "<<fy<<endl;
                if(fy==n-1){
                    ck=true;
                    break;
                }
                dfs(fx,fy);
            }
        }
    }
}
int main()
{

    int a=1;
    while(true)
    {
        cin>>n;if(n==0)break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){cin>>str[i][j];
            seen[i][j]=0;
            }
            int s=0;
            ck=false;
        for(int j=0;j<n;j++){
            if(str[j][s]=='w' && seen[j][s]==0){
               col=s,row=j;
               dfs(j,s);
               if(ck){
                cout<<a<<" W"<<endl;
                break;
               }
            }
        }
        if(!ck)cout<<a<<" B"<<endl;
        a++;

    }
    return 0;
}
