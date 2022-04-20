#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    string x;
    for(int a=1;a<=t;a++)
    {
        cin>>x;
        int len=x.size();
        char ch;int ans=0;
        cout<<"Case "<<a<<": ";
        for(int i=0;i<len;i++)
        {
            if(x[i]>='A' && x[i]<='Z'){
                if(ans!=0){
                    for(int k=0;k<ans;k++)cout<<ch;
                }
                ch=x[i];ans=0;
            }
            else{
                ans=(ans*10)+(x[i]-'0');
            }
        }
        if(ans!=0){
                    for(int k=0;k<ans;k++)cout<<ch;
                }
        cout<<endl;

    }
    return 0;
}
