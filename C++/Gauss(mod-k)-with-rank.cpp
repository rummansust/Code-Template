// https://lightoj.com/problem/graph-coloring

// #pragma GCC optimize("Ofast,fast-math,unroll-loops,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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
#define endl "\n"
#define casePrint(cas) cout << "Case " << cas << ": "
#define casePrintNL(cas) cout << "Case " << cas << ":\n"

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

const ll multiplyMod_128(__int128_t a, __int128_t b, ll M) {
  return (a * b) % M;
}
const ll addMod_128(__int128_t a, __int128_t b, ll M) { return (a + b) % M; }
ll bigMod_128(ll B, ll P, ll M) {
  ll R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = multiplyMod_128(R, B, M);
    }
    P /= 2;
    B = multiplyMod_128(B, B, M);
  }
  return R;
}

template <class T>
string decimalToString(T n) {
  if (n == 0) return "0";
  string sign = n < 0 ? "-" : "";
  string str = "";
  int k;
  while (n) {
    k = abs(int(n % 10));
    str.push_back('0' + k);
    n /= 10;
  }
  reverse(all(str));
  return sign + str;
}

template <class T>
T _gcd(T a, T b) {
  T c;
  while (b != 0) {
    c = a;
    a = b;
    b = c % b;
  }
  return a;
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
enum SolutionType { uniqueSolutions, infiniteSolutions, noSolutions };
// Gauss Jordan Elimination Modulo K
struct GJEModK {
  GJEModK() {}

 private:
  vector<vector<int>> a;

  void elimination(int k, int n, int m, vector<int> &where) {
    for (int col = 0, row = 0, pivot; col < m && row < n; ++col) {
      pivot = row;
      for (int i = row; i < n; ++i) {
        if (a[i][col] > a[pivot][col]) {
          pivot = i;
        }
      }
      if (!a[pivot][col]) continue;
      if (pivot != row) {
        for (int i = col; i <= m; i++) {
          swap(a[pivot][i], a[row][i]);
        }
      }
      where[col] = row;

      ll c;
      for (int i = 0; i < n; ++i) {
        if (i != row && a[i][col]) {
          c = (1LL * a[i][col] * BigMod(a[row][col], k - 2, k)) % k;
          for (int j = col; j <= m; j++) {
            a[i][j] -= (a[row][j] * c) % k;
            if (a[i][j] < 0) a[i][j] += k;
          }
        }
      }
      ++row;
    }
  }

  // a1x1 + a2x2 + a3x3 + ... ... ... + akxk = b1
  // last column will have the bi
  SolutionType _gaussUtils(int k, vector<int> &ans, vector<int> &where) {
    int n = a.size();
    int m = where.size();
    elimination(k, n, m, where);
    ans.clear();
    ans.resize(m);
    ans.assign(m, 0);
    for (int i = 0; i < m; ++i) {
      if (where[i] != -1 && a[where[i]][m]) {
        ans[i] = (1LL * a[where[i]][m] * BigMod(a[where[i]][i], k - 2, k)) % k;
      }
    }
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < m; ++j) {
        sum += (1LL * ans[j] * 1LL * a[i][j]) % k;
        if (sum >= k) sum -= k;
      }
      if (sum != a[i][m]) return noSolutions;
    }

    for (int i = 0; i < m; ++i)
      if (where[i] == -1) return infiniteSolutions;
    return uniqueSolutions;
  }

 public:
  void setMatrix(vector<vector<int>> &m) {
    a.clear();
    a = m;
  }
  void addRow(vector<int> &row) { a.push_back(row); }
  void removeLastRow() {
    if (a.size()) a.pop_back();
  }

  void reset() { a.clear(); }

  SolutionType gauss(int k, int m, vector<int> &ans) {
    vector<int> where(m, -1);
    return _gaussUtils(k, ans, where);
  }

  int rank(int k, int m) {
    vector<int> ans;
    vector<int> where(m, -1);
    SolutionType st = _gaussUtils(k, ans, where);
    if (st == noSolutions) {
      return -1;
    }
    int r = m;
    for (auto &w : where) r -= w == -1;
    return r;
  }

  void debugPrint() {
    deb(":::::::::::::::::::");
    for (auto &row : a) {
      for (auto &v : row) {
        cout << setw(2) << setfill(' ') << " " << v;
      }
      cout << endl;
    }
    deb(":::::::::::::::::::");
  }
};

const int MOD = 1000000007;
void work() {
  GJEModK e;
  int n, m, k, u, v;
  vector<vector<int>> adj;
  vector<int> row;
  int t, cas = 0;
  ll res;
  cin >> t;
  while (t--) {
    casePrint(++cas);
    cin >> n >> m >> k;
    if (m) {
      e.reset();
      adj.clear();
      adj.resize(n);
      while (m--) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      row.resize(n + 1);
      for (u = 0; u < n; u++) {
        row.assign(n + 1, 0);
        if (adj[u].empty())
          row[u] = 1;
        else
          row[u] = k - 1;
        for (auto &v : adj[u]) {
          row[v] = 1;
        }
        e.addRow(row);
      }
      int rank = e.rank(k, n);
      res = BigMod(k, n - rank, MOD);
    } else {
      res = 1;
    }
    cout << res << endl;
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
  cerr << "Time taken by function: " << duration.count() / 1000000.0
       << " seconds\n";
  return 0;
}