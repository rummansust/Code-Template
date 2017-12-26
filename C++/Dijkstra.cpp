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
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
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

struct qnode
{
    ll v,w;
    qnode() {}
    qnode(ll v,ll w):v(v),w(w) {}
    bool operator < (const qnode &x) const
    {
        return w>x.w;
    }
};

struct edge
{
    ll v,w;
    edge() {}
    edge(ll v,ll w):v(v),w(w) {}
};

vector<edge> adj[101005];
ll dist[100105];

void init(int n)
{
    for(int i=0; i<=n; i++) adj[i].clear();
    for(int i=0; i<=n; i++) dist[i]=oo;
    return ;
}

void dijkstra(int s)
{
    priority_queue<qnode> Q;

    int u,v;
    ll w;

    for(int i=0;i<s;i++)
    {
        SF("%d",&u);
        Q.push(qnode(u,0));
        dist[u]=0;
    }

    while(!Q.empty())
    {
        u=Q.top().v;
        Q.pop();
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i].v;
            w=adj[u][i].w;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                Q.push(qnode(v,dist[v]));
            }
        }
    }
    return ;
}

int main()
{
    int test,cas=0;
    int n,m,w,u,v,s;
    SF("%d %d",&n,&m);
    init(n+1);
    for(int i=0;i<m;i++)
    {
        SF("%d %d %d",&u,&v,&w);
        adj[u].psb(edge(v,w));
        adj[v].psb(edge(u,w));
    }
    SF("%d",&s);
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        PF("%lld\n",dist[i]);
    }
    return 0;
}













