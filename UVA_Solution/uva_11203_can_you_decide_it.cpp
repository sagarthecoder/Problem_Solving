#include<cstdio>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include <unordered_map>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x;
        int posM=-1,posE=-1,m=0,e=0,prosnoM=0,prosnoE=0;
        bool brk=true;
        cin>>x;
        int len=x.size();
        for(int i=0;i<len;i++)
        {
            if(x[i]!='M' && x[i]!='E' && x[i]!='?')brk=false;
            if(x[i]=='M'){
                m++;
                posM=i;
            }
            if(x[i]=='E'){
                e++;
                posE=i;
            }
           /// cout<<"brk ="<<brk<<endl;
        }
        if(posE==-1 || posM==-1 || m!=1 || e!=1 || brk==false || posM>=posE)cout<<"no-theorem"<<endl;
        else
        {
            prosnoM=posM;
            prosnoE=len-(posE+1);
            /*if(posE-posM==2)
            {
                if(prosnoM==prosnoE-1 && prosnoM!=0 && prosnoE!=0)cout<<"theorem"<<endl;
                else
                    cout<<"no-theorem"<<endl;
            }*/
            ///else
            ///{
                ///if(posM>0 && posE-posM>2 && prosnoE>=2)cout<<"theorem"<<endl;
                if(posE-posM>=2 && prosnoM!=0 && prosnoE!=0 && posM+(posE-posM-1)==prosnoE)cout<<"theorem"<<endl;
                else
                    cout<<"no-theorem"<<endl;
            ///}
        }
        ///printf("%d %d %d %d %d %d %d\n",posM,posE,m,e,brk,prosnoM,prosnoE);
    }
    return 0;
}
