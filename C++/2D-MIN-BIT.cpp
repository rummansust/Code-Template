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
#include <utility>
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
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

typedef pair<int,int> pii;

const int MAX = 305;
/// 1 based indexing

int T[4][MAX+7][MAX+7];

vector<pii > adj[MAX*MAX];

int dp[2][MAX][MAX];
int mat[MAX][MAX];

void u0(int r,int c,int v,int id)
{
    for(int x=r;x<MAX;x += x&-x)
    {
        for(int y=c;y<MAX;y += y&-y)
        {
            T[0][x][y]=id?max(T[0][x][y],v):min(T[0][x][y],v);
        }
    }
    return ;
}

void u1(int r,int c,int v,int id)
{
    for(int x=r;x<MAX;x += x&-x)
    {
        for(int y=c;y>0;y -= y&-y)
        {
            T[1][x][y]=id?max(T[1][x][y],v):min(T[1][x][y],v);
        }
    }
    return ;
}

void u2(int r,int c,int v,int id)
{
    for(int x=r;x>0;x -= x&-x)
    {
        for(int y=c;y<MAX;y += y&-y)
        {
            T[2][x][y]=id?max(T[2][x][y],v):min(T[2][x][y],v);
        }
    }
    return ;
}

void u3(int r,int c,int v,int id)
{
    for(int x=r;x>0;x -= x&-x)
    {
        for(int y=c;y>0;y -= y&-y)
        {
            T[3][x][y]=id?max(T[3][x][y],v):min(T[3][x][y],v);
        }
    }
    return ;
}

int q0(int r,int c)
{
    int ret=-oo;
    for(int x=r;x>0;x -= x&-x)
    {
        for(int y=c;y>0;y -= y&-y)
        {
            ret=max(T[0][x][y],ret);
        }
    }
    return ret;
}

int q1(int r,int c)
{
    int ret=-oo;
    for(int x=r;x>0;x -= x&-x)
    {
        for(int y=c;y<MAX;y += y&-y)
        {
            ret=max(T[1][x][y],ret);
        }
    }
    return ret;
}

int q2(int r,int c)
{
    int ret=-oo;
    for(int x=r;x<MAX;x += x&-x)
    {
        for(int y=c;y>0;y -= y&-y)
        {
            ret=max(T[2][x][y],ret);
        }
    }
    return ret;
}

int q3(int r,int c)
{
    int ret=-oo;
    for(int x=r;x<MAX;x += x&-x)
    {
        for(int y=c;y<MAX;y += y&-y)
        {
            ret=max(T[3][x][y],ret);
        }
    }
    return ret;
}

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int n,m,p;
    sf("%d %d %d",&n,&m,&p);
    int pre=1,cur=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sf("%d",&mat[i][j]);
            adj[mat[i][j]].psb(mp(i,j));
            if(mat[i][j]==1)
            {
                dp[pre][i][j]=i+j-2;
            }
        }
    }
    int x,y,a,b,res,v;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<MAX;k++)
            {
                T[i][j][k]=-oo;
            }
        }
    }

    for(int i=2;i<=p;i++)
    {
        for(int j=0;j<SZ(adj[i-1]);j++)
        {
            x=adj[i-1][j].fs;
            y=adj[i-1][j].sc;
            v=dp[pre][x][y];
            u0(x,y,x+y-v,1);
            u1(x,y,x-y-v,1);
            u2(x,y,-x+y-v,1);
            u3(x,y,-x-y-v,1);
        }
        for(int j=0;j<SZ(adj[i]);j++)
        {
            x=adj[i][j].fs;
            y=adj[i][j].sc;
            v=min(oo,x+y - q0(x,y));
            v=min(v,x-y-q1(x,y));
            v=min(v,-x+y-q2(x,y));
            v=min(v,-x-y-q3(x,y));
            dp[cur][x][y]=v;
        }
        for(int j=0;j<SZ(adj[i-1]);j++)
        {
            x=adj[i-1][j].fs;
            y=adj[i-1][j].sc;
            u0(x,y,-oo,0);
            u1(x,y,-oo,0);
            u2(x,y,-oo,0);
            u3(x,y,-oo,0);
        }
        swap(pre,cur);
    }
    res=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mat[i][j]==p)
            {
                res=dp[pre][i][j];
                break;
            }
        }
        if(res!=-1) break;
    }
    pf("%d\n",res);
    return 0;
}









