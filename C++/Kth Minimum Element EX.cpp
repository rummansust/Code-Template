#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<complex>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<string.h>
#include<assert.h>
#include<time.h>

using namespace std;

#define SZ(x) (int) x.size()
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define clrall(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define ll long long
#define ull unsigned long long
#define SF scanf
#define PF printf
#define psb push_back
#define ppb pop_back
#define oo 1<<29
#define mp make_pair
#define fs first
#define sc second
#define __ std::ios_base::sync_with_stdio(false)

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

/**
 0 based indexing
 find kth min element in n sorted arrays
 work only with integer values
*/

struct data
{
    int mid1,mid2,len,i_idx;
    data(){}
    data(int m1,int m2,int l,int i):mid1(m1),mid2(m2),len(l),i_idx(i){}
};

bool cmp(const data &a,const data &b)
{
    if(a.mid2==b.mid3) return a.len>b.len;
    return a.mid2<b.mid2;
}

vector<int> arrays[30];
vector<pair<int,int> > interval;

/**
 when len = 0 or en-st+1=0 or (en = -1 && st = 0)
 the interval should be ignored.
*/

int kthElement(int k)
{
    int k_1=k-1;
    vector<data> info;
    int idx,len,mid1,mid2;
    int in_size = SZ(interval),st,en;
    int sLen=0;
    for(int i=0;i<in_size;i++)
    {
        st = interval[i].fs;
        en = interval[i].sc;
        len = en-st+1;
        sLen += len;
        info.psb(data(0,0,len,i));
    }

    for(int i=0;i<in_size;i++)
    {
        st = interval[i].fs;
        en = interval[i].sc;
        len=info[i].len;
        if(len==0) mid1 = mid2 = INT_MAX;
        else
        {
            idx = (int)(((ll)len*(ll)k_1)/(ll)sLen);
            mid1 = (idx==st?INT_MIN:arrays[idx-1]);
            mid2 = (idx==en+1?INT_MAX:arrays[idx]);
        }
        info[i].mid1 = mid1;
        info[i].mid2 = mid2;
    }

    sort(all(info),cmp);

}

int main()
{
    return 0;
}
















