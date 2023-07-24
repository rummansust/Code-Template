//
//  main.cpp
//  UVA-1588 - Kickdown
//
//  Created by Rumman Mahmud on 7/27/20.
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
#include <unordered_set>

using namespace std;

#define deb1(a0) cerr<<#a0<<" = "<<a0<<endl
#define deb2(a0,a1) cerr<<#a0<<" = "<<a0<<", "<<#a1<<" = "<<a1<<endl
#define deb3(a0,a1,a2) cerr<<#a0<<" = "<<a0<<", "<<#a1<<" = "<<a1<<", "<<#a2<<" = "<<a2<<endl

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
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
#define Write freopen("out2.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)
struct VectorHash {
  template <class T>
    size_t operator()(const vector<T>& v) const {
        hash<T> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
struct PairHash {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const
  {
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
  }
};

using MySet = std::unordered_set<std::vector<int>, VectorHash>;

int main(int argc, const char * argv[]) {
  return 0;
}
