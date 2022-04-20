#include <bits/stdc++.h>
using namespace std;
struct data
{
    string s;
    int len;
};
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        string x;
        string now;
        int k,L;

        vector<data>str;
        while(true)
        {
            cin>>x;
            if(x=="*")break;
            int len=x.size();
            str.push_back({x,len});
        }
        getline(cin,now);
        int sz=str.size();
        ///cout<<"sz= "<<str.size()<<endl;
        while(true)
        {
            getline(cin,now);
            map<string,int>seen;
            string y="",z="";
            int len=now.size();
            ///cout<<"len = "<<len<<endl;
            if(len==0)break;
            for( k=0; k<len; k++)
            {
                if(now[k]==' ')break;
                y+=now[k];
            }
            for(L=k+1; L<len; L++)z+=now[L];
            ///cout<<"y = "<<y<<endl;
            ///cout<<"z = "<<z<<endl;
            queue<string>q;
            q.push(y);
            bool ck=false;
            int maxi=0,ylen=y.size(),zlen=z.size();
            if(z!=y)
            {
                while(!q.empty())
                {
                    string top=q.front(),asus;
                    ///cout<<"go "<<endl;
                    for(int i=0; i<sz; i++)
                    {

                        ///cout<<"vitore = "<<endl;
                        if(str[i].len==ylen && str[i].s!=y && seen[str[i].s]==0)
                        {
                            int cnt=0;
                            ///cout<<"omg = "<<endl;
                            asus=str[i].s;
                            for(int j=0; j<ylen; j++)
                            {

                                if(asus[j]==top[j])cnt++;
                            }
                            if(cnt>=ylen-1)
                            {

                                seen[asus]=seen[top]+1;
                                maxi=max(seen[asus],maxi);
                                ///cout<<"maxi = "<<maxi<<endl;
                                ///cout<<"asus = "<<asus<<endl;
                                q.push(asus);
                                if(asus==z)
                                {
                                    ck=true;
                                    break;
                                }
                            }

                        }
                    }
                    if(ck)break;
                    q.pop();
                }
            }
            cout<<y<<" "<<z<<" "<<maxi<<endl;

        }
        if(a!=t)cout<<endl;
    }
    return 0;
}
