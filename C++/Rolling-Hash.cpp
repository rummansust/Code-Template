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

const int MAX1 = 1010;
const int MAX2 = 1010;

ll P1=59272331ll;
ll P2=84592337ll;
int ID[555];

ll PowerP1[MAX1];
ll PowerP2[MAX1];

ll InvP1[MAX1];
ll InvP2[MAX1];

ll HashMainP1[MAX1][MAX1];
ll HashMainP2[MAX1][MAX1];

ll queryMatrix[MAX2][MAX2];

ll HashQueryP1[MAX2];
ll HashQueryP2[MAX2];

int Pattern[MAX2];

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

void MakeMainHashTable(int n,int m,int c)
{
    ll tmpP1[MAX1];
    ll tmpP2[MAX1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            HashMainP1[i][j]=(HashMainP1[i][j]*PowerP1[j] + HashMainP1[i][j-1])%P1;
            HashMainP2[i][j]=(HashMainP2[i][j]*PowerP2[j] + HashMainP2[i][j-1])%P2;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=c-1;j<m;j++)
        {
            if(j-c+1==0)
            {
                tmpP1[j-c+1]=HashMainP1[i][j];
                tmpP2[j-c+1]=HashMainP2[i][j];
            }
            else if(j-c+1>0)
            {
                tmpP1[j-c+1]=(HashMainP1[i][j]-HashMainP1[i][j-c])%P1;
                if(tmpP1[j-c+1]<0) tmpP1[j-c+1]+=P1;
                tmpP1[j-c+1]*=InvP1[j-c+1];
                tmpP1[j-c+1]%=P1;

                tmpP2[j-c+1]=(HashMainP2[i][j]-HashMainP2[i][j-c])%P2;
                if(tmpP2[j-c+1]<0) tmpP2[j-c+1]+=P2;
                tmpP2[j-c+1]*=InvP2[j-c+1];
                tmpP2[j-c+1]%=P2;
            }
        }
        for(int j=0;j<m-c+1;j++)
        {
            HashMainP1[i][j]=tmpP1[j];
            HashMainP2[i][j]=tmpP2[j];
        }
    }
    return ;
}

void MakeQueryHashTable(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        HashQueryP1[i]=HashQueryP2[i]=0;
        for(int j=0;j<m;j++)
        {
            HashQueryP1[i]=(queryMatrix[i][j]*PowerP1[j] + HashQueryP1[i])%P1;
            HashQueryP2[i]=(queryMatrix[i][j]*PowerP2[j] + HashQueryP2[i])%P2;
        }
    }
    return ;
}

int solveKmp(int nQ,int mQ,int n,int m)
{
    int cnt=0,k=0;
    Pattern[k]=0;
    for(int i=1;i<nQ;i++)
    {
        while(k>0 && (HashQueryP1[i]!=HashQueryP1[k] || HashQueryP2[i]!=HashQueryP2[k])) k=Pattern[k-1];
        if(HashQueryP1[i]==HashQueryP1[k] && HashQueryP2[i]==HashQueryP2[k]) k++;
        Pattern[i]=k;
    }
    for(int j=0;j<=m-mQ;j++)
    {
        k=0;
        for(int i=0;i<n;i++)
        {
            while(k>0 && (HashQueryP1[k]!=HashMainP1[i][j] || HashQueryP2[k]!=HashMainP2[i][j])) k=Pattern[k-1];
            if(HashQueryP1[k]==HashMainP1[i][j] && HashQueryP2[k]==HashMainP2[i][j]) k++;
            if(k>=nQ) cnt++,k=Pattern[k-1];
        }
    }
    return cnt>0;
}

char mainStr[MAX1][MAX1];
char queryStr[MAX2][MAX2];


void print(int n,int m,int r,int c)
{
    deb(":::::::::::::::::::::::::");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-c+1;j++)
        {
            PF("%8lld%c",HashMainP1[i][j]," \n"[j==m-c]);
        }
    }
    deb(":::::::::::::::::::::::::");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-c+1;j++)
        {
            PF("%8lld%c",HashMainP2[i][j]," \n"[j==m-c]);
        }
    }
    deb(":::::::::::::::::::::::::");
    for(int i=0;i<r;i++)
    {
        PF("%8lld\n",HashQueryP1[i]);
    }
    deb(":::::::::::::::::::::::::");
    for(int i=0;i<r;i++)
    {
        PF("%8lld\n",HashQueryP2[i]);
    }
    deb(":::::::::::::::::::::::::");
    return ;
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    int idx;
    int n,m,r,c,test;
    vector<string> v={"NO","YES"};
    SF("%d",&test);
    while(test--)
    {
        SF("%d %d",&n,&m);
        for(int i=0;i<n;i++) SF(" %s",&mainStr[i]);

        SF("%d %d",&r,&c);
        for(int i=0;i<r;i++) SF(" %s",&queryStr[i]);
        if(r>n||c>m)
        {
            PF("0\n");
            continue;
        }
        clrall(ID,-1);
        idx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ID[mainStr[i][j]]==-1) ID[mainStr[i][j]]=idx++;
                HashMainP1[i][j]=HashMainP2[i][j]=ID[mainStr[i][j]];
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(ID[queryStr[i][j]]==-1) ID[queryStr[i][j]]=idx++;
                queryMatrix[i][j]=ID[queryStr[i][j]];
            }
        }
        MakePowerInv(m,idx);
        MakeMainHashTable(n,m,c);
        MakeQueryHashTable(r,c);
        PF("%s\n",v[solveKmp(r,c,n,m)].c_str());
    }
    return 0;
}

/**
1
3 3
abc
bcd
cde
2 2
bc
cd
*/


/**
2
1 1
x
1 1
y
3 3
abc
bcd
cde
2 2
bc
cd
*/
/**
ll P1=1012454587ll;
ll P2=6524871251ll;
*/








