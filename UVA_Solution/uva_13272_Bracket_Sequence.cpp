#include <bits/stdc++.h>
using namespace std;
int seen[100002];
struct data
{
    char ch;
    int v;
};
char c1,c2;
void go(char ch)
{
    if(ch=='<')c1='>';
    else if(ch=='{')c1='}';
    else if(ch=='[')c1=']';
    else if(ch=='(')c1=')';
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        char x[100008];
        stack<data>s;
        memset(seen,0,sizeof(seen));
        ///memset(ans,0,sizeof(ans));
        scanf("%s",x);int len=strlen(x);
        ///cout<<"len = "<<len<<endl;
        int cnt=0;
        for(int i=len-1;i>=0;i--)
        {
            if(x[i]=='<' || x[i]=='{' || x[i]=='(' || x[i]=='['){
                go(x[i]);
                ///cout<<"ok="<<x[i]<<endl;
                if(!s.empty()){
                    if(s.top().ch==c1){
                        ///cnt=seen[i];
                       /// seen[i]=2;
                       int ln=s.top().v;
                       seen[i]=2+seen[i+1]+seen[ln+1];
                        /*int baraitechi=0;
                        for(int j=i;j<=ln;j++){baraitechi+=seen[j];
                        }*/
                        s.pop();
                        ///ans[i]=baraitechi+ans[ln+1];

                        ///cout<<"i = "<<i<<" ,seen[i] = "<<seen[i]<<endl;
                    }
                    else{
                    s.push({x[i],i});
                    ///cnt=0;
                    }
                }
                else s.push({x[i],i});
               }
            else s.push({x[i],i});
        }
        printf("Case %d:\n",a);
        for(int i=0;i<len;i++)printf("%d\n",seen[i]);
    }
    return 0;
}
