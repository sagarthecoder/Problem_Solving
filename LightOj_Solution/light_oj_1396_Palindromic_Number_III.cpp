#include <bits/stdc++.h>
#define ll long long
using namespace std;
char x[100008];
char go(char ch)
{
    if(ch=='0')return '1';if(ch=='1')return '2';if(ch=='2')return '3';
    if(ch=='3')return '4';if(ch=='4')return '5';if(ch=='5')return '6';
    if(ch=='6')return '7';if(ch=='7')return '8';if(ch=='8')return '9';
    else return 'A';

}
int main()
{
    int t;scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,nine=0,i;
        scanf("%s",x);
        n=strlen(x);
        char y[n+3];
        printf("Case %d: ",a);
        for(i=0;i<n;i++){y[i]=x[i];
        if(x[i]=='9')nine++;
        }
        y[i]='\0';int mid=n/2;

        if(n==1 && x[0]=='0'){
            printf("1\n");continue;
        }
        if(nine==n){
            printf("1");
            for(int i=1;i<n;i++)printf("0");
            printf("1\n");continue;
        }


        for( i=0;i<mid;i++){
            y[n-i-1]=x[i];
        }
        bool ck=true;
        for( i=0;i<n;i++){
            if(y[i]<x[i]){
                ck=false;break;
            }
            else if(y[i]>x[i])break;
        }
        if(ck==true){
                bool mairala=false;
        for( i=0;i<n;i++){
            if(x[i]!=y[i]){
                mairala=true;;break;
            }
         }
         if(mairala==false)ck=false;

        }
        if(ck==false){
            if(n%2!=0){
                int m=n/2;
                if(y[m]=='9'){
                    y[m]='0';
                    for( i=m-1;i>=0;i--){
                        if(y[i]!='9'){
                            y[i]=go(y[i]);
                            y[n-i-1]=y[i];break;
                        }
                        else
                        {
                            y[i]='0';y[n-i-1]='0';
                        }
                    }
                }
                else y[m]=go(y[m]);
            }
            else
            {
                int m1=n/2;
                int m2=m1-1;
                if(y[m2]=='9'){
                    y[m1]='0';y[m2]='0';
                    for( i=m2-1;i>=0;i--){
                        if(y[i]!='9'){
                            y[i]=go(y[i]);
                            y[n-i-1]=y[i];break;
                        }
                        else
                        {
                            y[i]='0';y[n-i-1]='0';
                        }
                    }
                }
                else{
                    y[m1]=go(y[m1]);
                    y[m2]=y[m1];
                }
            }
        }
        printf("%s\n",y);

    }
    return 0;
}
