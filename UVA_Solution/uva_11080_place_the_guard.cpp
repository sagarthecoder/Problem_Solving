#include <bits/stdc++.h>
using namespace std;
vector<int>v[203];
int visited[203],black=0,white=0;
int bfs(int x)
{
   black=0,white=0;
   bool ck=false;
   queue<int>q;q.push(x);
   black++;
   while(!q.empty())
   {
       int top=q.front();
       ///cout<<"top = "<<top<<endl;
      /// cout<<"value of top = "<<visited[top]<<endl<<endl;
       for(int i=0;i<v[top].size();i++)
       {
           int asus=v[top][i];
           if(visited[asus]==-1 && asus!=x){
             visited[asus]=visited[top]^1;
             q.push(asus);
             if(visited[asus]==0)black++;
             else white++;
           }
           else {
            if(visited[asus]==visited[top]){ck=true;
            break;
            }
           }
          /// cout<<"top = "<<top<<",= "<<visited[top]<<endl;
          /// cout<<"asus = "<<asus<<" , = "<<visited[asus]<<endl;
       }
       ////cout<<endl<<endl;
       if(ck)break;
       q.pop();
   }
   if(ck)return 2021;
   else return min(black,white);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,e,x,y,cnt=0;scanf("%d %d",&n,&e);
        for(int i=0;i<e;i++){
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=0;i<n;i++)visited[i]=-1;
        bool ck=false;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                visited[i]=0;
                int ans=bfs(i);
                if(ans==2021){
                    cout<<"-1"<<endl;
                    ck=true;
                    break;
                }
                if(ans==0)ans=1;
                cnt+=ans;
            }
        }
        if(!ck){cout<<cnt<<endl;
        }
        for(int i=0;i<n;i++)v[i].clear();
    }
    return 0;
}
