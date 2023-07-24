#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define xrange(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

const int mod = 7340033;
const ll root = 3;

ll getmod(ll a, ll tmod)
{
    return ((a%tmod)+tmod)%tmod;
}
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

void fft (vector<ll> & a, bool invert)
{
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i)
    {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1)
    {
        ll wlen=fp(root,(mod-1)/len);
        if(invert) wlen=fp(wlen,mod-2);
        for (int i=0; i<n; i+=len)
        {
            ll w = 1;
            for (int j=0; j<len/2; ++j)
            {
                ll u = a[i+j],  v = ll (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = getmod(u+v,mod);
                a[i+j+len/2] = getmod(u-v,mod);
                w = ll (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert)
    {
        ll inv=fp(n,mod-2);
        for(int i=0; i<n; i++)
            a[i]=a[i]*inv%mod;
    }
}

void multiply (const vector<ll> & a, vector<ll> & res)
{
    vector <ll> fa (a.begin(), a.end());
    size_t n = 1;
    while (n < a.size() ) n <<= 1;
    n <<= 1;
    fa.resize (n);
    fft (fa, false);///fft(fb,false);
    forn(i,n)
    fa[i] *= fa[i];///fa[i]*=fb[i];
    fft (fa, true);
    res.resize (n);
    forn(i,n)
    res[i] = fa[i] % mod;
}

int MN = 29;
int MK = 1001;
vector <vector <ll> > dp(MN+2,vector <ll> (MK,0));
vector <ll> d;

void init()
{
    int m;
    for (int i=0; i<=MN; i++)
    {
        dp[i][0] = 1;
        multiply(dp[i],d);
        d.resize(MK);
        multiply(d,dp[i+1]);
        dp[i+1].insert(dp[i+1].begin(),0);
        dp[i+1].resize(MK);
    }
}

int main()
{
    init();
    int tc;
    scanf("%d", &tc);
    forn(i,tc)
    {
        ll n,k;
        scanf("%I64d %I64d",&n,&k);
        int iter = 0;
        while (n>1 && n&1)
            iter++, n>>=1;
        printf("%I64d\n",dp[iter][k]);
    }
    return 0;
}
/**
248ms
*/
