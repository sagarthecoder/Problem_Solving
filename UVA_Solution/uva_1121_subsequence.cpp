#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n,s;
    while(cin>>n>>s){
   int  res,low=0,mini=1000000000,len=1,high=1;
    int ara[n+1];
    for(int i=0;i<n;i++)cin>>ara[i];
    res=ara[0];
    while(high<=n)
    {
        if(res>=s){
           mini=min(mini,len);
           ////cout<<"len = "<<len<<endl;
           len--;
           res-=ara[low];
           low++;
        }
        else{
            res+=ara[high];len++;high++;
        }
    }
    //if(res>=s)
   // mini=min(mini,len);
   if(mini==1000000000)cout<<0<<endl;
   else
    cout<<mini<<endl;
    }
    return 0;
}
