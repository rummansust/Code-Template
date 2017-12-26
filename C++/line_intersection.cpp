#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <sstream>

#define clr(name,val) memset(name,val,sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> &vector name);
///make_pair  point=make_pair(i,j);
///access pair value point.first;point.second;

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

struct point
{
    int x,y;
};

bool line_intersection(point s1,point s2,point t1,point t2,point &res)
{
    double a1,b1,a2,b2,c1,c2,det;
    a1=(s2.y*1.0-s1.y*1.0);
    b1=(s1.x*1.0-s2.x*1.0);
    c1=(a1*s1.x*1.0+b1*s1.y*1.0);
    a2=(t2.y*1.0-t1.y*1.0);
    b2=(t1.x*1.0-t2.x*1.0);
    c2=(a2*t1.x*1.0+b2*t1.y*1.0);
    det=a1*b2-a2*b1;
    if(det==0.0) return false;
    res.x=(b2*c1-b1*c2)/det;
    res.y=(a1*c2-a2*c1)/det;
    return true;
}

double dist(point a,point b)
{
    int dx,dy;
    dx=a.x-b.x;
    dy=a.y-b.y;
    return sqrt(dx*dx*1.0+dy*dy*1.0);
}

bool check(point a,point b,point &res)
{
    if(min(a.x,b.x)<=res.x&&res.x<=max(a.x,b.x))
    {
        if(min(a.y,b.y)<=res.y&&res.y<=max(a.y,b.y))
        return true;
    }
    return false;
}

int main()
{
    point s1s,s1e,s2s,s2e,res;
    double ans;
    int cas=0;
    while(scanf("%d %d %d %d",&s1s.x,&s1s.y,&s1e.x,&s1e.y)==4)
    {
        if(!s1s.x&&!s1s.y&&!s1e.x&&!s1e.y) break;
        scanf("%d %d %d %d",&s2s.x,&s2s.y,&s2e.x,&s2e.y);
        printf("Case %d: ",++cas);
        if(line_intersection(s1s,s1e,s2s,s2e,res))
        {
            cout<<"yes"<<endl;
            if(check(s1s,s1e,res)&&check(s2s,s2e,res))
            {
                double d1=dist(s1s,s2s)+dist(s1e,s2s);
                double d2=dist(s1s,s2e)+dist(s1e,s2e);
                ans=min(d1,d2);
                printf("%.3f",ans/2.0);
                cout<<endl;
                continue;
            }
            ans=dist(s1s,s1e);
            printf("%.3f",ans/2.0);
            cout<<endl;
            continue;
        }
        ans=dist(s1s,s1e);
        printf("%.3f",ans/2.0);
        cout<<endl;
    }
    return 0;
}
