
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
#include <unordered_map>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

ll BigModML(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M
template<class T> T _gcd(T a, T b){ T c = a % b; while(c != 0) { a = b; b = c; c = a % b; } return b;}
template<class T>inline T _lcm(T a,T b){T g=_gcd(a,b);return ((a/g)*b);}
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

const int MAX = 110000;
char sieve[(MAX>>4) + 7];
int phi[MAX];
ll M=1000000007LL;

void sieve_phi()
{
  int r,i,j;
  for(i=1;i<MAX;i++)
  {
    phi[i]=i;
    if(!(i&1)) phi[i]>>=1;
  }
  for(i=3;i<MAX;i+=2)
  {
    if(!(sieve[i>>4]&(1<<((i>>1)&7))))
    {
      phi[i]--;
      r=i<<1;
      for(j=r;j<MAX;j+=i)
      {
        if(j&1) {
          sieve[j>>4]|=(1<<((j>>1)&7));
        }
        phi[j]/=i;
        phi[j]*=(i-1);
      }
    }
  }
  return ;
}

///burnside_lemma = 1/n(S(phi(n/d)*k^d));
template<class T> inline T Burnside_Lemma_div(T n,T k)
{
  T i;
  T sq=sqrt(n)+1,res=(T) 0;
  for(i=1;i<sq;i++)
  {
    if(n%i==0)
    {
      res+=(phi[n/i]*BigMod(k,i,M))%M;
      if(n/i!=i) res+=(phi[i]*BigMod(k,n/i,M))%M;
      res%=M;
      if(res<0) res+=M;
    }
  }
  return res;
}

int main()
{
  sieve_phi();
  ll n,k,res,inv;
  SF("%lld %lld",&n,&k);
  res=Burnside_Lemma_div(n,k);
  inv=BigMod(n,M-2,M);
  res=(res*inv)%M;
  if(res<0) res+=M;
  PF("%lld\n",res);
  return 0;
}
