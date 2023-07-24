//
//  main.cpp
//  UVA-11695 Flight Planning
//
//  Created by Rumman Mahmud on 7/31/20.
//  Copyright © 2020 Rumman Mahmud. All rights reserved.
//

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

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

ll BigModML(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M

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
typedef vector<vector<int> > Tree;
typedef pair<vector<int>, int> FarthestTreePath;
typedef pair<int, int> Edge;

inline void addEdge(int u,int v, Tree &t) {
  t[u].push_back(v);
  t[v].push_back(u);
  return;
}

FarthestTreePath farthestTreePathFrom(int root, int excludedNode, Tree &t, int &n) {
  vector<int> dist(n,-1),parLink(n,-1);
  queue<int> Q;
  int u = root;
  Q.push(u);
  dist[u]=0;
  int farthestNode = u, farthestDist = 0;
  while(!Q.empty()) {
    u = Q.front(); Q.pop();
    for(auto v: t[u]) {
      if(v!=excludedNode && dist[v]==-1) {
        dist[v] = dist[u]+1;
        parLink[v] = u;
        Q.push(v);
        if(dist[v]>farthestDist) {
          farthestDist = dist[v];
          farthestNode = v;
        }
      }
    }
  }
  vector<int> path;
  int v = farthestNode;
  while (v!=-1) {
    path.push_back(v);
    v = parLink[v];
  }
  return {path, farthestNode};
}

vector<int> treeDiameter(int root, int excludedNode, Tree &t, int &n) {
  FarthestTreePath f = farthestTreePathFrom(root, excludedNode, t, n);
  f = farthestTreePathFrom(f.second, excludedNode, t, n);
  return f.first;
}

void constructTree(vector<Edge> &e, int &n, Tree &t) {
  t.resize(n);
  for(auto i: e) {
    addEdge(i.first, i.second, t);
  }
  return;
}

pair<int, Edge> work(Edge e, Tree &t, int &n) {
  vector<int> td = treeDiameter(e.first, e.second, t, n);
  int diameter1 = (int)td.size();
  int midDist1 = diameter1>>1;
  int center1 = td[diameter1 >> 1];
  
  td = treeDiameter(e.second, e.first, t, n);
  int diameter2 = (int)td.size();
  int midDist2 = diameter2>>1;
  int center2 = td[diameter2 >> 1];
  int maxDist = max(max(diameter1,diameter2)-1,midDist1+midDist2+1);
  return {maxDist, {center1,center2}};
}

void solve(vector<Edge> &e, int &n) {
  Tree t;
  constructTree(e, n, t);
  int res=oo;
  pair<int, Edge> ret;
  Edge link = {-1,-1}, unlink = {-1,-1};
  for(auto i: e) {
    ret = work(i, t, n);
    if(ret.first<res) {
      res=ret.first;
      unlink=i;
      link=ret.second;
    }
  }
  cout<<res<<"\n";
  cout<<unlink.first+1<<" "<<unlink.second+1<<"\n";
  cout<<link.first+1<<" "<<link.second+1<<"\n";
}

void test() {
  int n = 4;
  vector<Edge> e;
  e.psb(mp(0, 1));
  e.psb(mp(1, 2));
  e.psb(mp(2, 3));
//  e.psb(mp(2, 4));
//  e.psb(mp(4, 5));
//  e.psb(mp(1, 6));
  solve(e, n);
}

int main(int argc, const char * argv[]) {
//  test();
  __;
  int t,n;
  vector<Edge> e;
  cin>>t;
  while (t--) {
    cin>>n;
    e.resize(n-1);
    for(int i=0;i<n-1;i++) {
      cin>>e[i].first>>e[i].second;
      e[i].first--;
      e[i].second--;
    }
    solve(e, n);
  }
  return 0;
}
/**
 1
 14
 1 2
 1 8
 2 3
 2 4
 8 9
 8 10
 8 11
 4 5
 4 6
 4 7
 10 12
 10 13
 13 14
 */
