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
struct Edge
{
    int u,v,cap,indx;
    Edge(){}
    Edge(int u,int v,int cap,int indx):u(u),v(v),cap(cap),indx(indx) {}
};
const int MAX = 205;
vector<Edge> adj[MAX];
pair<int,int> par[MAX];
bool visited[MAX];
void addEdge(int from,int to,int cap)
{
    int id1,id2;
    adj[from].psb(Edge(from,to,cap,-1));
    id1=SZ(adj[from])-1;
    adj[to].psb(Edge(to,from,0,-1));
    id2=SZ(adj[to])-1;
    adj[from][id1].indx=id2;
    adj[to][id2].indx=id1;
    return ;
}
void updateEdge(int from,int indx,int val)
{
    adj[from][indx].cap+=val;
    return ;
}
bool augmentPath(int S,int E)
{
    int u=S,v,k,cap;
    queue<int> Q;
    Q.push(u);
    clrall(visited,0);
    clrall(par,-1);
    visited[u]=true;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        k=SZ(adj[u]);
        for(int i=0;i<k;i++)
        {
            v=adj[u][i].v;
            cap=adj[u][i].cap;
            if(visited[v]||!cap) continue;
            par[v]=mp(u,i);
            if(v==E) return true;
            visited[v]=true;
            Q.push(v);
        }
    }
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
    int flow=0;
    while(augmentPath(S,E))
    {
        flow+=getFlow(S,E);
    }
    return flow;
}
int main()
{
    int n,N,source,sink;
    int res,test,cas=0;
    int x[MAX],y[MAX],L,W,D,SD;
    SF("%d",&test);
    while(test--)
    {
        SF("%d %d %d %d",&L,&W,&n,&D);
        for(int i=1;i<=n;i++) SF("%d %d",&x[i],&y[i]);
        N=n+n+2;
        source=0;
        sink=N-1;
        SD=4*D*D;
        for(int i=0;i<=N;i++) adj[i].clear();
        for(int i=1;i<=n;i++) addEdge(i,i+n,1);
        for(int i=1;i<=n;i++)
        {
            if(y[i]<=D) addEdge(source,i,1);
            if(W-y[i]<=D) addEdge(i+n,sink,1);
            for(int j=1;j<=n;j++)
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= SD)
                {
                    addEdge(i+n,j,1);
                }
        }
        PF("Case %d: %d\n",++cas,maxFlow(source,sink));
    }
    return 0;
}
