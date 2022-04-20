#include <bits/stdc++.h>
#define pi 3.141592653589793
using namespace std;
struct data
{
    double La,Lo;
};
map<string,vector<data> >seen;
double rad(double x)
{
    return ((pi*x)/180.0);
}
int main()
{
    double a,b,c,d,r=6378.00,lat1,lat2,lon1,lon2;
    string x,y;
    while(true){
     cin>>x;
     if(x=="#")break;
     cin>>lat1>>lon1;
     seen[x].push_back({lat1,lon1});
    }
    while(true)
    {
       cin>>x>>y;
       if(x=="#" && y=="#")break;
       cout<<x<<" - "<<y<<endl;
       if(seen[x].size()==0 || seen[y].size()==0)cout<<"Unknown"<<endl;
       else if(x==y)cout<<"0 km"<<endl;
       else{
       lat1=rad(seen[x][0].La);
      /// cout<<"g = "<<seen[x][0].La<<endl;
       lat2=rad(seen[y][0].La);
       lon1=rad(seen[x][0].Lo);
       lon2=rad(seen[y][0].Lo);
       double dlon=lon2-lon1;
       double dlat=lat2-lat1;
       a=sin(dlat/2)*sin(dlat/2) +(cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2));
       c=2*atan2(sqrt(a),sqrt(1-a));
       d=(r*c);
       int dis=(int)round(d);
       ///cout << setprecision (0) << fixed <<d<<endl;
       cout<<dis<<" km"<<endl;
       }

    }
   return 0;
}
