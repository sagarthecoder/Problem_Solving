#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int len,res=0,k;cin>>len>>k;
        string x;cin>>x;
        int seen[27]={0};
        for(int i=1;i<=len;i++)
        {
            int ch=x[i-1]-'A';
            if(seen[ch]!=0)
            {
                int baki=i-seen[ch];
                if(baki<=k)res++;
            }
            seen[ch]=i;
        }
        cout<<"Case "<<a<<": "<<res<<endl;
    }
    return 0;
}
