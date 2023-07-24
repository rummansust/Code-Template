//
//  main.cpp
//  KMP
//
//  Created by Rumman Mahmud on 8/1/20.
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

struct PuzzleString {
  int len;
  string s;
  vector<pii> pos;
  PuzzleString(){}
  PuzzleString(const string &str, const vector<pii> positions) {
    s = str;
    pos = positions;
    len = (int)str.size();
  }
};

struct QueryString {
  int len;
  string s;
  vector<int> fail;
  QueryString(){}
  QueryString(const string &str) {
    s = str;
    len = (int)str.size();
    fail.resize(len);
    failFunction();
  }
  
  void failFunction() {
    fail[0]=0;
    int k=0;
    for(int i=1;i<len;i++)
    {
      while(k && s[i]!=s[k]) k=fail[k-1];
      if(s[k]==s[i]) k++;
      fail[i]=k;
    }
  }
  
  int find(const string &txt) {
    int tLen = (int)txt.size();
    if(len>tLen) return tLen;
    int k=0,j=0;
    while(j<tLen) {
      while(k && s[k]!=txt[j]) k=fail[k-1];
      if(s[k]==txt[j]) {
        k++;
      }
      if(k==len) return j-len+1;
      j++;
    }
    return tLen;
  }
};

vector<PuzzleString> puzzleStrs;

void constructPuzzleStrings(const int &n, const vector<string> &mat) {
  int N = 11*n-4,k=0;
  vector<pii> pos(n);
  puzzleStrs.resize(N);
  string str;
  //row+reverse row
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      pos[j]={i,j};
    }
    puzzleStrs[k++] = PuzzleString(mat[i], pos);
    str.resize(n);
    for(int j=n-1,p=0;j>=0;j--,p++) {
      pos[p]={i,j};
      str[p]=mat[i][j];
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  str.resize(n);
  //col
  for(int j=0;j<n;j++) {
    for(int i=0;i<n;i++) {
      pos[i]={i,j};
      str[i]=mat[i][j];
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  //diagonal left to right
  for(int i=0;i<n;i++) {
    str.resize(n-i);
    pos.resize(n-i);
    for(int x=i,y=0;x<n;x++,y++) {
      str[y]=mat[x][y];
      pos[y]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
    for(int x=n-1,y=n-i-1,p=0;y>=0;x--,y--,p++) {
      str[p]=mat[x][y];
      pos[p]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  for(int i=1;i<n;i++) {
    str.resize(n-i);
    pos.resize(n-i);
    for(int x=0,y=i;y<n;x++,y++) {
      str[x]=mat[x][y];
      pos[x]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
    for(int x=n-i-1,y=n-1,p=0;x>=0;x--,y--,p++) {
      str[p]=mat[x][y];
      pos[p]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  //diagonal right to left
  for(int i=0;i<n;i++) {
    str.resize(n-i);
    pos.resize(n-i);
    for(int x=i,y=n-1,p=0;x<n;x++,y--,p++) {
      str[p]=mat[x][y];
      pos[p]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
    for(int x=n-1,y=i,p=0;y<n;x--,y++,p++) {
      str[p]=mat[x][y];
      pos[p]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  for(int i=n-2;i>=0;i--) {
    str.resize(i+1);
    pos.resize(i+1);
    for(int x=0,y=i;y>=0;x++,y--) {
      str[x]=mat[x][y];
      pos[x]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
    for(int x=i,y=0,p=0;x>=0;x--,y++,p++) {
      str[p]=mat[x][y];
      pos[p]={x,y};
    }
    puzzleStrs[k++] = PuzzleString(str, pos);
  }
  return;
}

pii search(QueryString &s) {
  int p,idx=0;
  for(auto i: puzzleStrs) {
    p=s.find(i.s);
    if(p<i.len) {
      return {idx,p};
    }
    idx++;
  }
  return {-1,-1};
}

void work() {
  int n;
  vector<string> mat;
  pii res;
  string s;
  QueryString q;
  while(cin>>n) {
    mat.resize(n);
    for(int i=0;i<n;i++) {
      cin>>mat[i];
    }
    constructPuzzleStrings(n, mat);
    while(cin>>s) {
      if(s=="0") break;
      q = QueryString(s);
      res=search(q);
      if(res.first!=-1) {
        pii lp = puzzleStrs[res.first].pos[res.second];
        pii rp = puzzleStrs[res.first].pos[res.second+q.len-1];
        cout<<lp.first+1<<","<<lp.second+1<<" "<<rp.first+1<<","<<rp.second+1<<"\n";
      } else {
        deb("Not found");
      }
    }
  }
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
/**
3 3
SEX
IDP
LSE
IS
LD
PD
DE
0
 */
