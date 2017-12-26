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
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out1.txt","w",stdout)
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

const int MAX = 100005;

///0 based

using namespace std;

int tree[MAX][30],level[MAX],totchild[MAX],mxl;
vector<int> adj[MAX];

void init(int n)
{
    mxl=0;
    for(int i=0;i<=n;i++) adj[i].clear();
    clrall(tree,-1);
    clrall(level,0);
    clrall(totchild,0);
}

void dfs(int u,int par)
{
    int v;
    level[u]=level[par]+1;
    totchild[u]++;
    for(int i=0; i<SZ(adj[u]); i++)
    {
        v=adj[u][i];
        if(!level[v])
        {
            mxl=max(mxl,level[u]);
            tree[v][0]=u;
            dfs(v,u);
            totchild[u]+=totchild[v];
        }
    }
    return ;
}

void lca(int n)
{
    int h=1,i;
    for(i=0; (h<<i)<=mxl; i++);
    h=i-1;
    for(int i=1;i<=h;i++)
    {
        for(int u=0;u<n;u++)
        {
            tree[u][i]=tree[ tree[u][i-1] ][i-1];
        }
    }
    return ;
}

int query(int a,int b)
{
    int la=level[a],lb=level[b],ld;
    if(la>lb)
    {
        swap(a,b);
        swap(la,lb);
    }
    ld=lb-la;
    for(int i=0;;i++)
    {
        if((ld&1)&&tree[b][i]!=-1) b=tree[b][i];
        ld=(ld>>1);
        if(!ld) break;
    }
    if(a==b) return a;
    int j,h=1;
    for(j=0; (h<<j)<mxl; j++);
    h=j-1;
    for(int i=h;i>-1;i--)
    {
        if(tree[a][i]==tree[b][i]) continue;
        if(tree[a][i]==-1||tree[b][i]==-1) continue;
        a=tree[a][i];
        b=tree[b][i];
    }
    if(tree[a][0]!=-1) a=tree[a][0];
    return a;
}


///check u is an ancestor of v or not
bool isAncestor(int u,int v)
{
    if(u==-1 || v==-1) return false;
    if(level[u]>level[v]) return false;
    return true;
}

int findKthParent(int k,int u)
{
    for(int i=0;;i++)
    {
        if((k&1)&&tree[u][i]!=-1) u=tree[u][i];
        k=(k>>1);
        if(!k) break;
    }
    return u;
}


int solve(int u,int v,int n)
{
    if(u==v) return n;
    int res,dist,lchild,rchild,ancs,mchild,cmchild;
    ancs=query(u,v);
    dist=level[u]+level[v]-2*level[ancs] - 1;
    if(!(dist&1)) return 0;
    if(level[u]==level[v])
    {
        res=n;
        lchild=findKthParent((dist>>1),u);
        rchild=findKthParent((dist>>1),v);
        res=res-totchild[rchild]-totchild[lchild];
    }
    else
    {
        if(level[u]>level[v])
        {
            mchild=findKthParent((dist>>1)+1,u);
            cmchild=findKthParent((dist>>1),u);
            res=totchild[mchild]-totchild[cmchild];
        }
        else
        {
            mchild=findKthParent((dist>>1)+1,v);
            cmchild=findKthParent((dist>>1),v);
            res=totchild[mchild]-totchild[cmchild];
        }
    }
    return res;
}

int main()
{
    #ifdef MAHDI
    Read;
    Write;
    #endif // MAHDI
    int u,v,n,test,a,b,Q,cas=0,res,ni;
    while(SF("%d",&n)==1)
    {
        init(n+5);
        for(int i=0; i<n-1; i++)
        {
            SF("%d %d",&u,&v);
            u--;
            v--;
            adj[u].psb(v);
            adj[v].psb(u);
        }
        dfs(0,0);
        lca(n);
        SF("%d",&Q);
        int tq=Q;
        ni=0;
        while(Q--)
        {
            ni++;
            SF("%d %d",&a,&b);
            a--;
            b--;
            res=solve(a,b,n);
            PF("%d\n",res);
        }
    }
    return 0;
}
/*
11
11 10
0 1
0 2
2 3
2 4
4 5
5 6
6 7
7 8
8 9
9 10
*/















