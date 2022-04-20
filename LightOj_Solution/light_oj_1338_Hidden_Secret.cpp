#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;cin>>t;
    string x,y;getline(cin,x);
    for(int a=1;a<=t;a++)
    {
        string x1,y1;
        getline(cin,x);
        ///getline(cin,y);
        getline(cin,y);
        int L1=x.size(),L2=y.size();
        cout<<"Case "<<a<<": ";
        for(int i=0;i<L1;i++){
            if(x[i]!=' ')x1+=tolower(x[i]);
        }
        for(int i=0;i<L2;i++){
            if(y[i]!=' ')y1+=tolower(y[i]);
        }
        int len1=x1.size(),len2=y1.size();
        if(len1!=len2)cout<<"No"<<endl;
        else
        {
            sort(x1.begin(),x1.end());
            sort(y1.begin(),y1.end());
            if(x1==y1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
