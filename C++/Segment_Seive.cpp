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
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outR.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define SZ3 2147483647
#define SZ1 47900
#define SZ2 5080

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

char sieve[(SZ1>>4)+7];
int prime[SZ2];
char flag[(SZ3>>4)+7];

void bit_sieve()
{
    int i,j,k,r;
    prime[0]=2;
    k=1;
    int lim=(int)sqrt(SZ1)+1;
    for(i=3; i<SZ1; i+=2)
    {
        if(!(sieve[i>>4]&(1<<((i>>1)&7))))
        {
            prime[k++]=i;
            if(i<lim)
            {
                r=i<<1;
                for(j=i*i; j<SZ1; j+=r)
                {
                    sieve[j>>4]|=(1<<((j>>1)&7));
                }
            }
        }
    }
    return ;
}

vector<int> primeInRange;

int segmentSeive(int a,int b)
{
    int st,en,r,i,j,rr;
    primeInRange.clear();
    if(a<=2&&b>=2) primeInRange.psb(2);
    for(i=1;prime[i]&&prime[i]<=b;i++)
    {
        r=prime[i];
        st=max(r+r+r,(a/r+(a%r!=0))*r);
        if(!(st&1)) st+=r;
        en=(b/r)*r;
        rr=(r<<1);
        if(st>b) break;
        for(j=st;j<=en;j+=rr)
        {
            flag[j>>4]|=(1<<((j>>1)&7));
        }
    }
    for(int i=max(a,3);i<=b;i++)
    {
        if((i&1) && (!(flag[i>>4]&(1<<((i>>1)&7)))))
        {
            primeInRange.psb(i);
        }
    }
    return SZ(primeInRange);
}

int main(void)
{
    bit_sieve();
    int a,b,k,s,test,i,cnt;
    SF("%d",&test);
    while(test--)
    {
        SF("%d %d",&a,&b);
        deb(segmentSeive(a,b));
    }
    return 0;
}

















