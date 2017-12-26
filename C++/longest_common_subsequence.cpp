#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <sstream>

#define clr(name,val) memset(name,val,sizeof(name));
#define EPS .000000001
#define ll long long
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 1100

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

int table[MAX][MAX];
int LCS(string a,string b)
{
    int m=a.size(),n=b.size();
    for(int i=0;i<=m;i++) table[i][0]=0;
    for(int j=0;j<=n;j++) table[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }
    return table[m][n];
}

void print_LCS(string a,string b,int m,int n,string &s)
{
    if(!m||!n) return ;
    if(a[m-1]==b[n-1])
    {
        print_LCS(a,b,m-1,n-1,s);
        s+=a[m-1];
    }
    else if(table[m-1][n]>table[m][n-1]) print_LCS(a,b,m-1,n,s);
    else print_LCS(a,b,m,n-1,s);
}

int main()
{
    string a,b,s;
    int res;
    int cas=0;
    while(getline(cin,a))
    {
        getline(cin,b);
        res=LCS(a,b);
        printf("%d\n",res);
        s.clear();
        print_LCS(a,b,a.size(),b.size(),s);
        cout<<s<<endl;
        printf("Case #%d: you can visit at most %d cities.\n",++cas,res);
    }
    return 0;
}
