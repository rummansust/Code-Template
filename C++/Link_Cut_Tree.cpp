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
#include <stdexcept>
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

// Dynamic forest with vertex values and path sums. Operations are O(log n)
// amortized; nodes must remain alive at stable addresses while linked.
// Pass non-null nodes; e.g. Node a(1), b(2); link(&a, &b); pathSum(&a, &b).
// link/cut return false for a cycle or a nonexistent edge, respectively.
// makeRoot, link, cut and pathSum may change a component's represented root.
// pathSum requires connected vertices and throws otherwise. Sums must fit in ll.
struct LinkCutTree
{
  struct Node
  {
    Node *l = nullptr, *r = nullptr, *p = nullptr;
    ll val, sum;
    bool flip = false;

    explicit Node(ll value = 0) : val(value), sum(value) {}
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;

    bool is_root() const { return !p || (p->l != this && p->r != this); }

    void toggle()
    {
      swap(l, r);
      flip = !flip;
    }

    void push()
    {
      if (!flip)
        return;
      if (l)
        l->toggle();
      if (r)
        r->toggle();
      flip = false;
    }

    void pull()
    {
      sum = val + (l ? l->sum : 0) + (r ? r->sum : 0);
    }
  };

private:
  static void rotate(Node *x)
  {
    Node *p = x->p, *g = p->p;
    if (!p->is_root())
    {
      if (g->l == p)
        g->l = x;
      else
        g->r = x;
    }
    x->p = g;
    if (p->l == x)
    {
      p->l = x->r;
      if (x->r)
        x->r->p = p;
      x->r = p;
    }
    else
    {
      p->r = x->l;
      if (x->l)
        x->l->p = p;
      x->l = p;
    }
    p->p = x;
    p->pull();
    x->pull();
  }

  static void splay(Node *x)
  {
    vector<Node *> ancestors;
    for (Node *v = x;; v = v->p)
    {
      ancestors.push_back(v);
      if (v->is_root())
        break;
    }
    for (auto it = ancestors.rbegin(); it != ancestors.rend(); ++it)
      (*it)->push();

    while (!x->is_root())
    {
      Node *p = x->p;
      if (!p->is_root())
      {
        Node *g = p->p;
        if ((g->l == p) == (p->l == x))
          rotate(p);
        else
          rotate(x);
      }
      rotate(x);
    }
  }

  static void expose(Node *x)
  {
    Node *last = nullptr;
    for (Node *v = x; v; v = v->p)
    {
      splay(v);
      v->r = last;
      if (last)
        last->p = v;
      v->pull();
      last = v;
    }
    splay(x);
  }

public:
  static void makeRoot(Node *x)
  {
    expose(x);
    x->toggle();
  }

  static Node *findRoot(Node *x)
  {
    expose(x);
    x->push();
    while (x->l)
    {
      x = x->l;
      x->push();
    }
    splay(x);
    return x;
  }

  static bool connected(Node *x, Node *y)
  {
    return x == y || findRoot(x) == findRoot(y);
  }

  static bool link(Node *x, Node *y)
  {
    makeRoot(x);
    if (findRoot(y) == x)
      return false;
    x->p = y;
    return true;
  }

  static bool cut(Node *x, Node *y)
  {
    makeRoot(x);
    expose(y);
    if (y->l != x)
      return false;
    x->push();
    if (x->r)
      return false;
    y->l = nullptr;
    x->p = nullptr;
    y->pull();
    return true;
  }

  static ll pathSum(Node *x, Node *y)
  {
    if (!connected(x, y))
      throw invalid_argument("pathSum requires connected vertices");
    makeRoot(x);
    expose(y);
    return y->sum;
  }

  static void setValue(Node *x, ll value)
  {
    expose(x);
    x->val = value;
    x->pull();
  }
};

void test_link_cut_tree()
{
  using LCT = LinkCutTree;
  LCT::Node a(1), b(2), c(3);

  // Build the chain a - b - c.
  if (!LCT::link(&a, &b) || !LCT::link(&b, &c))
    throw logic_error("Failed to build demo tree");

  cout << "a to c sum: " << LCT::pathSum(&a, &c) << "\n"; // 6
  LCT::setValue(&b, 10);
  cout << "a to c sum after update: " << LCT::pathSum(&a, &c) << "\n"; // 14

  LCT::makeRoot(&c);
  cout << "c is root: " << (LCT::findRoot(&a) == &c) << "\n";   // 1
  cout << "link a to c (cycle): " << LCT::link(&a, &c) << "\n"; // 0

  if (!LCT::cut(&b, &c))
    throw logic_error("Failed to cut demo edge");
  cout << "a and c connected after cut: " << LCT::connected(&a, &c) << "\n"; // 0
  cout << "a to b sum: " << LCT::pathSum(&a, &b) << "\n";                    // 11
  return;
}
void work()
{
  test_link_cut_tree();
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