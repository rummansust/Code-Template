#if DEBUG
#pragma GCC optimize("Ofast,fast-math,unroll-loops,O3,O2")
#endif
#if DEBUG
#include <filesystem>
#endif

#include <assert.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <array>
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
#include <fstream>
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
#if DEBUG
using namespace std::filesystem;
#endif

#define SZ(x) ((int)x.size())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define clrall(name, val) memset(name, (val), sizeof(name))
#define eraseDuplicate(v) v.resize(distance(v.begin(), unique(all(v))))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define Double long double
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
#define __ std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl "\n"
#define casePrint(cas) cout << "Case " << cas << ": "
#define casePrintNL(cas) cout << "Case " << cas << ":\n"
#define ignore_blank_line cin.ignore(numeric_limits<streamsize>::max(), '\n')

ll MulModL(ll B, ll P, ll M)
{
  ll R = 0;
  while (P > 0)
  {
    if ((P & 1ll) == 1)
    {
      R = (R + B);
      if (R >= M)
        R -= M;
    }
    P >>= 1ll;
    B = (B + B);
    if (B >= M)
      B -= M;
  }
  return R;
}

ll MulModD(ll B, ll P, ll M)
{
  ll I = ((long double)B * (long double)P / (long double)M);
  ll R = B * P - M * I;
  R = (R % M + M) % M;
  return R;
}

ll BigMod(ll B, ll P, ll M)
{
  ll R = 1;
  while (P > 0)
  {
    if (P % 2 == 1)
    {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
} /// (B^P)%M

ll BigModML(ll B, ll P, ll M)
{
  ll R = 1;
  while (P > 0)
  {
    if (P % 2 == 1)
    {
      R = MulModL(R, B, M);
    }
    P /= 2;
    B = MulModL(B, B, M);
  }
  return R;
} /// (B^P)%M

const ll multiplyMod_128(__int128_t a, __int128_t b, ll M)
{
  return (a * b) % M;
}
const ll addMod_128(__int128_t a, __int128_t b, ll M) { return (a + b) % M; }
ll bigMod_128(ll B, ll P, ll M)
{
  ll R = 1;
  while (P > 0)
  {
    if (P % 2 == 1)
    {
      R = multiplyMod_128(R, B, M);
    }
    P /= 2;
    B = multiplyMod_128(B, B, M);
  }
  return R;
}

template <class T>
string decimalToString(T n)
{
  if (n == 0)
    return "0";
  string sign = n < 0 ? "-" : "";
  string str = "";
  int k;
  while (n)
  {
    k = abs(int(n % 10));
    str.push_back('0' + k);
    n /= 10;
  }
  reverse(all(str));
  return sign + str;
}

template <class T>
T _gcd(T a, T b)
{
  T c;
  while (b != 0)
  {
    c = a;
    a = b;
    b = c % b;
  }
  return a;
}
template <class T>
inline T _lcm(T a, T b)
{
  T g = _gcd(a, b);
  return ((a / g) * b);
}

template <typename T>
void deb(const T &val)
{
  cerr << val << "\n";
}

template <typename T, typename... Args>
void deb(const T &first, const Args &...rest)
{
  cerr << first << " ";
  deb(rest...);
}

// int dx[]= {-1,-1,0,0,1,1};
// int dy[]= {-1,0,-1,1,0,1};
// int dx[]= {0,0,1,-1};/*4 side move*/
// int dy[]= {-1,1,0,0};/*4 side move*/
// int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
// int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
// int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
// int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
ll power(ll B, ll P)
{
  ll R = 1;
  while (P > 0)
  {
    if (P & 1ll)
    {
      R = R * B;
    }
    P >>= 1ll;
    B = B * B;
  }
  return R;
}

typedef pair<int, int> pii;

template <typename T, typename Compare = std::less<T>>
class MonotonicQueue
{
private:
  struct Item
  {
    int index;
    T val;
  };
  std::deque<Item> dq;
  Compare comp;

public:
  MonotonicQueue(Compare c = Compare()) : comp(c) {}

  void push(int idx, T val)
  {
    // Pop elements from the back that violate the monotonic property
    while (!dq.empty() && (comp(val, dq.back().val) || val == dq.back().val))
    {
      dq.pop_back();
    }
    dq.push_back({idx, val});
  }

  void pop_expired(int current_idx, int window_size)
  {
    int threshold = current_idx - window_size;
    while (!dq.empty() && dq.front().index <= threshold)
    {
      dq.pop_front();
    }
  }

  T front_val() const
  {
    return dq.front().val;
  }

  int front_index() const
  {
    return dq.front().index;
  }

  bool empty() const
  {
    return dq.empty();
  }
};
// Test function for minimum sliding window
void test_min_queue(const vector<int> &arr, int window_size)
{
  deb("--- Testing Min Queue (Window Size:", window_size, ") ---");
  MonotonicQueue<int> min_q;

  for (int i = 0; i < (int)arr.size(); ++i)
  {
    min_q.push(i, arr[i]);
    min_q.pop_expired(i, window_size);

    if (i >= window_size - 1)
    {
      deb("Window ending at index", i, "Min:", min_q.front_val());
    }
  }
}

// Test function for maximum sliding window
void test_max_queue(const vector<int> &arr, int window_size)
{
  deb("--- Testing Max Queue (Window Size:", window_size, ") ---");
  MonotonicQueue<int, std::greater<int>> max_q;

  for (int i = 0; i < (int)arr.size(); ++i)
  {
    max_q.push(i, arr[i]);
    max_q.pop_expired(i, window_size);

    if (i >= window_size - 1)
    {
      deb("Window ending at index", i, "Max:", max_q.front_val());
    }
  }
}

void work()
{
  vector<int> sample_arr = {3, 1, 4, 3, 5, 9, 2, 6};
  int w = 3;

  test_min_queue(sample_arr, w);
  test_max_queue(sample_arr, w);
  return;
}

int main(int argc, char *argv[])
{
#if DEBUG
  path executablePath = argv[0];
  path currentDir = executablePath.parent_path();
  path inputFile = currentDir / "in.txt";
  path outputFile = currentDir / "out.txt";
  // freopen(inputFile.c_str(), "r", stdin);
  // freopen(outputFile.c_str(), "w", stdout);
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