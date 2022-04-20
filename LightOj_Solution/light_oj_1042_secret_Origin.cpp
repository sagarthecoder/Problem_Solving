#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    for(int a=1; a<=t; a++)
    {
        ll n,take,ans=0;
        string x;
        cin>>n;
        int i=0,cnt=0;
        take=n;
        while(true)
        {
            int rem=take%2;
            if(rem==0)
               x+='0';
            else
                x+='1';
            i++;
            if(take/2==0)
                break;
            take=take/2;
        }
        x+='0';
        i++;
        for(int j=0;j<i-1;j++){
            if(x[j]=='1' && x[j+1]=='0'){
                swap(x[j],x[j+1]);
                sort(x.begin(),x.begin()+j+1,greater<char>());break;

            }
        }
        for(int j=0;j<i;j++){
            if(x[j]!='0')ans+=(1<<j);
        }

        ///cout<<"x = "<<x<<endl;
        cout<<"Case "<<a<<": "<<ans<<endl;
    }
    return 0;
}
