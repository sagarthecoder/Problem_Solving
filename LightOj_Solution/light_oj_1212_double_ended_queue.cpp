#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int a=1;a<=t;a++)
    {
        int n,m,num;
        cout<<"Case "<<a<<":"<<endl;
        int i=0;cin>>n>>m;
        vector<int>v;
        vector<int>::iterator it;
        while(m--)
        {
            string x;cin>>x;
            if(x=="pushLeft"){
                cin>>num;
                if(i+1>n)cout<<"The queue is full"<<endl;
                else{
                cout<<"Pushed in left: "<<num<<endl;
                it=v.begin();
                v.insert(it,num);
                i++;
                }

            }
            else if(x=="pushRight"){
                cin>>num;
                if(i+1>n)cout<<"The queue is full"<<endl;
                else{
                v.push_back(num);
                cout<<"Pushed in right: "<<num<<endl;
                i++;
                }
            }
            else if(x=="popLeft"){
                if(i-1<0)cout<<"The queue is empty"<<endl;
                else
                {
                    cout<<"Popped from left: "<<v[0]<<endl;
                    i--;
                    v.erase(v.begin(),v.begin()+1);
                }
            }
            else
            {
                if(i-1<0)cout<<"The queue is empty"<<endl;
                else
                {
                    cout<<"Popped from right: "<<v[i-1]<<endl;
                    v.pop_back();
                    i--;
                }
            }
        }
    }
    return 0;
}
