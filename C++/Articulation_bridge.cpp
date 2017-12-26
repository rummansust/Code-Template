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
int distime[MAXN],height[MAXN],root,id;

void init(int n)
{
    bridge.clear();
    for(int i=0; i<=n; i++) adj[i].clear();
    clrall(distime,0);
    clrall(height,0);
    id=1;
    return ;
}

void dfs_bridge(int u,int par)
{
    int v,p,q;
    distime[u]=height[u]=id++;
    for(int i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!distime[v])
        {
            dfs_bridge(v,u);
            height[u]=min(height[u],height[v]);///height update.
            if(distime[u]<height[v])
            {
                p=u,q=v;
                if(p>q) swap(p,q);
                bridge.psb(mp(p,q));///find bridge.
            }
        }
        else if(distime[u]>distime[v]) height[u]=min(distime[v],height[u]);
    }
    return ;
}

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.fs==b.fs) return a.sc<b.sc;
    return a.fs<b.fs;
}

int main()
{
    int n,m,test,cas=0,u,v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].psb(v);
            adj[v].psb(u);
        }
        for(int i=0; i<n; i++)
        {
            if(!distime[i])
            {
                root=i;
                dfs_bridge(i,-1);
            }
        }
        cout<<bridge.size()<<endl;
        sort(bridge.begin(),bridge.end(),comp);
        for(int i=0;i<bridge.size();i++)
        {
            cout<<bridge[i].fs<<" "<<bridge[i].sc<<endl;
        }
    }
    return 0;
}
/*
5
8 7
0 1
5 0
1 2
2 3
3 4
6 7
1 3
*/
