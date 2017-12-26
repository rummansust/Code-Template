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
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)

using namespace std;

struct set_
{
    int par,rank_,member;
    set_(int p,int r,int m):par(p),rank_(r),member(m){}
};

struct edge
{
    int u,v,cost;
    edge(int u,int v,int w):u(u),v(v),cost(w){}
};

vector<edge> edge_list;
vector<set_> dset;
vector<edge> mst;

void make_set(int n)
{
    for(int i=0;i<=n;i++) dset.psb(set_(i,0,1));
    return ;
}

int find_par(int u)
{
    if(u!=dset[u].par) dset[u].par=find_par(dset[u].par);
    return dset[u].par;
}

bool union_set(int u,int v,int w)
{
    int up=find_par(u);
    int vp=find_par(v);
    if(up==vp) return false;
    dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
    mst.psb(edge(u,v,w));
    if(dset[up].rank_<dset[vp].rank_)
    {
        dset[up].par=dset[vp].par;
    }
    else
    {
        dset[vp].par=dset[up].par;
        if(dset[up].rank_==dset[vp].rank_)
        dset[up].rank_++;
    }
    return true;
}

bool cheak_connected(int n,int u)
{
    int up=find_par(u);
    if(dset[up].member!=n) return false;
    return true;
}

bool comp(edge a,edge b)
{
    return a.cost<b.cost;
}

int main()
{
    int n,m,u,v,w,res,test,cas=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        edge_list.clear();
        mst.clear();
        dset.clear();
        make_set(n);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge_list.psb(edge(u,v,w));
        }
        sort(edge_list.begin(),edge_list.end(),comp);
        for(int i=0;i<m;i++)
        {
            union_set(edge_list[i].u,edge_list[i].v,edge_list[i].cost);
        }
        printf("Case %d: ",++cas);
        if(!cheak_connected(n,edge_list[0].u))
        {
            printf("Not Connected\n");
        }
        else
        {
            res=0;
            for(int i=0;i<n-1;i++) res+=mst[i].cost;
            printf("%d\n",res);
        }
    }
    return 0;
}

/*
1
8 8
2 3 11
0 1 10
0 2 2
1 3 6
2 7 5
7 4 7
2 5 9
5 6 1
*/









