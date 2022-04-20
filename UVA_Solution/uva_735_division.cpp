#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool ck=false;
    while(true)
    {
        scanf("%d",&n);
        int get,get2;
        if(!n)break;
        if(ck)printf("\n");
        ck=true;
       bool olala=false;
        for(int i=1234; i<=98765; i++)
        {
            int taken=i;
            get=i,get2;
            if(i*n>98765)break;
            bool inside=false;
            bool inside2=false;
            bool seen[10]= {0};
            if(log10(i)+1<5)seen[0]=true;

            while(true)
            {
                int rem=taken%10;
               // cout<<"n = "<<i<<" "<<"Rem1 = "<<rem<<endl;
                //cout<<"fuck ="<<endl;
                if(seen[rem]==false)
                {
                    seen[rem]=1;
                }
                else
                {
                    inside=true;
                    break;
                }
                if(taken/10==0)break;
                taken=taken/10;
            }
            if(inside==false)
            {
                taken=(i*n);
                get2=taken;
                if(log10(taken)+1<5)
                {
                    if(seen[0]==true)
                        inside2=true;
                }
                //else
               // {
                    if(inside2==false){
                    while(true)
                    {
                        int rem=taken%10;
                        if(seen[rem]==false)
                        {
                            seen[rem]=1;
                        }
                        else
                        {
                            inside2=true;
                            break;
                        }
                        if(taken/10==0)break;
                        taken=taken/10;
                    }
               }
                //}
            }
           if(inside==false && inside2==false){
                if(log10(get2)+1<5)printf("0");
                printf("%d / ",get2);
                if(log10(get)+1<5)printf("0");
                printf("%d = %d\n",get,n);
                olala=true;
            }
        }
        if(!olala)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
