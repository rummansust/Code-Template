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
#include <utility>
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
#define oo 0x7fffffff
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

/// 0 based indexing

const int MAX = 100500;
const int SQSZ = 555;

vector<int> mValue[SQSZ];
vector<int> dValue[SQSZ];
int Hi[MAX];

int idx[MAX];

void build(int n)
{
    for(int i=0;i<n;i++) sort(all(dValue[i]));
    return ;
}

int queryLeft(int i,int x)
{
    int id=idx[i];
    int n=SZ(mValue[id]);
    int cnt=0;
    int s=i%SQSZ;
    for(int k=s;k<n;k++)
    {
        if(mValue[id][k]<=x) cnt++;
    }
    return cnt;
}

int queryRight(int i,int x)
{
    int id=idx[i];
    int n=SZ(mValue[id]);
    int cnt=0;
    int e=i%SQSZ;
    for(int k=0;k<=e;k++)
    {
        if(mValue[id][k]<=x) cnt++;
    }
    return cnt;
}

int query(int l,int r,int x)
{
    int ret=0;
    int lid=idx[l];
    int rid=idx[r];
    if(lid==rid)
    {
        l%=SQSZ;
        r%=SQSZ;
        for(int i=l;i<=r;i++)
        {
            if(mValue[lid][i]<=x) ret++;
        }
        return ret;
    }
    ret=queryLeft(l,x)+queryRight(r,x);
    for(int k=lid+1;k<rid;l++)
    {
        ret+=upper_bound(all(dValue[k]),x)-dValue[k].begin();
    }
    return ret;
}

void update(int i)
{
    int id=idx[i];
    int ti=i%SQSZ;
    int n=SZ(dValue[id]);
    mValue[id][ti]=oo;
    for(int k=ti+1;k<n;k++)
    {
        dValue[id][k-1]=dValue[id][k];
        if(k==n-1)
        {
            dValue[id][k]=oo;
        }
    }
    return ;
}


struct Query
{
    int l,r,idx;
    Query(){}
    Query(int l,int r,int idx):l(l),r(r),idx(idx){}
};

bool cmpLeft(const Query &a,const Query &b)
{
    return a.l<b.l;
}

bool cmpRight(const Query &a,const Query &b)
{
    return a.r>b.r;
}

ll finalRes[MAX];
Query qInfo[MAX];

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int n,v,k;
    int lim;
    SF("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        SF("%d",&Hi[i]);
    }
    lim=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<SQSZ&&i<n;j++,i++)
        {
            mValue[lim].psb(Hi[i]);
            dValue[lim].psb(Hi[i]);
        }
        lim++;
    }
    build(lim);
    ll res=0;
    int lo,hi;
    for(int i=0;i<n;i++)
    {
        hi=k+Hi[i];
        lo=Hi[i]-k-1;
        res+=query(i+1,n-1,hi)-query(i+1,n-1,lo);
    }
    deb(res);

    int q;
    SF("%d",&q);
    int l,r;


    /**
    incomplete
    */
    return 0;
}














