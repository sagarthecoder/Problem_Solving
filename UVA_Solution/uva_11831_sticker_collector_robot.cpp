#include <bits/stdc++.h>
using namespace std;
char str[102][102];
int n,k,m;
int main()
{

    while(true)
    {
        char ch;
        cin>>n>>m>>k;
        if(n==0 && m==0 && k==0)break;
        int x1,y1,res=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>str[i][j];
                if(str[i][j]!='*' && str[i][j]!='.' && str[i][j]!='#')
                {
                    ch=str[i][j];
                    x1=i,y1=j;
                }
            }
        string x;
        cin>>x;
        for(int i=0; i<k; i++)
        {
            if(x[i]!='F')
            {
                if(ch=='N')
                {
                    if(x[i]=='D')ch='L';
                    else if(x[i]=='E')ch='O';
                }
                else if(ch=='L'){
                    if(x[i]=='D')ch='S';
                    else if(x[i]=='E')ch='N';
                }
                else if(ch=='S'){
                    if(x[i]=='D')ch='O';
                    else if(x[i]=='E')ch='L';
                }
                else if(ch=='O'){
                    if(x[i]=='D')ch='N';
                    else if(x[i]=='E')ch='S';
                }

            }
            else
            {
                if(ch=='L')
                {
                    if(y1+1>=0 && y1+1<m)
                    {
                        if(str[x1][y1+1]!='#')
                        {
                            y1++;
                            if(str[x1][y1]=='*'){res++;
                            str[x1][y1]='.';
                            }
                        }
                    }
                }
                else if(ch=='O')
                {
                    if(y1-1>=0 && y1-1<m)
                    {
                        if(str[x1][y1-1]!='#')
                        {
                            y1--;
                            if(str[x1][y1]=='*'){
                                res++;
                                str[x1][y1]='.';
                            }
                        }
                    }
                }
                else if(ch=='N')
                {
                    if(x1-1>=0 && x1-1<n)
                    {
                        if(str[x1-1][y1]!='#')
                        {
                            x1--;
                            if(str[x1][y1]=='*'){
                                res++;str[x1][y1]='.';
                            }
                        }
                    }
                }
                else if(ch=='S')
                {
                    if(x1+1>=0 && x1+1<n)
                    {
                        if(str[x1+1][y1]!='#')
                        {
                            x1++;
                            if(str[x1][y1]=='*'){
                                res++;str[x1][y1]='.';
                            }
                        }
                    }
                }
            }
        }
        cout<<res<<endl;
    }
}
