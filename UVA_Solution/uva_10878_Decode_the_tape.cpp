
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;getline(cin,x);
    while(true)
    {
        getline(cin,x);
        int len=x.size();
        if(x[0]=='_')break;
        int sz=x.size();string y="";
        int ans=0;
        ///cout<<"len = "<<len<<endl;
        for(int i=1;i<len-1;i++){
              if(x[i]=='.')continue;
              if(x[i]=='o')y+='1';
              else y+='0';

        }
        len=y.size();
        for(int i=len-1,j=0;i>=0;i--,j++){
            if(y[i]=='1')ans+=(1<<j);
        }
       /// cout<<"ans = "<<ans<<endl<<endl;
        if(ans){
            cout<<(char)ans;
        }

    }
    ///cout<<endl;
    return 0;
}
