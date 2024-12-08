// https://codeforces.com/gym/100431 G
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

template <class T>
struct persistent_queue {
 private:
  int lastVersion = 0;
  const static int logMaxSize = 17;
  const static int MaxSize = (1 << logMaxSize) - 1;
  vector<int> binLiftingVersionHead[logMaxSize];
  vector<int> versionLen;
  vector<T> versionTailVal;
  int logLenOf(int v) {
    int i = 0;
    while (v) {
      i++;
      v >>= 1;
    }
    return i;
  }
  void init() {
    for (int i = 0; i < logMaxSize; i++) binLiftingVersionHead[i].clear();
    versionLen.resize(1, 0);
    versionTailVal.resize(1);
    lastVersion = 0;
    insertNewVersionInBinLifting(0, -1);
    return;
  }

  void insertNewVersionInBinLifting(int curVersion, int parVersion) {
    for (int i = 0; i < logMaxSize; i++) {
      binLiftingVersionHead[i].push_back(-1);
    }
    binLiftingVersionHead[0][curVersion] = parVersion;
    for (int i = 1; i < logMaxSize; i++) {
      parVersion = binLiftingVersionHead[i - 1][curVersion];
      if (parVersion == -1) break;
      binLiftingVersionHead[i][curVersion] =
          binLiftingVersionHead[i - 1][parVersion];
    }
    return;
  }

 public:
  persistent_queue() { init(); }
  void reset() { init(); }
  void push(int version, T val) {
    assert(version <= lastVersion);
    int len = versionLen[version];
    lastVersion++;
    versionLen.push_back(len + 1);
    versionTailVal.push_back(val);
    assert(lastVersion <= MaxSize);

    insertNewVersionInBinLifting(lastVersion, version);
    return;
  }

  T pop(int version) {
    assert(version <= lastVersion);
    int len = versionLen[version];
    assert(len > 0);
    int curVersion = version;
    int jumpLen = len - 1;
    for (int i = logMaxSize - 1; i >= 0; i--) {
      if ((jumpLen >> i) & 1) {
        curVersion = binLiftingVersionHead[i][curVersion];
      }
    }
    assert(curVersion != -1);
    int retVal = versionTailVal[curVersion];

    lastVersion++;
    versionLen.push_back(len - 1);
    versionTailVal.push_back(versionTailVal[version]);
    assert(lastVersion <= MaxSize);

    // When we are creating a new version after a pop we need to treat it as a copy
    // of the verion that we are popping from. It's because, even though the version
    // changed, the path should not change. Meaning, if the value in the path was
    // 1 -> 2 -> 4 before popping, then after popping the path should be 2 -> 4 instead
    // of 2 -> 4 -> 4. Hence the parent of the new version should point to the 
    // parent of the version that we are popping from.
    insertNewVersionInBinLifting(lastVersion,
                                 binLiftingVersionHead[0][version]);
    return retVal;
  }
  void debugPrintTree() {
    deb("::::::::::::::::::::::::::");
    for (int i = 0; i <= lastVersion; i++) {
      deb(binLiftingVersionHead[0][i], i, versionTailVal[i], versionLen[i]);
    }
    deb("::::::::::::::::::::::::::");
  }
};

void work() {
  persistent_queue<int> pq;
  pq.push(0, 1);
  deb(pq.pop(1));
  pq.push(2, 2);
  deb(pq.pop(3));
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