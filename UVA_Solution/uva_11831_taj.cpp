#include<bits/stdc++.h>

using namespace std;


//int visited[10000];

int main()
{
    long long n,m,s,i,j,x,y,t;
    string st;
    while(cin>>n>>m>>s && n!=0 && m!=0 && s!=0)
    {
        char edges[105][105];
        t=0;
        char c,v;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>edges[i][j];
                //
                v=edges[i][j];
                if(v=='N' || v=='S' || v=='L' || v=='O')
                {
                    x=i;
                    y=j;
                    c=v;
                    //edges[i][j]='2';
                }
            }
        }
        //cout<<c<<endl;
        cin>>st;
        for(i=0; i<s; i++)
        {
            if(st[i]=='D')
            {
                if(c=='O')c='N';
                else if(c=='N')c='L';
                else if(c=='L')c='S';
                else if(c=='S')c='O';
                edges[x][y]=c;
            }
            else if(st[i]=='E')
            {
                if(c=='O')c='S';
                else if(c=='N')c='O';
                else if(c=='L')c='N';
                else if(c=='S')c='L';
                edges[x][y]=c;
            }
            else if(st[i]=='F')
            {
                if(c=='O')
                {
                    int mx=x,my=y-1;
                    if(mx>=0 && mx<n && my>=0 && my<m && edges[mx][my]!='#')
                    {
                        y-=1;
                        if(edges[x][y]=='*')
                        {
                            t++;
                            edges[x][y]='1';
                            //cout<<x<<" "<<y<<endl;
                        }
                    }
                }
                else if(c=='N')
                {
                    int mx=x-1,my=y;
                    if(mx>=0 && mx<n && my>=0 && my<m && edges[mx][my]!='#')
                    {
                        x-=1;
                        if(edges[x][y]=='*')
                        {
                            t++;
                            edges[x][y]='1';
                            //cout<<x<<" "<<y<<endl;
                        }
                        //else edges[x][y]='v';
                    }
                }
                else if(c=='L')
                {
                    int mx=x,my=y+1;
                    if(mx>=0 && mx<n && my>=0 && my<m && edges[mx][my]!='#')
                    {
                        y+=1;
                        if(edges[x][y]=='*')
                        {
                            t++;
                            edges[x][y]='1';
                            //cout<<x<<" "<<y<<endl;
                        }
                        //else edges[x][y]='v';

                    }
                }
                else if(c=='S')
                {
                    int mx=x+1,my=y;
                    if(mx>=0 && mx<n && my>=0 && my<m && edges[mx][my]!='#')
                    {
                        x+=1;
                        if(edges[x][y]=='*')
                        {
                            t++;
                            edges[x][y]='.';
                            //cout<<x<<" "<<y<<endl;
                        }
                        //else edges[x][y]='v';
                    }

                }
            }
        }
        /*for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cout<<edges[i][j];
            }
            cout<<endl;
        }
        */

        cout<<t<<endl;

    }

}
