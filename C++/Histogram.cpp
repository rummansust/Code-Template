#include<bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define clrint(name,val,s) memset(name,(val),sizeof(int)*s);
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS 10e-6
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
#define read_ freopen("in.txt","r",stdin)
#define write_ freopen("outTmp.txt","w",stdout)

/**
1 based indexing
*/

const int MAX = 50100;

int val[MAX];

int l[MAX],r[MAX];
int n;


void find_left_right()
{

    for(int i=1;i<=n;i++)
    {
        l[i]=r[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        while(l[i]>1 && val[i]<=val[l[i]-1])
        {
            l[i]=l[l[i]-1];
        }
    }
    for(int i=n;i>0;i--)
    {
        while(r[i]<n && val[i]<=val[r[i]+1])
        {
            r[i]=r[r[i]+1];
        }
    }
    return ;
}

int main()
{
    #ifdef rumman
    read_;
    write_;
    #endif // rumman
    return 0;
}













