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
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("DL2.in","r",stdin)
#define Write freopen("DL2.out","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

/// 1 based

const int MAX = 3010;
int grid[MAX][MAX],n;
ll A[3010];
ll B[3010];
int tree[MAX<<2][MAX<<2];

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			tree[vx][vy] = grid[lx][ly];
		else
			tree[vx][vy] = max(tree[vx*2][vy] , tree[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		build_y (vx, lx, rx, vy*2, ly, my);
		build_y (vx, lx, rx, vy*2+1, my+1, ry);
		tree[vx][vy] = max(tree[vx][vy*2] , tree[vx][vy*2+1]);
	}
}

void build_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x (vx*2, lx, mx);
		build_x (vx*2+1, mx+1, rx);
	}
	build_y (vx, lx, rx, 1, 1, n);
}

int max_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return tree[vx][vy];
	int tmy = (tly + try_) / 2;
	return max(max_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		, max_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}

int max_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return max_y (vx, 1, 1, n, ly, ry);
	int tmx = (tlx + trx) / 2;
	return max(max_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		, max_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}

int main(void)
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    int cas,t=1,k;
    ll C,X;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d %lld %lld",&n,&k,&C,&X);
        for(int i=1;i<=n;i++) sf("%lld",&A[i]);
        for(int i=1;i<=n;i++) sf("%lld",&B[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                grid[i][j]=(A[i]*(ll)i + B[j]*(ll)j + C)%X;
            }
        }
        ll res=0;
        build_x(1,1,n);
        for(int i=1;i<=n-k+1;i++)
        {
            for(int j=1;j<=n-k+1;j++)
            {
                res+=max_x(1,1,n,i,i+k-1,j,j+k-1);
            }
        }
        pf("Case #%d: %lld\n",t++,res);
    }
    return 0;
}

/*


1
3
1 2 3
4 5 6
7 8 9
5
2 2 1
3 2 3
1 1 3
1 2 3
2 2 3


*/
