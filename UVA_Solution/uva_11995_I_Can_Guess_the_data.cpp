#include <bits/stdc++.h>
using namespace std;
int ara[5];
int main()
{
    int n;
    while(cin>>n)
    {
        int q1=0,p=0,st=0,total=0,a,b,c,y,x;
        bool ck=false;
        queue<int>q;
        stack<int>s;
        priority_queue<int>rupa;

        for(int i=0; i<n; i++)
        {
            a=-1,b=-1,c=-1;
            cin>>y>>x;
            if(y==1)
            {
                q.push(x);
                rupa.push(x);
                s.push(x);
            }
            else
            {
                total++;
                if(!q.empty()){a=q.front();
                q.pop();
                }
                if(!rupa.empty()){b=rupa.top();
                rupa.pop();
                }
                if(!s.empty()){c=s.top();
                s.pop();
                }
                //cout<<"a,b,c = "<<a<<" "<<b<<" "<<c<<endl;
                if(a==x)q1++;
                if(b==x)p++;
                if(c==x)st++;
                if(a!=x && b!=x && c!=x)ck=true;
            }
        }
        ara[0]=q1,ara[1]=p,ara[2]=st;
        sort(ara,ara+3,greater<int>());
        if(ck)cout<<"impossible"<<endl;
        else if(ara[0]!=total)cout<<"impossible"<<endl;
        else if(ara[0]==ara[1])cout<<"not sure"<<endl;
        else
        {
            if(q1==total)cout<<"queue"<<endl;
            else if(p==total)cout<<"priority queue"<<endl;
            else cout<<"stack"<<endl;
        }
    }
    return 0;
}
