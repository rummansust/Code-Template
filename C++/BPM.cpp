#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> &vector name);
///make_pair  point=make_pair(i,j);
///access pair value point.first;point.second;

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int par[200],color[200];
vector<int> adj[200];

bool dfs(int u)
{
    if(color[u]) return false;
    color[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(par[v]==-1||dfs(par[v]))
        {
            par[v]=u;
            return true;
        }
    }
    return false;
}

int bpm(int n)
{
    clr(par,-1);
    int ret=0;

    for(int i=0; i<n; i++)
    {
        clr(color,0);
        if(dfs(i)) ret++;
    }
    return ret;
}

int main()
{
    vector<pair<double,double> > g,h;
    double x,y;
    int n,m;
    double t,v;
    while(cin>>n>>m>>t>>v)
    {
        g.clear();
        h.clear();
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            cin>>x>>y;
            g.psb(make_pair(x,y));
        }
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            h.psb(make_pair(x,y));
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                double x1=(g[i].first-h[j].first);
                double x2=(g[i].second-h[j].second);
                double d=sqrt(x1*x1+x2*x2);
                if((d/v)<=t) adj[i].psb(j);
            }
        }
        int res=bpm(n);
        cout<<n-res<<endl;
    }
    return 0;
}
