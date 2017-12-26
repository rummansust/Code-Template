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
#define oo (1<<28)
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
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


/**
                Problem Link -> http://codeforces.com/contest/558/problem/E
                Problem Description :

                ##########################################################################################
                ##                                                                                      ##
                ##  Given a string S of length n and q queries each query is on the format i j k which  ##
                ##  means sort the substring consisting of the characters from i to j in non-decreasing ##
                ##  order if k=1 or in non-increasing order if k=0                                      ##
                ##                                                                                      ##
                ##########################################################################################

*/


const int MAX = 282144;
int tree[26][MAX];

int lazy[26][MAX];

bool islazy[26][MAX];

void relax(int id,int idx,int l,int r,int val)
{
    int nidx=(idx<<1);
    tree[id][idx]=(r-l+1)*val;
    if(l!=r)
    {
        lazy[id][nidx]=val;
        lazy[id][nidx|1]=val;
        islazy[id][nidx]=true;
        islazy[id][nidx|1]=true;
    }
    lazy[id][idx]=islazy[id][idx]=false;
    return ;
}

int update(int id,int idx,int l,int r,int ql,int qr,int val)
{
    if(l>r || ql>qr) return 0;
    if(islazy[id][idx])
    {
        relax(id,idx,l,r,lazy[id][idx]);
    }
    if(l>=ql&&r<=qr)
    {
        relax(id,idx,l,r,val);
        return tree[id][idx];
    }
    if(l>qr||r<ql) return tree[id][idx];
    int mid=(l+r)>>1,nidx=(idx<<1);
    tree[id][idx]=update(id,nidx,l,mid,ql,qr,val)+update(id,nidx|1,mid+1,r,ql,qr,val);
    return tree[id][idx];
}

int query(int id,int idx,int l,int r,int ql,int qr)
{
    if(l>r || ql>qr) return 0;
    if(islazy[id][idx])
    {
        relax(id,idx,l,r,lazy[id][idx]);
    }
    if(l>=ql&&r<=qr)
    {
        return tree[id][idx];
    }
    if(l>qr||r<ql) return 0;
    int mid=(l+r)>>1,nidx=(idx<<1);
    return query(id,nidx,l,mid,ql,qr)+query(id,nidx|1,mid+1,r,ql,qr);
}

char str[MAX];
int num[MAX];

int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif
    int n,m;
    SF("%d %d",&n,&m);
    SF("%s",str);
    for(int i=0;i<n;i++)
    {
        num[i]=str[i]-'a';
    }
    for(int i=0;i<n;i++)
    {
        update(num[i],1,0,n-1,i,i,1);
    }
    int l,r,k;///k=1 choto theke boro, k=0 means boro theke choto;
    for(int i=0;i<m;i++)
    {
        SF("%d %d %d",&l,&r,&k);
        l--;r--;
        if(k)
        {
            int in=0,sum;
            for(int j=0;j<26;j++)
            {
                sum=query(j,1,0,n-1,l,r);
                update(j,1,0,n-1,l,r,0);
                update(j,1,0,n-1,l+in,l+in+sum-1,1);
                in+=sum;
            }
        }
        else
        {
            int in=0,sum;
            for(int j=25;j>-1;j--)
            {
                sum=query(j,1,0,n-1,l,r);
                update(j,1,0,n-1,l,r,0);
                update(j,1,0,n-1,l+in,l+in+sum-1,1);
                in+=sum;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(query(j,1,0,n-1,i,i))
            {
                str[i]=j+'a';
                break;
            }
        }
    }
    PF("%s\n",str);
    return 0;
}













