#if DEBUG
#pragma GCC optimize("Ofast,fast-math,unroll-loops,O3")
#endif
#if DEBUG
#include <filesystem>
#endif

#include <assert.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using namespace std::chrono;
#if DEBUG
using namespace std::filesystem;
#endif

#define SZ(x) ((int)x.size())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define clrall(name, val) memset(name, (val), sizeof(name))
#define eraseDuplicate(v) v.resize(distance(v.begin(), unique(all(v))))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define Double long double
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1 << 28)
#define mp make_pair
#define mt make_tuple
#define get(a, b) get<b>(a)
#define fs first
#define sc second
#define __ std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl "\n"
#define casePrint(cas) cout << "Case " << cas << ": "
#define casePrintNL(cas) cout << "Case " << cas << ":\n"

template <class T1>
void deb(T1 e1)
{
    cerr << e1 << "\n";
}
template <class T1, class T2>
void deb(T1 e1, T2 e2)
{
    cerr << e1 << " " << e2 << "\n";
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3)
{
    cerr << e1 << " " << e2 << " " << e3 << "\n";
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    cerr << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
         << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6, T7 e7)
{
    cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
         << " " << e7 << "\n";
}

typedef pair<int, int> pii;
typedef pair<pii, pii> link_type;

// Template taken from https://github.com/ShahjalalShohag/code-library/blob/1c0a7de76ca4e645af23688f6ab524053a39a6fd/Graph%20Theory/Directed%20MST.cpp
const long long inf = 1e12;

template <typename T>
struct PQ
{
    ll sum = 0;
    priority_queue<T, vector<T>, greater<T>> Q;
    void push(T x)
    {
        x.w -= sum;
        Q.push(x);
    }
    T pop()
    {
        auto ans = Q.top();
        Q.pop();
        ans.w += sum;
        return ans;
    }
    int size() { return Q.size(); }
    void add(ll x) { sum += x; }
    void merge(PQ &&x)
    {
        if (size() < x.size())
            swap(sum, x.sum), swap(Q, x.Q);
        while (x.size())
        {
            auto tmp = x.pop();
            tmp.w -= sum;
            Q.push(tmp);
        }
    }
};
struct edge
{
    int u, v;
    ll w;
    bool operator>(const edge &rhs) const { return w > rhs.w; }
};
struct DSU
{
    vector<int> par;
    DSU(int n) : par(n, -1) {}
    int root(int i) { return par[i] < 0 ? i : par[i] = root(par[i]); }
    void set_par(int c, int p) { par[c] = p; }
};

// returns parents of each vertex
// each edge should be distinct
// it assumes that a solution exists (all vertices are reachable from root)
// 0 indexed
// Takes ~300ms for n = 2e5
vector<int> DMST(int n, int root, const vector<edge> &edges)
{
    vector<int> u(2 * n - 1, -1), par(2 * n - 1, -1);
    edge par_edge[2 * n - 1];
    vector<int> child[2 * n - 1];

    PQ<edge> Q[2 * n - 1];
    for (auto e : edges)
        Q[e.v].push(e);
    for (int i = 0; i < n; i++)
        Q[(i + 1) % n].push({i, (i + 1) % n, inf});

    int super = n;
    DSU dsu(2 * n - 1);
    int head = 0;
    while (Q[head].size())
    {
        auto x = Q[head].pop();
        int nxt_root = dsu.root(x.u);
        if (nxt_root == head)
            continue;
        u[head] = nxt_root;
        par_edge[head] = x;
        if (u[nxt_root] == -1)
            head = nxt_root;
        else
        {
            int j = nxt_root;
            do
            {
                Q[j].add(-par_edge[j].w);
                Q[super].merge(move(Q[j]));
                assert(u[j] != -1);
                child[super].push_back(j);
                j = dsu.root(u[j]);
            } while (j != nxt_root);
            for (auto u : child[super])
                par[u] = super, dsu.set_par(u, super);
            head = super++;
        }
    }
    vector<int> res(2 * n - 1, -1);
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        while (par[u] != -1)
        {
            for (auto v : child[par[u]])
            {
                if (v != u)
                {
                    res[par_edge[v].v] = par_edge[v].u;
                    q.push(par_edge[v].v);
                    par[v] = -1;
                }
            }
            u = par[u];
        }
    }
    res[root] = root;
    res.resize(n);
    return res;
}

void printEdges(vector<edge> &edges)
{
    for (auto &e : edges)
    {
        deb(e.u, e.v, e.w);
    }
    return;
}

bool canReachAllNodes(int n, vector<edge> &edges)
{
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        auto u = e.u, v = e.v;
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, false);
    vis[0] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            return false;
    }
    return true;
}

int go(int n, vector<edge> &edges)
{
    if (!canReachAllNodes(n, edges))
        return INT_MAX;
    auto res = DMST(n, 0, edges);
    unordered_map<int, int> W[n];
    for (auto u : edges)
        W[u.v][u.u] = u.w;

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += W[i][res[i]];
    return ans;
}

vector<edge> get_edges(int n, int b_threshold, vector<link_type> &links)
{
    vector<edge> edges;
    unordered_map<int, int> tMap[n];
    for (auto &e : links)
    {
        auto u = e.first.first, v = e.first.second;
        auto b = e.second.first, w = e.second.second;
        if (b >= b_threshold)
        {
            if (tMap[u].find(v) == tMap[u].end())
            {
                tMap[u][v] = w;
            }
            else
            {
                tMap[u][v] = min(tMap[u][v], w);
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        for (auto it : tMap[u])
        {
            edges.push_back({u, it.first, it.second});
        }
    }
    return edges;
}

int solve(int n, int maxB, int C, vector<link_type> &links)
{
    vector<edge> edges = get_edges(n, 0, links);
    if (!canReachAllNodes(n, edges))
        return -1;
    int lo = 1, hi = maxB, mid, resB = -1;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        edges = get_edges(n, mid, links);
        int res = go(n, edges);
        if (res <= C)
        {
            resB = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return resB;
}

// Problem: https://lightoj.com/problem/stream-my-contest
void work()
{
    int t, cas = 1;
    cin >> t;
    while (t--)
    {
        int n, m, c, u, v, b, w, maxB = 0;
        cin >> n >> m >> c;
        vector<link_type> links(m);
        for (auto &e : links)
        {
            cin >> u >> v >> b >> w;
            e = {{u, v}, {b, w}};
            maxB = max(maxB, b);
        }
        int res = solve(n, maxB, c, links);
        casePrint(cas++);
        if (res == -1)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << res << " kbps" << endl;
        }
    }

    return;
}

int main(int argc, char *argv[])
{
#if DEBUG
    path executablePath = argv[0];
    path currentDir = executablePath.parent_path();
    path inputFile = currentDir / "in-dir.txt";
    path outputFile = currentDir / "out-dir.txt";
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);
#endif
    __;
#if DEBUG
    auto start = high_resolution_clock::now();
#endif
    work();
#if DEBUG
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() / 1000000.0
         << " seconds\n";
#endif
    return 0;
}