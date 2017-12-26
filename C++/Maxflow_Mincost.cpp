#include "bits/stdc++.h"
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
struct data
{
    int u;
    int cost;
    data(){}
    data(int u,int cost):u(u),cost(cost){}
    bool operator < (const data &x) const
    {
        return x.cost<cost;
    }
};
struct Edge
{
    int u,v,cap,indx;
    int cost;
    Edge(){}
    Edge(int u,int v,int cap,int indx,int cost):u(u),v(v),cap(cap),indx(indx),cost(cost) {}
};
const int MAX = 220;
vector<Edge> edgeList,adj[MAX];
pair<int,int> par[MAX];
int Cost[MAX];
inline void addEdge(int from,int to,int cap,int cost)
{
    int id1,id2;
    adj[from].psb(Edge(from,to,cap,-1,cost));
    id1=SZ(adj[from])-1;
    adj[to].psb(Edge(to,from,0,-1,-cost));
    id2=SZ(adj[to])-1;
    adj[from][id1].indx=id2;
    adj[to][id2].indx=id1;
    return ;
}
inline void updateEdge(int from,int indx,int val)
{
    adj[from][indx].cap+=val;
    return ;
}
bool augmentPath(int S,int E)
{
    for(int i=S;i<=E;i++) Cost[i]=(int) oo,par[i]=mp(-1,-1);
    Cost[S]=0;
    priority_queue<data> Q;
    Q.push(data(S,0));
    int u,v,cap;
    int cost;
    int cnt=0;
    while(!Q.empty())
    {
        cnt++;
        u=Q.top().u;
        Q.pop();
        for(int i=0;i<SZ(adj[u]);i++)
        {
            v=adj[u][i].v;
            cost=adj[u][i].cost;
            cap=adj[u][i].cap;
            if(Cost[v]>cost+Cost[u] && cap)
            {
                Cost[v]=Cost[u]+cost;
                Q.push(data(v,Cost[v]));
                par[v]=mp(u,i);
            }
        }
    }
    if(Cost[E]!=oo) return true;
    return false;
}
int getFlow(int S,int E)
{
    int from,to,idf,idt;
    int minEdge=(int) INFINITY;
    to=E,from=par[to].fs;
    idt=par[to].sc;
    while(from!=-1)
    {
        minEdge=min(minEdge,adj[from][idt].cap);
        to=from;
        from=par[to].fs;
        idt=par[to].sc;
    }
    to=E,from=par[to].fs;
    idt=par[to].sc;
    while(from!=-1)
    {
        idf=adj[from][idt].indx;
        updateEdge(from,idt,-minEdge);
        updateEdge(to,idf,minEdge);
        to=from;
        from=par[to].fs;
        idt=par[to].sc;
    }
    return minEdge;
}
int maxFlow(int S,int E)
{
    int flow=0,ret=0;
    while(augmentPath(S,E))
    {
        flow=getFlow(S,E);
        ret+=(flow*Cost[E]);
    }
    return ret;
}
int main()
{
    int n,m,N,source,sink;
    int res,value,test,cas=0;
    SF("%d",&test);
    while(test--)
    {
        SF("%d",&n);
        m=n;
        int k=2*n;
        N=2*k+2;
        source=0;
        sink=N-1;
        for(int i=0;i<N;i++) adj[i].clear();
        for(int i=1;i<=k;i++) addEdge(i,i+k,1,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                SF("%d",&value);
                addEdge(i+k,j+n,1,value);
            }
        for(int i=1;i<=n;i++) addEdge(source,i,1,0);
        for(int i=n+1;i<=k;i++) addEdge(i+k,sink,1,0);
        int ret = maxFlow(source,sink);
        PF("Case %d: %d\n",++cas,ret);
    }
    return 0;
}
