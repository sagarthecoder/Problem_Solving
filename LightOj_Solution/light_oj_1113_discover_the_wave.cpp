#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        cout<<"Case "<<a<<":"<<endl;
        vector<string>v;
        string x,y;
        v.push_back("http://www.lightoj.com/");
        int i=1;
        vector<string>::iterator it;
        it=v.begin();
        int kola=1;
        while(true)
        {
            cin>>x;
            if(x=="QUIT")
                break;
            if(x=="BACK")
            {
                if(i-1<1)
                    cout<<"Ignored"<<endl;
                else
                {
                    cout<<v[i-2]<<endl;
                    i--;
                }
            }
            else if(x=="FORWARD")
            {
               /// cout<<"size = "<<v.size()<<endl;
                if(i+1>v.size() || i+1>kola)cout<<"Ignored"<<endl;
                else
                {
                    cout<<v[i]<<endl;
                    i++;
                }
            }
            else
            {
                cin>>y;
                cout<<y<<endl;
               it=v.begin();
                v.insert(it+i,y);
                i++;
                kola=i;
            }

        }
    }
    return 0;
}
