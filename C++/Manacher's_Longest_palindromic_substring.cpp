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
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint PF("Case #%d: ",++cas);

///Manachar's Algorithm for longest palindromic substring
///0 based
const int MAX = 2001000; ///twice of string size memory needed

char text[MAX];
int P[MAX];

void process(int &len)
{
    int i,j;
    char ch;
    SF("%s",&text);
    if(strcmp(text,"END")==0)
    {
        len=-1;
        return ;
    }
    len = strlen(text);
    for(i=len-1;i>-1;i--)
    {
        j=i+1;
        text[(j<<1)]=text[i];
        text[(j<<1)+1]='#';
    }
    text[0]='^';
    text[1]='#';
    text[((len<<1)+2)]='$';
    text[((len<<1)+3)]='\0';
    len<<=1;
    len+=3;
    return ;
}
///ret.fs=maxPal,ret.sc=pos of maxPal

pair<int,int> Manacher(int N)
{
    int R,C,i_,lb,rb;
    R=C=0;
    pair<int,int> ret;
    ret.fs=ret.sc=0;
    P[0]=0;
    for(int i=1;i<N-1;i++)
    {
        i_=2*C-i;
        P[i] = (R>i && i_>-1)?min(P[i_],R-i):0;
        lb=i-1-P[i];
        rb=i+1+P[i];
        while(lb>-1 && rb<N && text[lb] == text[rb])///***check bound here
        {
            P[i]++;
            lb=i-1-P[i];
            rb=i+1+P[i];
        }
        if(i+P[i]>R)
        {
            C=i;
            R=i+P[i];
        }
        if(ret.fs<P[i])
        {
            ret.fs=P[i];
            ret.sc=i;
        }
    }
    return ret;
}

int main()
{
    int test,N,cas=0;
    pair<int,int> res;
    SF("%d",&test);
    while(test--)
    {
        process(N);
        if(N==-1) break;
        res=Manacher(N);
        PF("Case %d: %d\n",++cas,res.fs);
    }
}








