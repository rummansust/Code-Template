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
#define Write freopen("out.txt","w",stdout)
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

///1 based index
const int MAX = 50110;

struct data
{
    int l,r,Size,id;
    data(){}
    data(int l,int r,int Size,int id):l(l),r(r),Size(Size),id(id) {}
};

bool comp(const data& a,const data& b)
{
    if(a.l/a.Size==b.l/b.Size)
        return a.r<b.r;
    return (a.l/a.Size<b.l/b.Size);
}

data info[MAX];
ll a[MAX];
ll qans[MAX];
int freq[MAX*10];

void add(int p,ll &ans)
{
    ans+=(a[p]*((freq[a[p]]<<1ll) + 1));
    freq[a[p]]++;
    return ;
}

void remove(int p,ll &ans)
{
    freq[a[p]]--;
    ans-=(a[p]*((freq[a[p]]<<1ll) + 1));
    return ;
}

void solve()
{
    int n,q;
    SF("%d %d",&n,&q);
    for(int i=0;i<n;i++) SF("%I64d",&a[i+1]);
    int Size = 1+(int)sqrt(n);
    for(int i=0;i<q;i++){
        SF("%d %d",&info[i].l,&info[i].r);
        info[i].Size=Size;
        info[i].id=i;
    }
    sort(info,info+q,comp);
    int lp=1,rp=0,lq,rq;
    ll ans=0;
    for(int i=0;i<q;i++){
        lq=info[i].l;
        rq=info[i].r;
        while(lp<lq) { remove(lp,ans); lp++; }
        while(rp<rq) { rp++; add(rp,ans); }
        while(rp>rq) { remove(rp,ans); rp--; }
        while(lp>lq) { lp--; add(lp,ans); }
        qans[info[i].id]=ans;
    }
    for(int i=0;i<q;i++) PF("%I64d\n",qans[i]);
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    solve();
    return 0;
}














