#include <bits/stdc++.h>
using namespace std;
int ara[((1000003)*2)];
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        string x,y,z;
        memset(ara,0,sizeof(ara));
        cin>>x;
        y=x;
        reverse(x.begin(),x.end());
        z+=x;
        z+='#';
        z+=y;
        int i=1,j=0;
        int len=z.size();
       /// cout<<"z = "<<len<<endl;
        ///int ara[len+1];
       /// ara[0]=0;
        while(i<len)
        {
            if(j==0 && z[j]!=z[i])
            {
                i++;ara[i]=j;
            }
            else if(z[j]==z[i])
            {
                ara[i]=j+1;
                j++,i++;
            }
            else if(z[j]!=z[i])
            {
                j=ara[j-1];
            }
            ///cout<<"vitor = "<<ara[i]<<endl;
        }
        ///for( i=0;i<len;i++)cout<<ara[i]<<endl;
       /// cout<<"dis = "<<ara[len-1]<<endl;
       int olala=x.size();
        ///int ans=(len>>1)-(ara[len-1])+(len>>1);
        ///int ans=x.size()-ara[len-1]+x.size();
        int ans=olala-ara[len-1]+olala;
        cout<<"Case "<<a<<": "<<ans<<endl;

    }
    return 0;
}
