#include <bits/stdc++.h>
using namespace std;
int maxi;
int go(string x,int len)
{
    int L=len;
    for(int i=0,j=1;i<len;i++,j++)
    {
        if(L%j==0)
        {
            bool ck=false;
            int cnt=0;
            string y,z;
            y=x.substr(0,j);
            for(int k=0;k<L;k++)
            {
                z+=x[k];
                cnt++;
                if(cnt==j){
                    if(z==y){
                        z.clear();cnt=0;
                    }
                    else{
                        ck=true;break;
                    }
                }
            }
            if(!ck){maxi=j;
            break;
            }
        }
    }
    return maxi;
}
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        string x;
        cin>>x;
        int len=x.size();
        maxi=len;
        cout<<go(x,len)<<endl;
        if(a!=t)cout<<endl;
     }
     return 0;
}
