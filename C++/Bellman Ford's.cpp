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

#define MAX 2050

/// complexity V*E
/// 0 based
struct Edge
{
    int a,b,w;
};

Edge adj[MAX];
int dist[MAX];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=oo;
    }
    return ;
}
bool bellmanford(int s,int n,int m)
{
    dist[s]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[adj[j].a]==oo) continue;
            if(dist[adj[j].a]+adj[j].w<dist[adj[j].b])
            {
                dist[adj[j].b]=dist[adj[j].a]+adj[j].w;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(dist[adj[i].b]>adj[i].w+dist[adj[i].a])
        return false;///negative cycle
    }
    return true;
}
int main()
{
    int n,m,test,u,v,c,source,destination;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            adj[i].a=u;
            adj[i].b=v;
            adj[i].w=c;
        }
        if(bellmanford(0,n,m)) printf("Impossible\n");
        else printf("Possible\n");

    }
    return 0;
}
