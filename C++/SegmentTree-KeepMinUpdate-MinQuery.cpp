#include <assert.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using namespace std::chrono;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define clrall(name, val) memset(name, (val), sizeof(name))
#define eraseDuplicate(v) v.resize(distance(v.begin(), unique(all(v))))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1 << 28)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a, b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt", "r", stdin)
#define Write freopen("out.txt", "w", stdout)
#define __ std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

ll MulModL(ll B, ll P, ll M) {
  ll R = 0;
  while (P > 0) {
    if ((P & 1ll) == 1) {
      R = (R + B);
      if (R >= M) R -= M;
    }
    P >>= 1ll;
    B = (B + B);
    if (B >= M) B -= M;
  }
  return R;
}

ll MulModD(ll B, ll P, ll M) {
  ll I = ((long double)B * (long double)P / (long double)M);
  ll R = B * P - M * I;
  R = (R % M + M) % M;
  return R;
}

ll BigMod(ll B, ll P, ll M) {
  ll R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}  /// (B^P)%M

ll BigModML(ll B, ll P, ll M) {
  ll R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = MulModL(R, B, M);
    }
    P /= 2;
    B = MulModL(B, B, M);
  }
  return R;
}  /// (B^P)%M
template <class T>
T _gcd(T a, T b) {
  T c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
template <class T>
inline T _lcm(T a, T b) {
  T g = _gcd(a, b);
  return ((a / g) * b);
}
template <class T1>
void deb(T1 e1) {
  cerr << e1 << "\n";
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cerr << e1 << " " << e2 << "\n";
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cerr << e1 << " " << e2 << " " << e3 << "\n";
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << "\n";
}
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6, T7 e7) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << " " << e7 << "\n";
}

// int dx[]= {-1,-1,0,0,1,1};
// int dy[]= {-1,0,-1,1,0,1};
// int dx[]= {0,0,1,-1};/*4 side move*/
// int dy[]= {-1,1,0,0};/*4 side move*/
// int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
// int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
// int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
// int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
ll power(ll B, ll P) {
  ll R = 1;
  while (P > 1) {
    if (P & 1ll) {
      R = R * B;
    }
    P >>= 1ll;
    B = B * B;
  }
  return R;
}

typedef pair<int, int> pii;
const int lim = (1 << 14) | 1;
vector<int> tree;
vector<int> lazyVal;
vector<bool> hasLazyVal;

void init() {
  tree = vector<int>(lim, oo);
  lazyVal = vector<int>(lim, oo);
  hasLazyVal = vector<bool>(lim, false);
  return;
}

void relax(int idx, int l, int r, int val) {
  int nidx = idx << 1;
  tree[idx] = min(tree[idx], val);
  if (l != r) {
    lazyVal[nidx] = min(lazyVal[nidx], val);
    hasLazyVal[nidx] = true;
    lazyVal[nidx | 1] = min(lazyVal[nidx | 1], val);
    hasLazyVal[nidx | 1] = true;
  }
  hasLazyVal[idx] = false;
  lazyVal[idx] = oo;
}

int update(int idx, int l, int r, int ql, int qr, int val) {
  if (l > r || ql > qr) return oo;
  if (hasLazyVal[idx]) {
    relax(idx, l, r, lazyVal[idx]);
  }
  if (l > qr || r < ql) return tree[idx];
  if (l >= ql && r <= qr) {
    relax(idx, l, r, val);
    return tree[idx];
  }
  int mid = (l + r) >> 1, nidx = (idx << 1);
  tree[idx] = min(update(nidx, l, mid, ql, qr, val),
                  update(nidx | 1, mid + 1, r, ql, qr, val));
  return tree[idx];
}

int query(int idx, int l, int r, int ql, int qr) {
  if (l > r || ql > qr) return oo;
  if (hasLazyVal[idx]) {
    relax(idx, l, r, lazyVal[idx]);
  }
  if (l > qr || r < ql) return oo;
  if (l >= ql && r <= qr) {
    return tree[idx];
  }
  int mid = (l + r) >> 1, nidx = (idx << 1);
  return min(query(nidx, l, mid, ql, qr), query(nidx | 1, mid + 1, r, ql, qr));
}

void printTree(int n) {
  for (int i = 0, v; i < n; i++) {
    v = query(1, 0, n - 1, i, i);
    if (v == oo)
      cerr << "inf ";
    else
      cerr << v << " ";
  }
  cerr << endl;
  return;
}

void testTree() {
  init();
  int n, m, a, b, c;
  cin >> n;
  while (cin >> m) {
    while (m--) {
      printTree(n);
      cin >> a >> b >> c;
      deb("Range:", a, ",", b, "val:", c);
      update(1, 0, n - 1, a, b, c);
      printTree(n);
    }
  }
}

void work() {
  // testTree();
  int n, l, r, t, m;
  bool isFirstCase = true;
  vector<pii> range;
  cin >> t;
  while (t--) {
    init();
    if (!isFirstCase) cout << endl;
    isFirstCase = false;
    cin >> n;
    range.clear();
    while (cin >> l >> r && (l != 0 || r != 0)) {
      l = max(0, l);
      r = min(r, n);
      if (l > n || r < 0 || l > r) continue;
      range.push_back({l, r});
    }
    sort(all(range));
    eraseDuplicate(range);
    m = range.size();
    int idx = 0;
    for (auto &s : range) {
      if (s.first == 0) {
        update(1, 0, n, s.first, s.second, 1);
      } else {
        l = query(1, 0, n, s.first, s.second);
        update(1, 0, n, s.first, s.second, l + 1);
      }
    }
    l = query(1, 0, n, n, n);
    if (l == oo)
      cout << 0 << endl;
    else {
      cout << l << endl;
      for (int i = 0; i < l; i++) cout << "0 0\n";
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
  cerr << "Time taken by function: " << duration.count() / 1000000.0
       << " seconds\n";
  return 0;
}
