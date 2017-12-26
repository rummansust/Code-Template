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
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint cout<<"Case "<<(++cas)<<": ";

const int MAX = 1020;
ll dp[MAX][MAX];
int mid[MAX][MAX];

ll pos[MAX];

ll knuthTrick(int n)
{
    for(int s=0;s<=n;s++)
    {
        for(int L=0;L+s<=n;L++)
        {
            int R=L+s;
            if(s<2)
            {
                dp[L][R]=0;
                mid[L][R]=L;
                continue;
            }
            int midLeft = mid[L][R-1];
            int midRight = mid[L+1][R];
            ll cost = pos[R]-pos[L];
            ll cur;
            dp[L][R]=(1ll<<60);
            for(int M=midLeft;M<=midRight;M++)
            {
                cur = dp[L][M]+dp[M][R]+cost;
                if(dp[L][R]>cur)
                {
                    dp[L][R] = cur;
                    mid[L][R] = M;
                }
            }
        }
    }
    return dp[0][n];
}

int main()
{
    __;
    int n;
    ll m;
    while(cin>>m>>n)
    {
        pos[0]=0;
        pos[n+1]=m;
        for(int i=1;i<=n;i++)
        {
            cin>>pos[i];
        }
        cout<<knuthTrick(n+1)<<"\n";
    }
    return 0;
}










