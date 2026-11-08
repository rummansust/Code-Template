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

const int ALPHABET_SIZE = 26;
const int MAX_NODES = 1e6 + 5;
const int MAX_WORD_LENGTH = 105;

struct state
{
  int child[ALPHABET_SIZE], link, depth;
  vector<int> matched;
  void initialize(int dep)
  {
    memset(child, 0, sizeof(child));
    matched.clear();
    link = 0;
    depth = dep;
  }
};

state T[MAX_NODES];                     // normally total character
char words[MAX_NODES][MAX_WORD_LENGTH]; // 1 based
int sz, _last;                          // sz = node no(1 based)(0 is root), _last is used while iteration
char str[MAX_NODES];
int toporder[MAX_NODES];             // for topological sort
int freq[MAX_NODES], ans[MAX_NODES]; // ans = occurance of the word in the string, freq = substring frequency

void initialize() // normally only 1st node (initialize all for safety)
{
  T[0].initialize(0);
  sz = 1;
}

void buildahocorasick(int n) // how many node
{
  initialize();
  int i, j, len, u, v, p;
  char ch;
  queue<int> q;

  for (i = 1; i <= n; i++)
  {
    _last = 0;
    len = strlen(words[i]);
    for (j = 0; j < len; j++)
    {
      ch = words[i][j] - 'a'; // sometimes change here
      if (T[_last].child[ch] == 0)
      {
        T[sz].initialize(j + 1);
        T[_last].child[ch] = sz++;
      }
      _last = T[_last].child[ch];
    }
    T[_last].matched.push_back(i);
  }

  for (i = 0; i < ALPHABET_SIZE; i++)
  {
    if (T[0].child[i])
    {
      q.push(T[0].child[i]);
      T[T[0].child[i]].link = 0;
    }
  }

  while (!q.empty())
  {
    u = q.front();
    q.pop();

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
      if (T[u].child[i])
      {
        p = T[u].link;
        v = T[u].child[i];
        while (p != 0 && T[p].child[i] == 0)
          p = T[p].link;
        T[v].link = T[p].child[i];
        q.push(v);
      }
      else
        T[u].child[i] = T[T[u].link].child[i];
    }
  }

  vector<int> depthcount(sz, 0);
  for (i = 0; i < sz; i++)
    depthcount[T[i].depth]++;
  for (i = 1; i < sz; i++)
    depthcount[i] += depthcount[i - 1];
  for (i = 0; i < sz; i++)
    toporder[--depthcount[T[i].depth]] = i;
}

void search(int numwords)
{
  int i, j, len, cur, p, v;
  char ch;

  cur = 0;
  len = strlen(str);
  memset(freq, 0, sizeof(int) * sz);

  for (i = 0; i < len; i++)
  {
    ch = str[i] - 'a';
    cur = T[cur].child[ch];
    freq[cur]++;
  }

  for (i = sz - 1; i >= 0; i--)
  {
    v = toporder[i];
    if (T[v].link > 0)
      freq[T[v].link] += freq[v];
  }

  for (i = 1; i <= numwords; i++)
    ans[i] = 0;

  for (i = 1; i < sz; i++)
  {
    if (!T[i].matched.empty())
    {
      for (j = 0; j < (int)T[i].matched.size(); j++)
        ans[T[i].matched[j]] = freq[i];
    }
  }
}

void work()
{
  int n = 4;
  // 1-based indexing for words
  strcpy(words[1], "he");
  strcpy(words[2], "she");
  strcpy(words[3], "his");
  strcpy(words[4], "hers");

  strcpy(str, "ushers");

  buildahocorasick(n);
  search(n);

  cout << "Testing Pattern Occurrences in text \"ushers\":" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << "Word " << i << " (\"" << words[i] << "\"): " << ans[i] << " times" << endl;
  }
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