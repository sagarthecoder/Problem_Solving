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
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,x,y;scanf("%d",&n);
        vector<int>v[20009];
        bool seen[20009]={0};
       /// memset(seen,0,sizeof(seen));
        int ara[20009]={0};
        int word[20009];
       /// memset(word,0,sizeof(word));
        vector<int>taken;
        while(n--)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            if(seen[x]==0){
                seen[x]=1;taken.push_back(x);
            }
            if(seen[y]==0){
                seen[y]=1;taken.push_back(y);
            }
        }
        int sz=taken.size(),res=0,cnt;
        ///cout<<"sz = "<<sz<<endl;
        ///for(int i=0;i<sz;i++)cout<<"vec = "<<taken[i]<<endl;
        for(int i=0;i<sz;i++)
        {
            int A=0,B=0;
            if(ara[taken[i]]==0)
            {
                word[taken[i]]='A';
                A++;
                queue<int>q;q.push(taken[i]);
                while(!q.empty())
                {
                    int top=q.front();
                    for(int j=0;j<v[top].size();j++)
                    {
                        int asus=v[top][j];
                        if(ara[asus]==0 && asus!=taken[i])
                        {
                            ara[asus]=1;
                            q.push(asus);
                            if(word[top]=='A'){
                                B++;
                                word[asus]='B';
                            }
                            else{
                                word[asus]='A';
                                A++;
                            }
                        }
                    }
                    q.pop();
                }
                res+=max(A,B);
                ara[taken[i]]=1;
            }
        }
        printf("Case %d: %d\n",a,res);
        ///v.clear();
        ///for(int i=0;i<sz;i++)v[taken[i]].clear();

    }
    return 0;
}
