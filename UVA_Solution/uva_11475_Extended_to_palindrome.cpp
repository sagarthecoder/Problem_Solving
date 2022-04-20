#include <bits/stdc++.h>
using namespace std;
int ara[100002*2];
int go(string x,int len)
{
    int j=0,i=1;
    while(i<len)
    {
        if(j==0 && x[i]!=x[j])i++;
        else if(x[i]==x[j]){
            ara[i]=j+1;
            i++,j++;
        }
        else{
            j=ara[j-1];
        }
    }
    return ara[len-1];
}
int main()
{
    string x,y;
    while(cin>>x)
    {
        y=x;
        string suffix;
        memset(ara,0,sizeof(ara));
        reverse(x.begin(),x.end());
        string z;
         z+=x;z+='#';z+=y;
        int len=z.size();
        int ans=go(z,len);
        ///cout<<"ans = "<<ans<<endl;
        suffix=x.substr(ans);
        cout<<y+suffix<<endl;
        //cout<<"ans= "<<ans<<endl;
        ///cout<<"x = "<<y.size()<<endl;

    }
    return 0;
}
