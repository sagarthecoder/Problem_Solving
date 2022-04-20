#include <bits/stdc++.h>
using namespace std;
int s,p;
int ara[1000002][27],serial[510],fail[1000002],ans[1000002];
char x[1000002];
void build(char y[])
{
    int len=strlen(y);
   /// cout<<"lenBuild = "<<len<<endl;
    int j=0,num;
    for(int i=0;i<len;i++)
    {
       num=y[i]-'a';
       if(!ara[j][num])ara[j][num]=s++;
       j=ara[j][num];
    }
    serial[p]=j;
    /// cout<<"p = "<<p <<" = "<<j<<endl;

    ans[j]=0;
    p++;
}
void failure()
{
    queue<int>q;
    for(int i=0;i<26;i++){
        if(ara[0][i]){
            q.push(ara[0][i]);
            fail[ara[0][i]]=0;
        }
    }
    while(!q.empty())
    {
        int top=q.front();
        ///cout<<"top = "<<top<<endl;
        for(int i=0;i<26;i++)
        {
            if(ara[top][i])
            {
                q.push(ara[top][i]);
                int top2=fail[top];
                while(ara[top2][i]==0)
                {
                    if(top2==0)break;
                    top2=fail[top2];
                }
                fail[ara[top][i]]=ara[top2][i];
            }
        }
        q.pop();
    }
}
void counting()
{
    int len=strlen(x);
   /// cout<<"len = "<<len<<endl;
    int j=0,num,temp;
    for(int i=0;i<len;i++)
    {
        num=x[i]-'a';
        ///cout<<"num ="<<num<<endl;
        while(j && ara[j][num]==0)j=fail[j];
        j=ara[j][num];
        temp=j;
        while(temp)
        {
            ans[temp]++;
            temp=fail[temp];
        }
    }
}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;scanf("%d",&n);
        s=1,p=0;
        scanf("%s",x);
        char y[508];
        for(int i=0;i<n;i++){
            scanf("%s",y);
            build(y);
        }
        failure();
        counting();
        printf("Case %d:\n",a);
        for(int i=0;i<n;i++)printf("%d\n",ans[serial[i]]);
        memset(ara,0,sizeof(ara));
        memset(ans,0,sizeof(ans));
        memset(fail,0,sizeof(fail));
    }
    return 0;
}
