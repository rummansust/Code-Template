/**SUFFIX AUTOMATA*/
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

#define deb1(a0) cerr<<#a0<<" = "<<a0<<endl
#define deb2(a0,a1) cerr<<#a0<<" = "<<a0<<", "<<#a1<<" = "<<a1<<endl
#define deb3(a0,a1,a2) cerr<<#a0<<" = "<<a0<<", "<<#a1<<" = "<<a1<<", "<<#a2<<" = "<<a2<<endl

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out2.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define MAX 1001000
struct info
{
    int par,len;
    int child[26];
};
info T[(MAX<<1)];
bool flag[MAX<<1];
bool vis[MAX<<1];
int cnt[(MAX<<1)];
int last,it=0;
char text[MAX],str[MAX];
void init(const int &);
void suffix_automata(int);
void add_char(int id);
void add_char(int id)
{
    int cur,clone,pre,next;
    cur=it++;
    init(cur);
    /**increment length;*/
    T[cur].len=T[last].len+1;
    /**parent to child connection;*/
    for(pre=last;pre!=-1&&T[pre].child[id]==-1;pre=T[pre].par) T[pre].child[id] = cur;
    /**find parent of current node or clone node if needed;*/
    if(pre==-1) T[cur].par=0;
    else
    {
        /**
        clone node needed if cur node is not the next node of pre;
        we need to split the edge. but it's unnecessary to split
        when two nodes are adjacent(means the length difference is one).
        */
        next=T[pre].child[id];
        if(T[next].len==T[pre].len+1) T[cur].par=next;
        else
        {
            /**
            make clone node and copy all data from which node
            is responsible for repeating to clone node;
            */
            clone=it++;
            flag[clone]=true;
            init(clone);
            T[clone]=T[next];
            T[clone].len=T[pre].len+1;
            for(;T[pre].child[id]==next;pre=T[pre].par) T[pre].child[id]=clone;
            T[cur].par=T[next].par=clone;
        }
    }
    last=cur;
    return ;
}
void init(const int &node)
{
    T[node].len=0;
    T[node].par=-1;
    clrall(T[node].child,-1);
    return ;
}
void suffix_automata()
{
    memset(flag,0,sizeof(bool)*(it+1));
    memset(vis,0,sizeof(bool)*(it+1));
    memset(cnt,0,sizeof(int)*(it+1));
    flag[0]=true;
    last=0;
    it=1;
    init(0);
    for(int i=0;text[i];i++) add_char(text[i]-'a');
    return ;
}

void precal(int u)
{
    if(vis[u]) return ;
    vis[u]=true;
    cnt[u]+=!flag[u];
    int v;
    for(int i=0;i<26;i++)
    {
        v=T[u].child[i];
        if(v!=-1)
        {
            precal(v);
        }
    }
    if(T[u].par!=-1)
    {
        cnt[T[u].par]+=cnt[u];
    }
    return ;
}

int count_occ()
{
    int cnode=0,c;
    for(int i=0;str[i];i++)
    {
        c=str[i]-'a';
        if(T[cnode].child[c]==-1) return 0;
        cnode=T[cnode].child[c];
    }
    return cnt[cnode];
}

int main()
{
    int test,q,cas=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&q);
        scanf("%s",&text);
        suffix_automata();
        precal(0);
        pf("Case %d:\n",++cas);
        while(q--)
        {
            scanf("%s",&str);
            printf("%d\n",count_occ());
        }
    }
    return 0;
}








