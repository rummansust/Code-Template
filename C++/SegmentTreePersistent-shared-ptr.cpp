#if DEBUG
#pragma GCC optimize("Ofast,fast-math,unroll-loops,O3")
#endif

#include <bits/stdc++.h>

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
#define oo (1 << 28)
#define inf 0x3f3f3f3f
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
template <typename T,
          typename std::enable_if_t<is_arithmetic_v<T>, bool> = true>
struct vertex {
  shared_ptr<vertex<T>> leftChild, rightChild;
  T sum;
  vertex() : leftChild{nullptr}, rightChild(nullptr), sum(0) {}
  vertex(int val) : leftChild{nullptr}, rightChild(nullptr), sum(val) {}
  vertex(shared_ptr<vertex<T>> leftChild, shared_ptr<vertex<T>> rightChild)
      : leftChild{leftChild}, rightChild(rightChild), sum(0) {
    if (leftChild) sum += leftChild->sum;
    if (rightChild) sum += rightChild->sum;
  }
};

struct persistent_seg_tree {
 private:
  int N;
  template <typename T>
  shared_ptr<vertex<T>> buildUtils(vector<T> &vals, int l, int r) {
    if (l == r) {
      return make_shared<vertex<T>>(vals[l]);
    }
    int mid = (l + r) >> 1;
    return make_shared<vertex<T>>(buildUtils(vals, l, mid),
                                  buildUtils(vals, mid + 1, r));
  }

  template <typename T>
  shared_ptr<vertex<T>> pointUpdateUtils(shared_ptr<vertex<T>> node, int l,
                                         int r, int pos, T newVal) {
    if (l == r) return make_shared<vertex<T>>(newVal);
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      return make_shared<vertex<T>>(
          pointUpdateUtils(node->leftChild, l, mid, pos, newVal),
          node->rightChild);
    } else {
      return make_shared<vertex<T>>(
          node->leftChild,
          pointUpdateUtils(node->rightChild, mid + 1, r, pos, newVal));
    }
  }

  template <typename T,
            typename std::enable_if_t<is_arithmetic_v<T>, bool> = true>
  T rangeSumQueryUtils(shared_ptr<vertex<T>> node, int l, int r, int ql,
                       int qr) {
    if (ql > qr || l > r || l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return node->sum;
    int mid = (l + r) >> 1;
    return rangeSumQueryUtils(node->leftChild, l, mid, ql, qr) +
           rangeSumQueryUtils(node->rightChild, mid + 1, r, ql, qr);
  }

 public:
  persistent_seg_tree() {}
  template <typename T>
  shared_ptr<vertex<T>> build(vector<T> &vals) {
    N = vals.size();
    return buildUtils(vals, 0, N - 1);
  }
  template <typename T>
  shared_ptr<vertex<T>> pointUpdate(shared_ptr<vertex<T>> node, int pos,
                                    T newVal) {
    return pointUpdateUtils(node, 0, N - 1, pos, newVal);
  }

  template <typename T,
            typename std::enable_if_t<is_arithmetic_v<T>, bool> = true>
  T rangeSumQuery(shared_ptr<vertex<T>> node, int ql, int qr) {
    return rangeSumQueryUtils(node, 0, N - 1, ql, qr);
  }
};

void work() {
  vector<shared_ptr<vertex<int>>> roots;
  vector<int> vals = {2, 4, 3, 1};
  persistent_seg_tree pst;
  roots.push_back(pst.build(vals));
  deb(pst.rangeSumQuery<int>(roots[0], 0, 3));
  deb(pst.rangeSumQuery<int>(roots[0], 1, 2));
  roots.push_back(pst.pointUpdate<int>(roots[0], 2, 5));
  deb(pst.rangeSumQuery<int>(roots[1], 0, 3));
  deb(pst.rangeSumQuery<int>(roots[1], 1, 2));
  roots.push_back(pst.pointUpdate<int>(roots[0], 1, 5));
  deb(pst.rangeSumQuery<int>(roots[2], 0, 3));
  deb(pst.rangeSumQuery<int>(roots[2], 1, 2));
  return;
}

int main() {
#if DEBUG
  Read;
  Write;
#endif
  __;
#if DEBUG
  auto start = high_resolution_clock::now();
#endif
  work();
#if DEBUG
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << "Time taken by function: " << duration.count() / 1000000.0
       << " seconds\n";
#endif
  return 0;
}