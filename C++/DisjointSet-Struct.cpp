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
ll power(ll B,ll P) {
  ll R=1;
  while(P>1) {
    if(P&1ll) {
      R=R*B;
    }
    P>>=1ll;
    B=B*B;
  }
  return R;
}

typedef pair<int,int> pii;

struct edge
{
  int parent,rank,member;
};

struct DisjointSet {
  DisjointSet(){
    len=0;
    cnt=0;
  }
  DisjointSet(int n){
    len=n;
    cnt=n;
    dset.resize(len);
    initializeDset();
  }
  
  inline void clear() {
    len=0;
    cnt=0;
    dset.clear();
  }
  
  inline void resize(const int n) {
    len=n;
    cnt=n;
    dset.resize(len);
    initializeDset();
  }
  
  int findset(const int u)
  {
    if(dset[u].parent==u) return u;
    return dset[u].parent=findset(dset[u].parent);
  }
  
  inline void unionset(const int u,const int v)
  {
    int up=findset(u);
    int vp=findset(v);
    if(dset[up].parent==dset[vp].parent) return;
    cnt--;
    if(dset[up].rank<dset[vp].rank)
    {
      dset[up].parent=dset[vp].parent;
      dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
    }
    else
    {
      dset[vp].parent=dset[up].parent;
      dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
      if(dset[up].rank==dset[vp].rank)
        dset[up].rank=dset[up].rank+1;
    }
    return;
  }
  
  inline edge operator[](const int &n)const{
    return dset[n];
  }
  
  inline int count() {
    return cnt;
  }
  
  inline size_t size() {
    return len;
  }
  
  private:
    int len;
    int cnt;
    vector<edge> dset;
    void initializeDset() {
      for(int i=0;i<len;i++) {
        dset[i].parent=i;
        dset[i].rank=0;
        dset[i].member=1;
      }
    }
};

int numberOfAcornsIn(DisjointSet &D) {
  int n=D.size(),res=0;
  for(int i=0;i<n;i++) {
    res+=D[i].member==1;
  }
  return res;
}

inline pair<char, char> edgeFrom(const string &str) {
  return mp(str[1],str[3]);
}

inline vector<char> nodesFrom(const string &str) {
  int n=(str.size() >> 1) + 1;
  vector<char> nodes(n);
  for(int i=0,k=0;i<str.size();i+=2) {
    nodes[k++]=str[i];
  }
  return nodes;
}

void work() {
  string text;
  int t;
  cin>>t;
  vector<pair<char,char> > edges;
  vector<char> nodes;
  int map[27];
  DisjointSet dset;
  while(t--) {
    nodes.clear();
    edges.clear();
    while(cin>>text) {
      if(text[0]=='*') break;
      edges.push_back(edgeFrom(text));
    }
    cin>>text;
    nodes=nodesFrom(text);
    int k=0;
    for(auto i: nodes) {
      map[i-'A']=k++;
    }
    dset.resize(nodes.size());
    for(auto i: edges) {
      dset.unionset(map[i.first-'A'],map[i.second-'A']);
    }
    int acorns = numberOfAcornsIn(dset);
    cout<<"There are "<<dset.count()-acorns<<" tree(s) and "<<acorns<<" acorn(s).\n";
  }
  return;
}

int main() {
#if DEBUG
   Read;
   Write;
#endif
  __;
  auto start = high_resolution_clock::now();
  work();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken by function: "<< duration.count()/1000000.0 << " seconds\n";
  return 0;
}
