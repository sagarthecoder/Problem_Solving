#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    while(true)
    {
        cin>>x;
        if(x=="0")break;
        int len=x.size();
        ll ans=0;
        for(int i=0,j=len;i<len;i++,j--)
        {
           if(x[i]!='0')
           ans+=((x[i]-'0')*((1<<j)-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
