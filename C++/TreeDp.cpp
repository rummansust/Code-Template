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

const int MAX = 100500;
const int M = 1000000007;

ll dprec[MAX][3];
vector<ll> dpgen[MAX][3];
vector<int> adj[MAX];
bool isBlack[MAX];


ll rec(int,int,int,int);
ll gen(int,int,int,int,int);

ll gen(int u,int par,int edgeId,int haveBlack,int needBlack)
{
    if(edgeId==SZ(adj[u]))
    {
        return ((ll) haveBlack);
    }
    int state = (haveBlack*2+needBlack);
    ll ret=dpgen[u][state][edgeId];
    if(ret!=-1) return ret;
    int v=adj[u][edgeId];
    if(v==par) return gen(u,par,edgeId+1,haveBlack,needBlack);
    ret=dpgen[u][state][edgeId]=0;

    ret=(rec(v,u,0,0)*gen(u,par,edgeId+1,haveBlack,needBlack))%M;

    if(!haveBlack)
    {
        ret=(ret+(rec(v,u,0,1)*gen(u,par,edgeId+1,1,0))%M)%M;
        ret=(ret+(rec(v,u,1,0)*gen(u,par,edgeId+1,0,1))%M)%M;
    }
    else
    {
        ret=(ret+(rec(v,u,1,0)*gen(u,par,edgeId+1,haveBlack,needBlack))%M)%M;
    }
    dpgen[u][state][edgeId]=ret;
    return ret;

}

ll rec(int u,int par,int haveBlack,int needBlack)
{
    if(haveBlack && isBlack[u]) return 0;
    int state = (haveBlack*2+needBlack);
    ll &ret = dprec[u][state];
    if(ret!=-1) return ret;
    ret=0;
    int curHaveBlack=(haveBlack|isBlack[u]);
    ret = (gen(u,par,0,curHaveBlack,!curHaveBlack))%M;
    return ret;
}

int main()
{
    int n,v;
    SF("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        SF("%d",&v);
        adj[i+1].psb(v);
        adj[v].psb(i+1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<SZ(adj[i]);j++)
        {
            dpgen[i][0].psb(-1);
            dpgen[i][1].psb(-1);
            dpgen[i][2].psb(-1);
        }
    }
    clrall(dprec,-1);
    for(int i=0;i<n;i++) SF("%d",&isBlack[i]);
    PF("%I64d\n",rec(0,0,0,0));
    return 0;
}


/**
input:
6
0 0 2 1 1
0 1 0 1 0 0

output:
3
*/

