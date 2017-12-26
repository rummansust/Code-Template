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
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

/// 1 based
/// find sum with lazyProp

const int MAX = 120;

int stree[75536];
int lazy[75536];
bool grid[MAX][MAX];

int update(int,int,int,int,int,int,int,int,int,int);
int point_query(int,int,int,int,int,int,int);
void relax(int,int,int,int,int,int);

/// x1,y1,mx,my
/// x1,my+1,mx,y2
/// mx+1,y1,x2,my
/// mx+1,my+1,x2,y2

void relax(int idx,int x1,int y1,int x2,int y2,int val)
{
    int mx=(x1+x2)>>1,my=(y1+y2)>>1,nidx=(idx<<2);
    stree[idx]+=(x2-x1+1)*(y2-y1+1)*val;
    if(!(x1==x2 && y1==y2))
    {
        lazy[nidx]+=val;
        lazy[nidx|1]+=val;
        lazy[nidx|2]+=val;
        lazy[nidx|3]+=val;
    }
    lazy[idx]=0;
    return ;
}

int update(int idx,int x1,int y1,int x2,int y2,int ux1,int uy1,int ux2,int uy2,int val)
{
    if(x1>x2 || y1>y2) return 0;///invalid
    if(lazy[idx])
    {
        relax(idx,x1,y1,x2,y2,lazy[idx]);
    }
    if((ux1<=x1&&ux2>=x2) && (uy1<=y1&&uy2>=y2))///inside the given rectangle.
    {
        relax(idx,x1,y1,x2,y2,val);
        return stree[idx];
    }
    if(x2<ux1||x1>ux2) return stree[idx];///outside the given rectangle.
    if(y2<uy1||y1>uy2) return stree[idx];///outside the given rectangle.

    int mx=(x1+x2)>>1,my=(y1+y2)>>1,nidx=(idx<<2);
    int ret=0;
    ret+=update(nidx,x1,y1,mx,my,ux1,uy1,ux2,uy2,val);///upper left side
    ret+=update(nidx|1,x1,my+1,mx,y2,ux1,uy1,ux2,uy2,val);///upper right side
    ret+=update(nidx|2,mx+1,y1,x2,my,ux1,uy1,ux2,uy2,val);///lower left side
    ret+=update(nidx|3,mx+1,my+1,x2,y2,ux1,uy1,ux2,uy2,val);///lower left side
    stree[idx]=ret;
    return stree[idx];
}

int point_query(int idx,int x1,int y1,int x2,int y2,int x,int y)
{
    if(x1>x2 || y1>y2) return 0;///invalid
    if(lazy[idx])
    {
        relax(idx,x1,y1,x2,y2,lazy[idx]);
    }
    if((x==x1&&x==x2) && (y==y1&&y==y2))///inside the given rectangle.
    {
        return stree[idx];
    }
    if(x2<x||x1>x) return 0;///outside the given rectangle.
    if(y2<y||y1>y) return 0;
    int mx=(x1+x2)>>1,my=(y1+y2)>>1,nidx=(idx<<2);
    int ret=0;
    ret+=point_query(nidx,x1,y1,mx,my,x,y);///upper left side
    ret+=point_query(nidx|1,x1,my+1,mx,y2,x,y);///upper right side
    ret+=point_query(nidx|2,mx+1,y1,x2,my,x,y);///lower left side
    ret+=point_query(nidx|3,mx+1,my+1,x2,y2,x,y);///lower left side
    return ret&1;
}

void printGrid(int n,int m)
{
    int cur;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cur=grid[i][j]^point_query(1,1,1,n,m,i,j);
            PF("%d",cur);
        }
        puts("");
    }
}

int main()
{
    int test,n,m,r,c;
    char ch;
    while(SF("%d %d %d %d",&n,&m,&r,&c)==4 && (n+m+r+c))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                SF(" %c",&ch);
                grid[i][j]=(bool) (ch-'0');
            }
        }
        int res=0;
        clrall(stree,0);
        clrall(lazy,0);
        bool cur;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cur=grid[i][j]^point_query(1,1,1,n,m,i,j);
                if(cur==false) continue;
                if(i+r>n+1 || j+c>m+1)
                {
                    res=-1;
                    i=n+1;
                    j=m+1;
                    continue;
                }
                res++;
                update(1,1,1,n,m,i,j,i+r-1,j+c-1,1);
            }
        }
        PF("%d\n",res);
    }
    return 0;
}

/*
5 5 3 3
11011
11011
11011
00000
00000
0 0 0 0
*/









