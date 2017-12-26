/*
LOJ 1427
A string is a finite sequence of symbols that are chosen from an alphabet. In this
problem you are given a string T and n queries each with a string Pi, where the strings
contain lower case English alphabets only. You have to find the number of times Pi
occurs as a substring of T.

Input
Input starts with an integer T (≤ 10), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 500). The next line
contains the string T (1 ≤ |T| ≤ 10^6). Each of the next n lines contains a string Pi
(1 ≤ |Pi| ≤ 500).

Output
For each case, print the case number in a single line first. Then for each string Pi,
report the number of times it occurs as a substring of T in a single line.

Sample Input
Output for Sample Input
2
5
ababacbabc
aba
ba
ac
a
abc
3
lightoj
oj
light
lit
Case 1:
2
3
1
4
1
Case 2:
1
1
0
Notes
1.      Dataset is huge, use faster I/O methods.
2.       If S is a string then |S| denotes the length of S.
*/
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define REP(i,n)    for(i=0;i<n;i++)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[110][110],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
//*************************************************My Code Starts Here*********************************************************************************
#define wnum  510
#define wsize 510
#define strsize 1000010 //size of the main string
#define bacca   27     //number of child



#define Read freopen("in.txt","r",stdin)
#define Write freopen("outT.txt","w",stdout)



struct state
{
    int child[bacca],link,depth;
    vector<int>matched;
    void initialize(int dep)
    {
        mem(child,0);
        matched.clear();
        link=0;
        depth=dep;
    }
};
state T[wnum*wsize]; //normally total character
char words[wnum][wsize]; //1 based
int sz,last;  //sz=node no(1 based)(0 is root),last is used while iteration
char str[strsize];
int height[wsize],top[wnum*wsize]; //for topological sort
int freq[wsize*wnum],ans[wnum]; //O based. ans=occurance of the word in the string(not always needed). freq=substring frequency

void Initialize()  //normally only 1st node (initialize all for safety)
{
    T[0].initialize(0);
    sz=1;
    mem(height,0);
}

void Build_Aho_Corasick(int N) //how many node
{
    Initialize();
    int i,j,len,u,v,p;
    char ch;
    queue<int>Q;

    fr(i,1,N)
    {
        last=0;
        len=strlen(words[i]);
        REP(j,len)
        {
            ch=words[i][j]-'a'; //sometimes change here
            if(T[last].child[ch]==0){
                T[sz].initialize(j+1);
                T[last].child[ch]=sz++;
            }
            last=T[last].child[ch];
        }
        T[last].matched.pb(i);
    }

    fr(i,0,bacca-1)
    {
        if(T[0].child[i])
        {
            Q.push(T[0].child[i]);
            T[T[0].child[i]].link=0;
        }
    }

    while(!Q.empty())
    {
        u=Q.front();Q.pop();

        REP(i,bacca)
        {
            if(T[u].child[i])
            {
                p=T[u].link;
                v=T[u].child[i];
                while(p!=0 && T[p].child[i]==0)
                      p=T[p].link;
                T[v].link=T[p].child[i];
                Q.push(v);
            }
            else
                T[u].child[i] = T[T[u].link].child[i];
        }
    }

   for(i=0;i<sz;i++) height[T[i].depth]++;//,cout<<"i : "<<i<<" dep : "<<T[i].depth<<endl;
   for(i=1;i<wsize;i++) height[i]+=height[i-1];
   for(i=0;i<sz;i++) top[--height[T[i].depth]] = i;
}

void Search()
{
    int i,j,len,cur,p,v;
    char ch;

    cur=0;
    len=strlen(str);
    mem(freq,0);

    for(i=0;i<len;i++)
    {
        ch=str[i]-'a';
        if(T[cur].child[ch]==0)
        {
            p=T[cur].link;
            while(p>0 && T[p].child[ch]==0)
                p=T[p].link;
            cur=T[p].child[ch];
        }
        else
            cur=T[cur].child[ch];
        freq[cur]++;
    }

    for(i=sz-1;i>=0;i--)
    {
        v=top[i];
        freq[T[v].link]+=freq[v];
//        cout<<v<<" * "<<T[v].link<<endl;
    }
//    for(int i=0;i<sz;i++) cout<<freq[i]<<" ";
//    cout<<endl;

    for(i=1;i<sz;i++)
    {
        if(SZ(T[i].matched))
        {
            REP(j,SZ(T[i].matched))
                ans[T[i].matched[j]]=freq[i];
        }
    }
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    Read;
    Write;
    int test,Case=1,i,j,k,minv,u,v,id_no,N;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        scanf(" %s",str);

        fr(i,1,N)
            scanf(" %s",words[i]);

        Build_Aho_Corasick(N);

        Search();
        printf("Case %d:\n",Case++);
        fr(i,1,N)
            printf("%d\n",ans[i]);
    }
    return 0;
}
