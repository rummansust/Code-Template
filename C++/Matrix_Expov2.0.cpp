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
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define clrall(name, val) memset(name, (val), sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1 << 28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var, s, n, it) for (var = (s); var < (n); (var) += it)
#define rev(var, s, n, it) for (var = (n - 1); var > (s - 1); (var) -= it)
#define Read freopen("in.txt", "r", stdin)
#define Write freopen("out.txt", "w", stdout)
#define __ std::ios_base::sync_with_stdio(false)

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

template <class T1>
void deb(T1 e1) { cout << e1 << endl; }
template <class T1, class T2>
void deb(T1 e1, T2 e2) { cout << e1 << " " << e2 << endl; }
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) { cout << e1 << " " << e2 << " " << e3 << endl; }
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl; }
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl; }
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) { cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl; }

// int dx[]= {-1,-1,0,0,1,1};
// int dy[]= {-1,0,-1,1,0,1};
// int dx[]= {0,0,1,-1};/*4 side move*/
// int dy[]= {-1,1,0,0};/*4 side move*/
// int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
// int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
// int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
// int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

constexpr int MOD = 998244353;

namespace ModCalculator
{
    inline int add(int a, int b)
    {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }
    inline int inc(int &a, int b) { return a = add(a, b); }
    inline int mult(ll a, ll b) { return (a * b) % MOD; }
};

using namespace ModCalculator;

class Matrix
{
public:
    int dim;
    std::vector<std::vector<int>> mat;
    Matrix() : dim(0) {}
    Matrix(int _dim) : dim(_dim), mat(_dim, std::vector<int>(_dim, 0)) {}
    Matrix(int _dim, int iVal) : dim(_dim), mat(_dim, std::vector<int>(_dim, iVal)) {}

    void set_identity()
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                mat[i][j] = (i == j) ? 1 : 0;
            }
        }
    }

    friend Matrix operator*(const Matrix &A, const Matrix &B)
    {
        Matrix ret(A.dim);
        for (int i = 0; i < A.dim; i++)
        {
            for (int j = 0; j < A.dim; j++)
            {
                int sum = 0;
                for (int k = 0; k < A.dim; k++)
                {
                    inc(sum, mult(A.mat[i][k], B.mat[k][j]));
                }
                ret.mat[i][j] = sum;
            }
        }
        return ret;
    }

    Matrix operator^(ll P) const
    {
        Matrix result(dim), base = *this;
        result.set_identity();
        while (P)
        {
            if (P & 1LL)
                result = result * base;
            base = base * base;
            P >>= 1LL;
        }
        return result;
    }

    void print() const
    {
        for (const auto &row : mat)
        {
            for (unsigned int val : row)
            {
                cerr << val << " ";
            }
            cerr << "\n";
        }
    }
};

int main()
{
#ifdef MAHDI
    //    Read;
    //    Write;
#endif // MAHDI
    Matrix Base;
    return 0;
}
