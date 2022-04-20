#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x,y;
    while(getline(cin,x)){
    int j=0,i;
    //getline(cin,x);
    int len=x.size();
    for( i=0;i<len;i++)
    {
        //if(((x[i]>='a' && x[i]<='z')||(x[i]>='A' && x[i]<='Z') || (x[i]>='0' && x[i]<='9'))==false)
        if(x[i]==' ')
        {
            if(!y.empty())
            {
                reverse(x.begin()+i-y.size(),x.begin()+i);
            }
            y.clear();
        }
        //else if(((x[i]>='a' && x[i]<='z')||(x[i]>='A' && x[i]<='Z') || (x[i]>='0' && x[i]<='9'))==true)y+=x[i];
        else
            y+=x[i];
    }
    if(y.size()>0)
    {
        reverse(x.begin()+i-y.size(),x.begin()+i);
    }
    y.clear();
    cout<<x<<endl;
    }
    return 0;
}
