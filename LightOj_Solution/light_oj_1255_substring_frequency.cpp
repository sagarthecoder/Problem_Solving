#include <bits/stdc++.h>
using namespace std;
int ara[1000003];
int kmp(int i,int j,int len2,int len,int cnt,string x,string y)
{
    while(i<len)
    {
        if(x[i]==y[j]){
            j++,i++;
        }
        if(j==len2){cnt++;
          j=ara[j-1];
        }
        else if(x[i]!=y[j]){
            if(j!=0)j=ara[j-1];
            else i++;
        }
    }
    return cnt;
}
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++){
    string x,y;cin>>x>>y;
    memset(ara,0,sizeof(ara));
    int j=0,i=1,len;
    len=x.size();
    int len2=y.size();
    ara[0]=0;
    while(i<len2) /// substring er jonne array table create korbo .
    {
        if(j==0 && y[j]!=y[i]){
            i++;
        }
        else if(y[j]==y[i]){
            ara[i]=j+1;
            j++,i++;
        }
        else if(y[j]!=y[i])
        {
            j=ara[j-1];
        }
    }
     i=0,j=0;
    /// abdbaabdbamnpab
    int ans=kmp(0,0,len2,len,0,x,y);
    cout<<"Case "<<a<<": "<<ans<<endl;
    }
    return 0;

}

