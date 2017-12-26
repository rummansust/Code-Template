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

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define clrint(name,val,s) memset(name,(val),sizeof(int)*s);
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS 10e-6
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1LL<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("input.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

using namespace std;

template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a>b?b:a;}
template<class T>inline T _GCD(T a,T b){if(b==0) return a;return _GCD(b,a%b);}
template<class T>inline T _LCM(T a,T b){T g=_GCD(a,b);return ((a/g)*b);}
template<class T>inline T big_mod(T a,T p,T MOD){if(p==0) return 1;T ret=big_mod(a,p/2,MOD);ret=(ret*ret)%MOD;if(ret<0) ret+=MOD;if(p%2) ret=(ret*a)%MOD;if(ret<0) ret+=MOD;return ret;}
template<class T>inline T power(T a,T p){if(p==0) return 1;ll ret=power(a,p/2);ret=(ret*ret);if(p%2) ret=(ret*a);return ret;}
template<class T0,class T1,class T2>inline T1 string_mod_ll(T0 s,T1 mm,T2 Sz){T1 n=0;for(int i=0;i<Sz;i++){n=n*10+(ll)(s[i]-'0');n%=mm;}return n;}

int compare(string a,string b){if(a==b) return 0;if(SZ(a)==SZ(b)){for(int i=0; i<SZ(a); i++){if(a[i]>b[i]) return 1;else if(a[i]<b[i]) return -1;}return -1;}if(SZ(a)>SZ(b)) return 1;return -1;}
string string_add(string b,string a){if(SZ(a)>SZ(b)) swap(a,b);a=string((SZ(b)-SZ(a)),'0')+a;int carry=0,add;string res;for(int i=SZ(a)-1; i>-1; i--){add=(int)(a[i]-'0')+(int)(b[i]-'0')+carry;carry=add/10;res+=(add%10)+'0';}if(carry) res+=carry+'0';reverse(res.begin(),res.end());return res;}
string string_mul(string a,string b){if(SZ(a)>SZ(b)) swap(a,b);string res,tres;int l=0,carry,mul;for(int i=SZ(a)-1; i>-1; i--){tres=string(l,'0');carry=0;for(int j=SZ(b)-1; j>-1; j--){mul=(int)(a[i]-'0')*(int)(b[j]-'0')+carry;carry=mul/10; tres+=(mul%10)+'0'; }if(carry) tres+=carry+'0';reverse(tres.begin(),tres.end());res=string_add(tres,res);l++;}return res;}
void cut_leading_zero(string &res){int i;for(i=0; i<SZ(res); i++){if(res[i]!='0') break;}res=res.substr(i);if(!SZ(res)) res="0";return;}

///pass a vector to a funtion: funtion (vector <data type> &vector name);
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

struct edge
{
    int u,v,c;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),c(c){}
};

int Cap[55][55];
int N;
int MaxFlow;
bool col[55];
int par[55];
vector<int> adj[55],setCut;
vector<pair<int,int> > edge_list;

void addEdge(int,int,int);

bool SPFA(int,int);

void augmentPath(int,int);

void MinCut(int);

int main()
{
//    read_;
    int c;
    int it1,it2,it3;
    int m,u,v,S,T,n;
    while(~SF("%d %d",&n,&m))
    {
        if(n==0&&m==0) return 0;
        N=n;
        edge_list.clear();
        setCut.clear();
        MaxFlow=0;
        rep(it1,1,N+1,1)
        {
            rep(it2,1,N+1,1) Cap[it1][it2]=0;
            adj[it1].clear();
        }
        while(m--)
        {
            SF("%d %d %d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
            adj[u].psb(v);
            adj[v].psb(u);
            edge_list.psb(mp(u,v));
        }
        S=1;
        T=2;
        while(SPFA(S,T))
        {
            augmentPath(S,T);
        }
        clrall(col,0);
        MinCut(S);
        rep(it1,0,SZ(setCut),1)
        {
            u=setCut[it1];
            rep(it2,0,SZ(adj[u]),1)
            {
                v=adj[u][it2];
                if(col[u]&&col[v]) continue;
                PF("%d %d\n",u,v);
            }
        }
        PF("\n");
    }
    return 0;
}

void addEdge(int u,int v,int c)
{
    Cap[u][v]+=c;
    return ;
}

void updateEdge(int u,int v,int c)
{
    Cap[v][u]-=c;
    return ;
}

bool SPFA(int S,int E)
{
    int it1;
    rep(it1,1,N+1,1) col[it1]=false,par[it1]=0;
    int u=S,v;
    queue<int> Q;
    Q.push(u);
    col[u]=true;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();

        rep(it1,0,SZ(adj[u]),1)
        {
            v=adj[u][it1];
            if(Cap[u][v] && !col[v])
            {
                Q.push(v);
                col[v]=true;
                par[v]=u;
                if(v==E) return true;
            }
        }
    }

    return false;
}

void augmentPath(int S,int E)
{
    int minEdge=oo;
    int u=E,v=par[E];
    while(v)
    {
        minEdge = min(minEdge,Cap[v][u]);
        u=v;
        v=par[u];
    }
    u=E,v=par[E];
    while(v)
    {
        updateEdge(u,v,minEdge);
        addEdge(u,v,minEdge);
        u=v;
        v=par[u];
    }
    MaxFlow+=minEdge;
    return ;
}

void MinCut(int u)
{
    setCut.psb(u);
    col[u]=true;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(!col[v]&&Cap[u][v]>0)
        {
            MinCut(v);
        }
    }
    return ;
}



















