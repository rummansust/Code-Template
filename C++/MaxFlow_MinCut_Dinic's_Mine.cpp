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
#define clrall(name,val) memset(name,(val),sizeof(name));
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outMyTest.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

struct Edge
{
    int to,toIndex,cap,flow;
    Edge(){}
    Edge(int to,int toIndex,int cap,int flow):to(to),toIndex(toIndex),cap(cap),flow(flow){}
};
const int MAX = 120;
vector<Edge> adj[MAX];
int dist[MAX];
pair<int,int> par[MAX];
void addEdge(int from,int to,int cap)
{
    if(from==to) return ;
    int indxft=SZ(adj[from]),indxtf=SZ(adj[to]);
    adj[from].psb(Edge(to,indxtf,cap,0));
    adj[to].psb(Edge(from,indxft,0,0));
    return ;
}
bool dinicBfs(int S,int E)
{
    int from=S,to,fromIndex,toIndex,cap,flow;
    queue<int> Q;
    clrall(dist,0);
    clrall(par,-1);
    dist[from]=1;
    Q.push(from);
    while(!Q.empty())
    {
        from=Q.front(),Q.pop();
        int k=SZ(adj[from]);
        for(int i=0;i<k;i++)
        {
            to=adj[from][i].to;
            cap=adj[from][i].cap;
            flow=adj[from][i].flow;
            if(!dist[to] && (cap-flow)>0)
            {
                dist[to]=dist[from]+1;
                par[to]=mp(from,i);
                Q.push(to);
            }
        }
    }
    return (dist[E]!=0);
}
int dinicUpdate(int S,int E)
{
    int k=SZ(adj[E]);
    int from,to,fromIndex,toIndex,minEdge,flow=0;
    for(int i=0;i<k;i++)
    {
        to=E;
        toIndex = adj[to][i].toIndex;
        from=adj[to][i].to;
        fromIndex = adj[from][toIndex].toIndex;
        minEdge=(int) INFINITY;
        while(from!=-1)
        {
            minEdge=min(minEdge,adj[from][toIndex].cap-adj[from][toIndex].flow);
            if(minEdge<=0) break;
            to=from;
            from=par[to].fs;
            toIndex=par[to].sc;
        }
        if(minEdge<=0 || to!=S) continue;
        to=E;
        toIndex = adj[to][i].toIndex;
        from=adj[to][i].to;
        fromIndex = adj[from][toIndex].toIndex;
        while(from!=-1)
        {
            adj[from][toIndex].flow+=minEdge;
            adj[to][fromIndex].flow-=minEdge;
            to=from;
            from=par[to].fs;
            if(from==-1) break;
            toIndex=par[to].sc;
            fromIndex=adj[from][toIndex].toIndex;
        }
        flow+=minEdge;
    }
    return flow;
}
int maxFlow(int S,int E)
{
    int totFlow = 0,cnt=0,ret;
    while(dinicBfs(S,E))
    {
        ret = dinicUpdate(S,E);
        totFlow+=ret;
    }
    return totFlow;
}
int main()
{
    int test,cas=0,u,v,c,n,m,source,sink;
    SF("%d",&test);
    while(test--)
    {
        SF("%d %d %d %d",&n,&source,&sink,&m);
        for(int i=0;i<=n;i++) adj[i].clear();
        while(m--)
        {
            SF("%d %d %d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
        }
        PF("Case %d: %d\n",++cas,maxFlow(source,sink));
    }
    return 0;
}
