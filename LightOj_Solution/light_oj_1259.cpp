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
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define M 10000000
using namespace std;
//map<int,int>status;
bool status[M+2];
int main()
{

    int sq=sqrt(M);
    vector<int>prime;
    status[1]=true;
    status[0]=true;
     for(int i=2;i<=M;i++){
        if(status[i]==false){
            prime.push_back(i);
            for(int j=2*i;j<=M;j=j+i){
                status[j]=true;
            }
        }
    }
   int t,n;
   //sieve();
   cin>>t;
   //scanf("%d",&t);
   for(int j=1;j<=t;j++)
   {
       cin>>n;
       int res=0;
       for(int i=0;true;i++)
       {
           int k=n-prime[i];
           //cout<<k<<endl;
           if(prime[i]>k)break;
           if(status[k]==false){
            res++;
           }

       }
       cout<<"Case "<<j<<": "<<res<<endl;
   }
   return 0;
}

