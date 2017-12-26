#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

//#define USE_SIGN // Define this to have signed custom int I/O

// Turn on iostreams optimizations
inline void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//
// Custom int write and read functions
//
// FIXME: Can't read or write INT_MIN
// TODO: Can these functions be further sped up?
//

inline void write_int(int x)
{
#ifdef USE_SIGN
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
#endif

    char buf[10], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
}

inline int read_int()
{
    char c;

    while (c = getchar(), c <= ' ');

#ifdef USE_SIGN
    bool sign = c == '-';
    if (sign)
    {
        c = getchar();
    }
#endif

    int res = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
    {
        res = res * 10 + (c - '0');
    }
    // One character is gobbled here

#ifdef USE_SIGN
    return sign ? -res : res;
#else
    return res;
#endif
}

int arr[101000];

int main()
{
    init();
    int n,t;
    t=read_int();
    while(t--)
    {
        n=read_int();
        for(int i=0;i<n;i++)
        {
            arr[i]=read_int();
        }
    }
    return 0;
}



















