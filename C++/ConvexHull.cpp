#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define clr(name,val) memset(name,(val),sizeof(name));
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS .000000001
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("outputtest.txt","w",stdout)

using namespace std;

typedef pair<int,int> pii;

pii point[10000];
bool col[10000];
int x,y;
int n;///n should be greater than 2;
int cross(pii b,pii c)
{
    return b.fs*c.sc-b.sc*c.fs;
}

bool comp1(pii a,pii b)
{
    if(a.sc==b.sc) return a.fs>b.fs;
    else return a.sc<b.sc;
}

ll distance(pii a)
{
    ll d=(ll) a.fs*(ll) a.fs + (ll) a.sc*(ll) a.sc;
    return d;
}

bool comp2(pii a,pii b)
{
    pii na=a,nb=b;
    na.fs-=x;
    nb.fs-=x;
    na.sc-=y;
    nb.sc-=y;
    int crs=cross(na,nb);
    ll dist1=distance(na),dist2=distance(nb);
    if(crs==0)
    {
        return dist1>dist2;
    }
    else return crs>0;
}

stack<pii > S;

void convex_Hull()
{
    pii x,a,b,na,nb;
    bool ok;
    for(int i=2;i<n;i++)
    {
        ok=true;
        b=point[i];
        if(col[i]) continue;
        do
        {
            a=S.top(),S.pop();
            x=S.top(),S.pop();
            S.push(x);
            S.push(a);
            na=a,nb=b;
            na.fs-=x.fs;
            nb.fs-=x.fs;
            na.sc-=x.sc;
            nb.sc-=x.sc;
            int crs=cross(na,nb);
            if(crs==0)
            {
                ok=false;
                break;
            }
            else if(crs>0) break;
            else
            {
                if(SZ(S)>2)
                S.pop();
                else break;
            }
        }while(SZ(S)>2);
        if(ok) S.push(b);
    }
    return ;
}

int main()
{
    pii a,b;
    while(cin>>n&&n)
    {
        clr(col,0);
        for(int i=0;i<n;i++)
        {
            cin>>point[i].fs>>point[i].sc;
        }
        sort(point,point+n,comp1);
        x=point[0].fs;
        y=point[0].sc;
        sort(point+1,point+n,comp2);
//        cout<<"::::::::::::::::"<<endl;
        for(int i=2;i<n;i++)
        {
            a=point[i];
            b=point[i-1];
            a.fs-=x;
            b.fs-=x;
            a.sc-=y;
            b.sc-=y;
            int crs=cross(a,b);
            if(crs==0) col[i]=true;
        }
//        for(int i=0;i<n;i++)
//        {
//            cout<<point[i].fs<<" "<<point[i].sc<<endl;
//        }

        S.push(point[0]);
        S.push(point[1]);
//        cout<<"Convex Hull Set of Points"<<endl;
//        cout<<"::::::::::::::::"<<endl;
        convex_Hull();
        if(SZ(S)==n) puts("No");
        else puts("Yes");
//        cout<<x<<" "<<y<<endl;
        while(!S.empty())
        {
//            cout<<S.top().fs<<" "<<S.top().sc<<endl;
            S.pop();
        }
//        cout<<"::::::::::::::::"<<endl;
    }
    return 0;
}
/*
5
1 5
6 6
3 3
2 2
8 3
*/














