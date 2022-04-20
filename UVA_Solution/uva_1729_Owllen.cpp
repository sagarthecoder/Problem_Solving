#include <bits/stdc++.h>
#define ll long long
using namespace std;
int seen[200];
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        string x;cin>>x;
        int len=x.size(),cnt=0;
        memset(seen,0,sizeof(seen));
        for(int i=0;i<len;i++){
        seen[x[i]]++;
        }
        int mini=10000000;
        for(char ch='a';ch<='z';ch++)mini=min(mini,seen[ch]);
        cout<<"Case "<<a<<": ";
        cout<<mini<<endl;
    }
    return 0;
}
