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
#include <limits.h>

#define clr(name,val) memset(name,(val),sizeof(name));
#define EPS .000000001
#define ll long long
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo 10000000
#define for_i(s,n) for(int i=(s);i<(n);(i)++)
#define for_j(s,n) for(int (j)=(s);(j)<(n);(j)++)
#define for_k(s,n) for(int (k)=(s);(k)<(n);(k)++)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
//#define mod (unsigned int) (1<<32)

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

struct matrix
{
    unsigned int mat[40][40];
};

int vm;

matrix matMul(matrix x,matrix y)
{
    matrix res;
    for(int i=0; i<vm; i++)
    {
        for(int j=0; j<vm; j++)
        {
            res.mat[i][j]=0;
            for(int k=0; k<vm; k++)
            {
                res.mat[i][j]=res.mat[i][j]+x.mat[i][k]*y.mat[k][j];
            }
        }
    }
    return res;
}

matrix matExpo(matrix A,int n)
{
    if(n==1) return A;
    matrix ret;
    if(n&1) ret=matMul(matExpo(A,n-1),A);
    else
    {
        ret=matExpo(A,n/2);
        ret=matMul(ret,ret);
    }
    return ret;
}

int main()
{
    int test,n,cas=0;
    matrix task;
    vector<pair<int,int> > v;
    for_i(0,38)for_j(0,38) task.mat[i][j]=0;
    for(int i=0; i<10; i++)
    {
        for(int j=i+2; j<10; j++)
        {
            v.psb(make_pair(i,j));
        }
    }
    vm=v.size();
    for(int i=0; i<vm; i++)
    {
        int c1=v[i].first;
        int c2=v[i].second;
        for(int j=0; j<vm; j++)
        {
            int c3=v[j].first;
            int c4=v[j].second;
            if(c1==c3||c1==c4||c2==c3||c2==c4) continue;
            if((c1+1)==c3||(c1+1)==c4||(c2+1)==c3||(c2+1)==c4) continue;
            if((c1-1)==c3||(c1-1)==c4||(c2-1)==c3||(c2-1)==c4) continue;
            task.mat[i][j]=1;
        }
    }
    cin>>test;
    while(test--)
    {
        cin>>n;
        unsigned int sum=0;
        if(n-1)
        {
            matrix res=matExpo(task,n-1);
            for(int i=0; i<vm; i++)
            {
                for(int j=0; j<vm; j++)
                {
                    sum=(sum+res.mat[i][j]);
                }
            }
        }
        else sum=36;
        printf("Case %d: %u\n",++cas,sum);
    }
    return 0;
}
