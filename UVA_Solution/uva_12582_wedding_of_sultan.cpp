#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int seen[27]={0};
        string x;
        cin>>x;int len=x.size();
        stack<char>s;
        for(int i=0;i<len;i++)
        {
            if(!s.empty())
            {
                if(s.top()==x[i]){
                    s.pop();
                }
                else
                {
                    char ch=s.top();
                    seen[ch-'A']++;
                    seen[x[i]-'A']++;
                    s.push(x[i]);
                }
            }
            else s.push(x[i]);
        }
        cout<<"Case "<<a<<endl;
        for(int i=0;i<26;i++)
        {
            if(seen[i]>0)
            {
                char ch='A'+i;
                cout<<ch<<" = "<<seen[i]<<endl;
            }
        }
    }
    return 0;
}
