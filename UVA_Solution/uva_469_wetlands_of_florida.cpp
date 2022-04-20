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
map<int, map<int,int> >seen;
vector<int>rupa;
vector<int>love;
vector<int>sagar;
int counting=0,type=0,length,take1,take2;
void dfs(int x,int y)
{
    if(seen[x][y]==0)
        return;
    int dx[]= {1,-1,0,0,1,1,-1,-1};
    int dy[]= {0,0,-1,1,-1,1,-1,1};
    for(int i=0; i<8; i++)
    {
        int fx=x+dx[i];
        int fy=y+dy[i];
        if(fx>=0 && fy>=0 && fy<length && fx<type && (fx!=take1 || fy!=take2))
        {
            if(seen[fx][fy]==2)
            {
                rupa.push_back(fx);
                love.push_back(fy);
                counting++;
                seen[fx][fy]=1;
                dfs(fx,fy);
            }
        }

    }
}
int main()
{
    int i,j,sum,res,taken,n,t,k;
    char ch;
    string x,y;
    cin>>t;
    getline(cin,y);
    getline(cin,y);
    for(k=1;k<=t;k++)
    {
        string x,y;
        j=0,res=0,n=1;
        seen.clear();
        while(1)
        {
            getline(cin,x);
            if(x.empty()==true)
                break;
            int len=x.size();
            if(x[0]=='L' || x[0]=='W')
            {
                type++;
                length=len;
                for(i=0; i<len; i++)
                {
                    if(x[i]=='W')
                    {
                        seen[j][i]=2;
                    }
                }
                j++;
            }
            else
            {
                for(i=0; i<len; i++)
                {
                    if(i==len-1)
                    {
                        res=(res*n) +(x[i]-'0');
                        sagar.push_back(res);
                        res=0;
                        n=1;
                    }
                    else if(x[i]!=' ')
                    {
                        res=(res*n) +(x[i]-'0');
                        n=10;
                    }

                    else
                    {
                        sagar.push_back(res);
                        n=1;
                        res=0;
                    }
                }
                if(seen[sagar[0]-1][sagar[1]-1]!=2){
                    cout<<0<<endl;
                }
                else
                {
                    take1=sagar[0]-1,take2=sagar[1]-1;
                    dfs(sagar[0]-1,sagar[1]-1);
                    cout<<counting+1<<endl;
                    for(i=0; i<rupa.size(); i++)
                    {
                        int w=rupa[i];
                        int c=love[i];
                        seen[w][c]=2;
                    }
                    rupa.clear();
                    love.clear();
                }
                sagar.clear();
                take1=0,take2=0;
                counting=0;
            }
        }
        if(k!=t){
        cout<<endl;

    }
    return 0;
}
