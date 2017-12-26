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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)


string get="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int data[500];

string a_to_b(int a,int b,string &s);
ll a_to_10(int a,string &s);
string ten_to_b(int b,ll n);

void init()
{
    for(int i=0;i<get.size();i++)
    {
        data[get[i]]=i;
    }
}

string a_to_b(int a,int b,string &s)
{
    ll n=a_to_10(a,s);
    return ten_to_b(b,n);
}

ll a_to_10(int a,string &s)
{
    ll pr=1,n=0;
    for(int i=s.size()-1;i>-1;i--)
    {
        n+=(pr*data[s[i]]);
        pr*=a;
    }
    return n;
}

string ten_to_b(int b,ll n)
{
    string res;
    if(n==0) return "0";
    while(n)
    {
        res+=(get[n%b]);
        n/=b;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    return 0;
}















