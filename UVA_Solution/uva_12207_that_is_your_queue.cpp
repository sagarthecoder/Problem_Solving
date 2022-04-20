#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pos[1004];
int main()
{
    int n,q,a=1;
    while(true)
    {
        scanf("%d %d",&n,&q);
        memset(pos,0,sizeof(pos));
        if(!n && !q)break;
        printf("Case %d:\n",a);
        vector<int>v;stack<int>q2;
        map<int,bool>seen;

        int mn=min(q,n);
        int sz=mn;
        for(int i=1;i<=mn;i++){
            v.push_back(i);
            pos[i]=i;
        }
        int up=-1;char ch;int x;
        int k=0;

        for(int i=0;i<q;i++)
        {
            scanf(" %c",&ch);

            if(ch=='E'){

                scanf("%d",&x);
                if(x<=mn){
                /// cout<<"x = "<<x<<endl;
                 ///cout<<"pos of x = "<<pos[x]<<endl;
                 ///cout<<"before = "<<v[pos[x]-1]<<endl;
                 v[pos[x]-1]=-1;
                 ///cout<<"after = "<<-1<<endl;
                 ///v.push_back(x);
                 ///pos[x]=sz;sz++;
                 //q2.push(x);seen[x]=1;
                }
                q2.push(x);seen[x]=1;
              ///  cout<<"front = "<<q2.front()<<endl;
            }
            else
            {
                bool ck=false;
                while(!q2.empty())
                {
                    int top1=q2.top();
                    if(seen[top1]){
                        printf("%d\n",top1);
                        if(top1<=mn){
                            v.push_back(top1);
                            sz++;
                            pos[top1]=sz;
                        }
                        seen[top1]=0;
                        ck=true;
                        q2.pop();break;
                    }
                    q2.pop();
                }
                if(!ck)
                {
                    ///cout<<"K = "<<k<<endl;
                    for(;k<sz;k++)
                    {
                        if(ck)break;
                        int top=v[k];
                        if(top!=-1){
                            printf("%d\n",top);
                            v.push_back(top);
                           // pos[top]=sz;
                            sz++;
                            pos[top]=sz;
                            ck=true;
                            //break;
                        }
                    }
                    ///cout<<"Down = "<<sz<<endl;
                }
            }
        }
        a++;
    }
    return 0;
}
