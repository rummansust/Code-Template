/////////////////////////////////////////////////////////////////////////////////
///// problem name :  Suffix Array n*log(n)^2                               /////
///// author : Rumman Mahmud                                                /////
///// SUST CSE 2011331034                                                   /////
/////////////////////////////////////////////////////////////////////////////////


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

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
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
#define oo (1<<30)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("outputtest.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

using namespace std;

template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a>b?b:a;}
template<class T>inline T _GCD(T a,T b){if(b==0) return a;return _GCD(b,a%b);}
template<class T>inline T _LCM(T a,T b){T g=_GCD(a,b);return ((a/g)*b);}
template<class T>inline T big_mod(T a,T p,T MOD){if(p==0) return 1;T ret=big_mod(a,p/2,MOD);ret=(ret*ret)%MOD;if(ret<0) ret+=MOD;if(p%2) ret=(ret*a)%MOD;if(ret<0) ret+=MOD;return ret;}
template<class T>inline T power(T a,T p){if(p==0) return 1;ll ret=power(a,p/2);ret=(ret*ret);if(p%2) ret=(ret*a);return ret;}
template<class T0,class T1,class T2>inline T1 string_mod_ll(T0 s,T1 mm,T2 Sz){T1 n=0;for(int i=0;i<Sz;i++){n=n*10+(ll)(s[i]-'0');n%=mm;}return n;}

int compare(string a,string b){if(a==b) return 0;if(SZ(a)==SZ(b)){for(int i=0; i<SZ(a); i++){if(a[i]>b[i]) return 1;else if(a[i]<b[i]) return -1;}return -1;}if(SZ(a)>SZ(b)) return 1;return -1;}
string string_add(string b,string a){if(SZ(a)>SZ(b)) swap(a,b);a=string((SZ(b)-SZ(a)),'0')+a;int carry=0,add;string res;for(int i=SZ(a)-1; i>-1; i--){add=(int)(a[i]-'0')+(int)(b[i]-'0')+carry;carry=add/10;res+=(add%10)+'0';}if(carry) res+=carry+'0';reverse(res.begin(),res.end());return res;}
string string_mul(string a,string b){if(SZ(a)>SZ(b)) swap(a,b);string res,tres;int l=0,carry,mul;for(int i=SZ(a)-1; i>-1; i--){tres=string(l,'0');carry=0;for(int j=SZ(b)-1; j>-1; j--){mul=(int)(a[i]-'0')*(int)(b[j]-'0')+carry;carry=mul/10; tres+=(mul%10)+'0'; }if(carry) tres+=carry+'0';reverse(tres.begin(),tres.end());res=string_add(tres,res);l++;}return res;}
void cut_leading_zero(string &res){int i;for(i=0; i<SZ(res); i++){if(res[i]!='0') break;}res=res.substr(i);if(!SZ(res)) res="0";return;}

///pass a vector to a funtion: funtion (vector <data type> &vector name);
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define MAXL 65000
#define MAXH 17

struct SAS
{
    int tup[2];
    int idx;
    SAS()
    {
        clrall(tup,0);
        idx=0;
    }
};

SAS TA[MAXL];
int SA[MAXH][MAXL],LCP[MAXL],last_;
int ID[500];
string text;

bool comp(struct SAS a,struct SAS b)
{
    return a.tup[0]==b.tup[0]?(a.tup[1]<b.tup[1]?true:false):(a.tup[0]<b.tup[0]?true:false);
}

void buildSAS()
{
    int i,j,k,N;
    N=(int) SZ(text);
    rep(i,0,N)
    {
        SA[0][i] = ID[text[i]];///initialize tree
        TA[i]=SAS();
    }
    int step=1,jump=1;
    for(;jump<=N;jump<<=1,step++)
    {
        rep(i,0,N)
        {
            TA[i].idx = i;
            TA[i].tup[0] = SA[step-1][i];/// tup1 sort-index before.
            TA[i].tup[1] = i+jump<N?SA[step-1][i+jump]:-1;/// tup2 sort-index after.
        }
        sort(TA,TA+N,comp);/// sort by first tup then second tup.
        rep(i,0,N)
        {
            SA[step][TA[i].idx] = i>0 && TA[i].tup[0]==TA[i-1].tup[0] && TA[i].tup[1]==TA[i-1].tup[1]?SA[step][TA[i-1].idx]:i;
            /// if first jump characters of two suffix are same then their indx will be same, otherwise i.
        }
    }
    last_=step;
    cout<<"Suffix Array:\n\n";
    rep(i,0,N) cout<<setw(2)<<i<<"  "<<text.substr(TA[i].idx)<<endl;
    return ;
}

int buildLCP()
{
    LCP[0]=0;
    int N=SZ(text),i,j,k,id1,id2;
    cout<<"\nLCP:\n\n"<<setw(2)<<0<<" "<<0<<endl;
    int ret=0;
    rep(i,1,N)
    {
        id1=TA[i].idx;
        id2=TA[i-1].idx;
        LCP[i]=0;
        rvp(k,0,last_)
        {
            if(SA[k][id1]==SA[k][id2]&&SA[k][id2]!=-1)
            {
                LCP[i]+=(1<<k);
                id1+=(1<<k);
                id2+=(1<<k);
            }

        }
        ret+=LCP[i];
        cout<<setw(2)<<i<<" "<<LCP[i]<<endl;
    }
    return ret;
}

void makeID()
{
    int i,j,k;
    rep(i,('A'),('Z'+1)) ID[i]=(int) (i-'A');
    rep(i,('a'),('z'+1)) ID[i]=(int) (i-'a')+26;
    return ;
}

string tmp;

int main()
{
    __;
    makeID();
    int res,N,test,cas=0;
    cin>>test;
    while(test--)
    {
        clrall(SA,-1);
        cin>>text;
        buildSAS();
        N=SZ(text);
        res=N*(N+1);
        res>>=1;
        res-=buildLCP();
        cout<<"Distinct sub-string : "<<res<<endl;
    }
    return 0;
}

/*
MISSISSIPPI
Suffix Array:

 0  I
 1  IPPI
 2  ISSIPPI
 3  ISSISSIPPI
 4  MISSISSIPPI
 5  PI
 6  PPI
 7  SIPPI
 8  SISSIPPI
 9  SSIPPI
10  SSISSIPPI

LCP:

 0 0
 1 1
 2 1
 3 4
 4 0
 5 0
 6 1
 7 0
 8 2
 9 1
10 3
*/
















