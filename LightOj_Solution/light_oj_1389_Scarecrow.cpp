#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n,cnt=0;cin>>n;
        string x;cin>>x;
        x+='#';x+='#';
        for(int i=0;i<n;i++)
        {
            if(x[i]=='#')continue;
            else
            {
                cnt++;i+=2;
            }
        }
        cout<<"Case "<<a<<": "<<cnt<<endl;
    }
    return 0;
}
