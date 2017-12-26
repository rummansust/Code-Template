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
#define clrall(name,val) memset(name,(val),sizeof(name))
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
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {
    ll R=0;
    while(P>0)      {
        if((P&1ll)==1) {
            R=(R+B);
            if(R>=M) R-=M;
        }
        P>>=1ll;
        B=(B+B);
        if(B>=M) B-=M;
    }
    return R;
}

ll MulModD(ll B, ll P,ll M) {
    ll I=((long double)B*(long double)P/(long double)M);
    ll R=B*P-M*I;
    R=(R%M+M)%M;
    return R;
}

ll BigMod(ll B,ll P,ll M) {
    ll R=1;    /// (B^P)%M
    while(P>0)      {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

ll BigModML(ll B,ll P,ll M) {
    ll R=1;    /// (B^P)%M
    while(P>0)      {
        if(P%2==1) {
            R=MulModL(R,B,M);
        }
        P/=2;
        B=MulModL(B,B,M);
    }
    return R;
}

template<class T1> void deb(T1 e1) {
    cout<<e1<<"\n";
}
template<class T1,class T2> void deb(T1 e1,T2 e2) {
    cout<<e1<<" "<<e2<<"\n";
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3) {
    cout<<e1<<" "<<e2<<" "<<e3<<"\n";
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";
}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7) {
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";
}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

const int MAXM = 105;
const int MAXN = 505;

bitset<MAXM> a[MAXN];
int n,m;
ll gauss () {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;
        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }

    ll res=0;
    int p=0;
    for(int i=0; i<m; i++) {
        if(where[i]==-1) { ///independant variable
            p++;
        }
    }
    for(int i=0; i<p; i++) {
        res|=1ll<<i;
    }
    return res;
}


int main() {
#ifdef MAHDI
    Read;
    Write;
#endif // MAHDI

    int prime[MAXN],k=0;
    bool flag[MAXN];
    clrall(flag,0);
    prime[k++]=2;
    for(int i=3; i<MAXN; i+=2) {
        if(!flag[i]) {
            prime[k++]=i;
            for(int j=i*i; j<MAXN; j+=2*i) flag[j]=true;
        }
    }
    n=k;
    ll v;
    int t;
    sf("%d",&t);
    while(t--) {
        sf("%d",&m);
        for(int i=0; i<n; i++) a[i].reset();
        for(int i=0; i<m; i++) {
            sf("%lld",&v);
            for(int j=0; j<n; j++) {
                int c=0;
                if(!v) break;
                while(v%prime[j]==0) {
                    c++;
                    v/=prime[j];
                }
                c&=1;
                if(c) a[j].set(i);
            }
        }
        pf("%lld\n",gauss());
    }

    return 0;
}
















