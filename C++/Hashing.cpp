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

const int MAX1 = 100010;

ll P1=59272331ll;
ll P2=84592337ll;
int ID[555];

ll PowerP1[MAX1];
ll PowerP2[MAX1];

ll InvP1[MAX1];
ll InvP2[MAX1];

ll HashStr1P1[MAX1];
ll HashStr1P2[MAX1];

ll HashStr2P1[MAX1];
ll HashStr2P2[MAX1];

void MakePowerInv(int n,int B)
{
    PowerP1[0]=1;
    PowerP2[0]=1;
    InvP1[0]=1;
    InvP2[0]=1;
    ll IP1=BigMod(B,P1-2,P1);
    ll IP2=BigMod(B,P2-2,P2);
    for(int i=1;i<=n;i++)
    {
        PowerP1[i]=(PowerP1[i-1]*B)%P1;
        PowerP2[i]=(PowerP2[i-1]*B)%P2;
        InvP1[i]=(InvP1[i-1]*IP1)%P1;
        InvP2[i]=(InvP2[i-1]*IP2)%P2;
    }
    return ;
}

void MakeHashTable(int n)
{
    for(int i=0;i<n;i++)
    {
        HashStr1P1[i]=(HashStr1P1[i]*PowerP1[i] + (i?HashStr1P1[i-1]:0))%P1;
        HashStr1P2[i]=(HashStr1P2[i]*PowerP2[i] + (i?HashStr1P2[i-1]:0))%P2;

        HashStr2P1[i]=(HashStr2P1[i]*PowerP1[i] + (i?HashStr2P1[i-1]:0))%P1;
        HashStr2P2[i]=(HashStr2P2[i]*PowerP2[i] + (i?HashStr2P2[i-1]:0))%P2;
    }
    return ;
}

char Str1[MAX1];
char Str2[MAX1];

int solve(int n,int k,int &st)
{
    vector<pair<int,int> > mpp;
    vector<pair<int,int> > :: const_iterator it;
    ll hash1,hash2;
    for(int i=0;i<n-k+1;i++)
    {
        hash1=(HashStr1P1[i+k-1]-(i==0?0:HashStr1P1[i-1]))*InvP1[i];
        hash1%=P1;
        if(hash1<0) hash1+=P1;

        hash2=(HashStr1P2[i+k-1]-(i==0?0:HashStr1P2[i-1]))*InvP2[i];
        hash2%=P2;
        if(hash2<0) hash2+=P2;

        mpp.psb(mp(hash1,hash2));
    }

    sort(all(mpp));

    for(int i=0;i<n-k+1;i++)
    {
        hash1=(HashStr2P1[i+k-1]-(i==0?0:HashStr2P1[i-1]))*InvP1[i];
        hash1%=P1;
        if(hash1<0) hash1+=P1;

        hash2=(HashStr2P2[i+k-1]-(i==0?0:HashStr2P2[i-1]))*InvP2[i];
        hash2%=P2;
        if(hash2<0) hash2+=P2;
        if(binary_search(all(mpp),mp((int)hash1,(int)hash2)))
        {
            st=i;
            return true;
        }
    }
    return false;
}

int main()
{
    #ifdef MAHDI
    Read;
//    Write;
    #endif // MAHDI
    int idx;
    int n,test;
    SF("%d",&n);
    SF("%s",&Str1);
    SF("%s",&Str2);
    idx=1;
    clrall(ID,-1);
    for(int i=0;i<n;i++)
    {
        if(ID[Str1[i]]==-1) ID[Str1[i]]=idx++;
        if(ID[Str2[i]]==-1) ID[Str2[i]]=idx++;
        HashStr1P1[i]=HashStr1P2[i]=ID[Str1[i]];
        HashStr2P1[i]=HashStr2P2[i]=ID[Str2[i]];
    }
    MakePowerInv(n,idx);
    MakeHashTable(n);
    int lo=1,hi=n,mid,res=0,st=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        if(solve(n,mid,st))
        {
            lo=mid+1;
            res=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(st==-1) PF("\n");
    else
    {
        for(int i=st;i<st+res;i++) PF("%c",Str2[i]);
        PF("\n");
    }
    return 0;
}












