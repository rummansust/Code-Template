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
#define mem(name,val) memset(name,(val),sizeof(name));
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


const int MAXN = 505; // number of elements.
int n; //n no. of vertices.
vector<int> g[MAXN];
int match[MAXN]; //stores the matcings
int p[MAXN]; //array of ancestors.
int base[MAXN]; //Node numbering after compression.
int q[MAXN]; //Queue
bool used[MAXN], blossm[MAXN];
int lca (int a, int b)
{
    bool used[MAXN] = { 0 };
// From the node a climb up to the roots,
//marking all even vertices
    for (;;)
    {
        a = base[a];
        used[a] = true;
        if (match[a] == -1) break; // Got the root
        a = p[match[a]];
    }
// Climb from node b,
//until we find the marked vertex
    for (;;)
    {
        b = base[b];
        if (used[b]) return b;
        b = p[match[b]];
    }
}
void mark_path (int v, int b, int children)
{
    while (base[v] != b)
    {
        blossm[base[v]]=blossm[base[match[v]]]=true;
        p[v] = children;
        children = match[v];
        v = p[match[v]];
    }
}
int find_path (int root)
{
    mem(used,0);
    mem(p,-1);
    for (int i=0; i<n; ++i)
        base[i] = i;
    used[root] = true;
    int qh=0, qt=0;
    q[qt++] = root;
    while (qh < qt)
    {
        int v = q[qh++];
        for (int i=0; i<g[v].size(); ++i)
        {
            int to = g[v][i];
            if (base[v] == base[to]
                    || match[v] == to) continue;
            if (to == root || match[to] != -1
                    && p[match[to]] != -1)
            {
                int curbase = lca (v, to);
                mem(blossm,0);
                mark_path (v, curbase, to);
                mark_path (to, curbase, v);
                for (int i=0; i<n; ++i)
                    if (blossm[base[i]])
                    {
                        base[i] = curbase;
                        if (!used[i])
                        {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
            }
            else if (p[to] == -1)
            {
                p[to] = v;
                if (match[to] == -1) return to;
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}
int graph_match()
{
    int ret = 0;
    mem(match,-1);
    for (int i=0; i<n; ++i)
        if (match[i] == -1)
        {
            int v = find_path (i);
            if(v!=-1) ret++;
            while (v != -1)
            {
                int pv = p[v], ppv = match[pv];
                match[v] = pv, match[pv] = v;
                v = ppv;
            }
        }
    return ret;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    while(scanf("%d %d",&i,&j)==2)
    {
        i--,j--;
        g[i].psb(j);
        g[j].psb(i);
    }
    int ans = graph_match();
    printf("%d\n",ans*2);
    for(i=0; i<n; i++)
        if(match[i]>-1)
        {
            printf("%d %d\n",i+1,match[i]+1);
            match[match[i]] = -1;
        }
    return 0;
}
