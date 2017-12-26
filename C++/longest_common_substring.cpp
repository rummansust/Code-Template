#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define MAX

///next_permutation  next_permutation (s.begin(),s.end())
///reverse(a,a+n);
///binary_search(first,last);
///vector erase v.erase(v.begin()+position);
///map map<int , int > data;
///map clear  data.clear();
///map iterator>>>> map <int,vector <int> >::const_iterator it;
///find an element in map (colour.find(nd)==colour.end());//if it return true this
///mean the element is'nt in the map.
///pass a vector to a funtion: funtion (vector <data type> &vector name);
///make_pair  point=make_pair(i,j);
///access pair value point.first;point.second;

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int dp[200][200],par[200];
string str,str1,str2,str3;

int kmp(int len)
{
    clr(par,0);
    int k=0,mx=0;
    for(int i=1;i<len;i++)
    {
        while(k>1&&str[i]!=str[k]) k=par[k-1];
        if(str[i]==str[k]) ++k;
        par[i]=k;
        mx=max(mx,par[i]);
    }
    return mx;
}

int rec(int i,int j)
{
    if(i==-1||j==-1) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    ret=0;
    if(str1[i]==str2[j]) ret=rec(i-1,j-1) + 1;
    rec(i,j-1);
    rec(i-1,j);
    return ret;
}

void print(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return ;
}

stack<char> S;
string s;
int res;
map<string,int> mp;

void cheak()
{
    s.clear();
    while(!S.empty())
    {
        s+=S.top();S.pop();
    }
    if(mp.find(s)!=mp.end()) return ;
    mp[s]++;
    if(s.size()==0) return ;
    str=s+"#"+str3;
    int ret=kmp(str.size());
    if(ret!=s.size()) return ;
    res=max(res,ret);
    return ;
}

void pathrec1(int i,int j)
{
    if(i==-1||j==-1)
    {
        return ;
    }
    int l=i,r=j;
    while(l>-1&&r>-1)
    {
        if(l==0||r==0)
        {
            if(dp[l][r]) S.push(str1[l]);
            if(!S.empty()) cheak();
            break;
        }
        if(dp[l-1][r-1]<dp[l][r]) S.push(str1[l]);
        else
        {
            if(!S.empty()) cheak();
        }
        l--,r--;
    }
    pathrec1(i-1,j);
    return ;
}
void pathrec2(int i,int j)
{
    if(i==-1||j==-1)
    {
        return ;
    }
    int l=i,r=j;
    while(l>-1&&r>-1)
    {
        if(l==0||r==0)
        {
            if(dp[l][r]) S.push(str1[l]);
            if(!S.empty()) cheak();
            break;
        }
        if(dp[l-1][r-1]<dp[l][r]) S.push(str1[l]);
        else
        {
            if(!S.empty()) cheak();
        }
        l--,r--;
    }
    pathrec2(i,j-1);
    return ;
}

int main()
{
    int test,cas=0;
    scanf("%d ",&test);
    while(test--)
    {
        mp.clear();
        res=0;
        cin>>str1>>str2>>str3;
        clr(dp,-1);
        rec(str1.size()-1,str2.size()-1);
        pathrec1(str1.size()-1,str1.size()-1);
        pathrec2(str1.size()-1,str1.size()-1);
        cout<<res<<endl;
    }
    return 0;
}
