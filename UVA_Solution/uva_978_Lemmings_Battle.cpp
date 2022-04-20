#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,A,B,x;scanf("%d %d %d",&n,&A,&B);
        priority_queue<int>q1,q2;
        for(int i=0;i<A;i++){
            scanf("%d",&x);q1.push(x);
        }
        for(int i=0;i<B;i++){
            scanf("%d",&x);q2.push(x);
        }
        while(true){
         vector<int>v1,v2;
         int sz1=0,sz2=0,cnt=0;
        while(!q1.empty() && !q2.empty() && cnt<n)
        {
            int t1=q1.top(),t2=q2.top();
            q1.pop();q2.pop();
            if(t1==t2){

            }
            else if(t1>t2){
            v1.push_back(t1-t2);
            }
            else{
            v2.push_back(t2-t1);
            }
            cnt++;
        }
        sz1=v1.size(),sz2=v2.size();
        for(int i=0;i<sz1;i++)q1.push(v1[i]);
        for(int i=0;i<sz2;i++)q2.push(v2[i]);
        if(q1.empty() || q2.empty())break;

        }
        if(q1.empty() && q2.empty()){
            printf("green and blue died\n");
        }
        else if(!q1.empty()){
            printf("green wins\n");
            while(!q1.empty())
            {
                int t1=q1.top();
                printf("%d\n",t1);q1.pop();
            }
        }
        else if(!q2.empty()){
            printf("blue wins\n");
            while(!q2.empty())
            {
                int t1=q2.top();
                printf("%d\n",t1);q2.pop();
            }
        }
        if(a!=t)printf("\n");

    }
    return 0;
}
