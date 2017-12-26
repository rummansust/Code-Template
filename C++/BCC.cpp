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
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

const int MAXN = 100050;

vector<int> adj[MAXN];
vector<pair<int,int> > bridge;
stack<pair<int,int> > S;
vector<pair<int,int> > edge;
int distime[MAXN],height[MAXN],id;

void init(int n)
{
    for(int i=0;i<=n;i++) adj[i].clear();
    while(!S.empty()) S.pop();
    clrall(distime,0);
    clrall(height,0);
    id=1;
    return ;
}

void construct_bcc(int u,int v)
{
    pair<int,int> tmp;
    edge.clear();
    int nu,nv;
    while(!S.empty())
    {
        tmp=S.top();
        S.pop();
        nu=tmp.fs;
        nv=tmp.sc;
        edge.psb(mp(nu,nv));
        if(nu==u&&nv==v) break;
    }
    if(SZ(edge)<=1) return ;
    return ;
}

void dfs_bcc(int u,int par)
{
    int v,edgecnt;
    distime[u]=height[u]=id++;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!distime[v])
        {
            S.push(mp(u,v));
            dfs_bcc(v,u);
            height[u]=min(height[u],height[v]);
            if(distime[u]<=height[v])
            {
                construct_bcc(u,v);
            }
        }
        else if(distime[u]>distime[v])
        {
            S.push(mp(u,v));
            height[u]=min(height[u],distime[v]);
        }
    }
    return ;
}

int main()
{
    return 0;
}
















