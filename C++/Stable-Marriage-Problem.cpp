// https://lightoj.com/problem/employment

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
#define casePrint(cas) cout << "Case " << cas << ":"
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

vector<int> SMP(vector<vector<int>> &prefs, int n) {
  vector<vector<int>> prefsPos(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      prefsPos[i][prefs[i + n][j]] = j;
    }
  }

  auto comparePrefs = [&](int v, int u1, int u2) -> bool {
    return prefsPos[v - n][u1] < prefsPos[v - n][u2];
  };

  queue<int> q;
  vector<int> match(n + 1, -1);
  for (int i = 1; i <= n; i++) q.push(i);
  int u, v, eu;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto it = prefs[u].begin() + 1; it != prefs[u].end(); it++) {
      v = *it;
      if (match[v - n] == -1) {
        match[v - n] = u;
        break;
      } else {
        eu = match[v - n];
        if (comparePrefs(v, u, eu)) {
          match[v - n] = u;
          q.push(eu);
          break;
        }
      }
    }
  }
  return match;
}

void test() {
  /*
  1
  3
  4 5 6
  6 5 4
  5 4 6
  2 1 3
  1 2 3
  3 2 1
 */
  int n = 3;
  vector<vector<int>> prefs(2 * n + 1);
  prefs[1] = {0, 4, 5, 6};
  prefs[2] = {0, 6, 5, 4};
  prefs[3] = {0, 5, 4, 6};
  prefs[4] = {0, 2, 1, 3};
  prefs[5] = {0, 1, 2, 3};
  prefs[6] = {0, 3, 2, 1};
  vector<int> match = SMP(prefs, n);
  for (int i = 1; i <= n; i++) {
    deb(match[i], i + n);
  }
  return;
}

void work() {
  // test();
  int n;
  vector<vector<int>> prefs;
  vector<int> match;
  int t, cas = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    casePrint(++cas);
    prefs.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
      prefs[i].resize(n + 1);
      for (int j = 1; j <= n; j++) {
        cin >> prefs[i][j];
      }
    }
    match = SMP(prefs, n);
    for (int i = 1; i <= n; i++) {
      cout << " (" << match[i] << " " << i + n << ")";
    }
    cout << endl;
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