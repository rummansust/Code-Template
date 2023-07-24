#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name))
#define EPS 1e-9
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
const ll root_pw = 1<<20;

ll getmod(ll a, ll tmod){
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

void fft (ll a[],int n, bool invert) {

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
const int MN = 29;
const int MK = 1001;

void multiply (ll a[], ll res[],int len) {
        fft (a, len, false);///fft(b,false);
        forn(i,len)
                a[i] *= a[i];///a[i]*=b[i];
        fft (a, len, true);
        forn(i,len)
                res[i] = a[i] % mod;
}


ll dp[MN+2][MK+2];
ll x[MK<<3];
ll x_[MK<<3];

void init(){
    clrall(dp,0);
    dp[0][0]=1;
    int len=4096;
    for(int i=1;i<=30;i++)
    {
        memset(x,0,sizeof(x));
        for(int j=0;j<MK;j++)
            x[j]=dp[i-1][j];
        multiply(x,x_,len);
        multiply(x_,x,len);
        for(int j=0;j<MK;j++)
            dp[i][j]=(j==0 ? 1 : x[j-1]);
    }
}

int main(){
#ifdef dudkamaster
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
#endif
//    precalc();
        init();
        int tc;
        scanf("%d", &tc);
        forn(i,tc){
                ll n,k;
                sf("%I64d %I64d",&n,&k);
                int iter = 0;
                while (n>1 && n&1)
                        iter++, n>>=1;
                pf("%I64d\n",dp[iter][k]);
        }
        return 0;
}
/**
404ms
*/
