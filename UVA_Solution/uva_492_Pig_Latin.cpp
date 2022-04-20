#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    while(getline(cin,x))
    {
        int len=x.size();
        if(!len)
            break;


        string y="";
        for(int i=0; i<len; i++)
        {
            if((x[i]>='a' && x[i]<='z')||(x[i]>='A' && x[i]<='Z'))y+=x[i];
            else
            {
                if(!y.empty())
                {
                   // cout<<"y = "<<y<<endl;
                    char ch=tolower(y[0]);
                    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                    {
                        y+="ay";
                        cout<<y;
                    }
                    else
                    {
                        int sz=y.size();
                        for(int j=1; j<sz; j++)cout<<y[j];
                        cout<<y[0];
                        cout<<"ay";
                    }
                }
                cout<<x[i];
                y="";
            }
            //else if((x[i]>='a' && x[i]<'z')||(x[i]>='A' && x[i]<='Z'))y+=x[i];
            ///else cout<<x[i];
        }
        if(!y.empty())
        {
            char ch=tolower(y[0]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            {
                y+="ay";
                cout<<y;
            }
            else
            {
                int sz=y.size();
                for(int i=1; i<sz; i++)cout<<y[i];
                cout<<y[0];
                cout<<"ay";
            }
        }
        cout<<endl;

    }
    return 0;
}

