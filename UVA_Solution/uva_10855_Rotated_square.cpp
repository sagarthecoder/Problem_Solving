#include <bits/stdc++.h>
#define ll  long long int
using namespace std;
int main()
{
    int n,m;
    while(true)
    {
        cin>>n>>m;
        if(n+m==0)
            break;
        string x[n+2],y[m+2],y1[m+2],y2[m+2],y3[m+2];
        for(int i=0; i<n; i++)
            cin>>x[i];
        for(int i=0; i<m; i++)
        {
            cin>>y[i];
            y1[i]=y[i],y2[i]=y[i],y3[i]=y[i];
        }

        for(int t1=1; t1<=3; t1++)
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0,k=m-1; j<m; j++,k--)
                {
                    if(t1==1)
                        y1[i][j]=y[k][i];
                    else if(t1==2)
                        y2[i][j]=y1[k][i];
                    else
                        y3[i][j]=y2[k][i];
                }
            }
        }

        for(int t1=1; t1<=4; t1++)
        {
            int mx=0;
            for(int i=0; i<n; i++)
            {
                if(i+m>n)
                    break;
                for(int j=0; j<n; j++)
                {
                    if(i+m>n || j+m>n)
                        break;
                    bool ck=0;
                    for(int k=0; k<m; k++)
                    {
                        for(int k1=0; k1<m; k1++)
                        {
                            if(t1==1){
                                if(x[i+k][j+k1]!=y[k][k1])
                                {
                                    ck=true;
                                    break;
                                }
                            }
                                else if(t1==2)
                                {
                                    if(x[i+k][j+k1]!=y1[k][k1])
                                    {
                                        ck=true;
                                        break;
                                    }
                                }
                                else if(t1==3)
                                {
                                    if(x[i+k][j+k1]!=y2[k][k1])
                                    {
                                        ck=true;
                                        break;
                                    }
                                }
                                else
                                {
                                    if(x[i+k][j+k1]!=y3[k][k1])
                                    {
                                        ck=true;
                                        break;
                                    }
                                }
                        }
                        if(ck)
                            break;
                    }
                    if(ck==0)
                        mx++;
                }
            }
            cout<<mx;
            if(t1!=4)
                cout<<" ";
        }
        cout<<endl;

        /*for(int t1=0;t1<4;t1++){
            cout<<"Gap "<<endl;
            for(int i=0;i<m;i++)
            {
                if(t1==0)cout<<y[i]<<endl;
                else if(t1==1)cout<<y1[i]<<endl;
                else if(t1==2)cout<<y2[i]<<endl;
                else cout<<y3[i]<<endl;
            }

        }*/

    }
    return 0;
}
