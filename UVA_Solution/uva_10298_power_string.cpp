#include <bits/stdc++.h>
using namespace std;
int ara[1000004];
int main()
{
    while(true)
    {
        string x;//cin>>x;
        getline(cin,x);
        string y,z;
        z="";
        if(x==".")break;
        int len=x.size(),i=1,j=0;
        //cout<<"len= "<<len<<endl;
        while(i<len)
        {
            if(j==0 &&x[i]!=x[j]){
                ara[i]=0,i++;
            }
            else if(x[i]==x[j]){
                ara[i]=j+1;
                i++,j++;
            }
            else if(x[i]!=x[j]) j=ara[j-1];
        }
        if(len==0)cout<<1<<endl;
        else if(ara[len-1]==0)cout<<1<<endl;
        else if(ara[len-1]==len-1)cout<<len<<endl;
        else
        {

            int cnt=0;
            bool ck=false;
            y=x.substr(0,len-ara[len-1]);
            for(int i=0;i<len;i++)
            {
                z+=x[i];cnt++;
                if(cnt==len-ara[len-1]){
                    if(z==y){
                       // cout<<"z= "<<z<<endl;
                        z="";
                        cnt=0;
                    }
                    else{
                        ck=true;break;
                    }
                }
            }
            if(z!="" && z!=y)ck=true;
            ///cout<<"ck = "<<ck<<endl;
            if(!ck)cout<<len/(len-ara[len-1])<<endl;
            else cout<<1<<endl;
        }
        memset(ara,0,sizeof(ara));
    }
    return 0;
}
