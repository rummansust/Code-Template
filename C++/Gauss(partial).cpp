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
#define Write freopen("10828.txt","w",stdout)
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

int EQ(long double x) {
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

const int MAXN = 105;

double a[MAXN][MAXN];
double ans[MAXN];
bool infsol[MAXN];
int where[MAXN];
int mat[MAXN][MAXN];
int pos[MAXN];
/**
gauss for partial solution
*/
void gauss (int N) {
    int n = N;
    int m = N;
    int i,j;
    for(i = 0; i < n; i++) {
        int k = i;
        for(j = i+1; j < n; j++)
            if(abs(a[k][i]) < abs(a[j][i]))
                k = j;
        if(EQ(a[k][i]) == 0)
            continue;
        if(k != i) {
            for(j = 0; j <=m ; j++)
                swap(a[k][j], a[i][j]);
        }
        for(j = 0; j < n; j++) {
            if(i == j)  continue;
            for(k = m; k >= i; k--) {
                a[j][k] -= a[j][i]/a[i][i]*a[i][k];
            }
        }
    }
    clrall(infsol,0);
    for(int i=n-1;i>-1;i--)
    {
        if(EQ(a[i][m]) && EQ(a[i][i]) == 0)
        {
            infsol[i]=true;
        }
        else
        {
            if(EQ(a[i][m]) == 0) ans[i] = 0;
            else ans[i] = a[i][m]/a[i][i];
        }
        for(int j=i+1;j<n;j++)
        {
            if(EQ(a[i][j]) && infsol[j])
            {
                infsol[i]=true;;
            }
        }
    }
    return ;
}

int main() {
#ifdef MAHDI
//    Read;
    Write;
#endif // MAHDI
    int n,q,ind[MAXN],u,v,cas=0;
    while(sf("%d",&n)==1 && n) {
        clrall(ind,0);
        clrall(mat,0);
        while(sf("%d %d",&u,&v)==2 && u+v) {
            u--;
            v--;
            ind[u]++;
            mat[v][u]++;
        }
        clrall(a,0);
        for(int i=0; i<n; i++) {
            if(i==0) a[i][n]=1;
            a[i][i]=1;
            for(int j=0; j<n; j++) {
                if(mat[i][j]) {
                    a[i][j]-=(1.0*(mat[i][j]))/(double)(ind[j]);
                }
            }
        }
        gauss(n);
        pf("Case #%d:\n",++cas);
        sf("%d",&q);
        while(q--) {
            sf("%d",&u);
            u--;
            if(infsol[u]) pf("infinity\n");
            else pf("%.3f\n",abs(ans[u]));
        }
    }
    return 0;
}
/**
8
1 1
1 1
1 2
1 3
1 3
1 4
4 5
5 4
6 7
7 6
8 1
0 0
8 1 2 3 4 5 6 7 8
0
*/

/**
8
1 2
1 3
1 4
4 5
5 4
6 7
7 6
8 1
0 0
8 1 2 3 4 5 6 7 8
0
*/











