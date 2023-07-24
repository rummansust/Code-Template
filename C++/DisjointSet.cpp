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
#define psb(b) push_back(b)
#define ppb() pop_back()
#define oo 100000000000000000LL
#define swap(x,y) {int t;t=x;x=y;y=t;}
#define for_i(s,n) for(int i=s;i<n;i++)
#define for_j(s,n) for(int j=s;j<n;j++)
#define for_k(s,n) for(int k=s;k<n;k++)
#define MAX 100050

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

struct edge
{
  int parent,rank,member;
};

vector<edge> dset(MAX);

void makeset(int i)
{
  dset[i].parent=i;
  dset[i].rank=0;
  dset[i].member=1;
  return;
}

int findset(int u)
{
  if(dset[u].parent==u) return u;
  return dset[u].parent=findset(dset[u].parent);
}

void unionset(int u,int v)
{
  int up=findset(u);
  int vp=findset(v);
  if(dset[up].parent==dset[vp].parent) return;
  if(dset[up].rank<dset[vp].rank)
  {
    dset[up].parent=dset[vp].parent;
    dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
  }
  else
  {
    dset[vp].parent=dset[up].parent;
    dset[up].member=dset[vp].member=dset[up].member+dset[vp].member;
    if(dset[up].rank==dset[vp].rank)
      dset[up].rank=dset[up].rank+1;
  }
  return;
}

int main()
{
  int m,test;
  int u,v;
  string su,sv;
  map<string,int> data;
  scanf("%d",&test);
  while(test--)
  {
    data.clear();
    for_i(0,MAX) makeset(i);
    scanf("%d ",&m);
    for(int i=0,k=-1;i<m;i++)
    {
      cin>>su>>sv;
      if(data.find(su)==data.end())
        data[su]=++k;
      if(data.find(sv)==data.end())
        data[sv]=++k;
      u=data[su];v=data[sv];
      unionset(u,v);
      printf("%d\n",dset[findset(u)].member);
    }
  }
  return 0;
}
