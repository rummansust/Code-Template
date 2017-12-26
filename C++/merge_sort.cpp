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
#define MAX 10000

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

using namespace std;

///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

struct point
{
    int x,y;
};

int data[MAX];

void make_merge_sort(int ls,int le,int rs,int re)
{
    int tmp[MAX],k=0,i,j;
    bool flag=true;
    for(i=ls,j=rs;;)
    {
        if(i>le)
        {
            flag=false;
            break;
        }
        else if(j>re) break;
        if(data[i]<=data[j])
        {
            tmp[k++]=data[i];
            i++;
        }
        else
        {
            tmp[k++]=data[j];
            j++;
        }
    }
    if(!flag)
    {
        for(int m=j;m<=re;m++)
        {
            tmp[k++]=data[m];
        }
    }
    else
    {
        for(int m=i;m<=le;m++)
        {
            tmp[k++]=data[m];
        }
    }
    for(i=ls,j=0;i<=re;i++,j++) data[i]=tmp[j];
    return;
}

point merging(int lb,int ub)
{
    if(lb==ub)
    {
        point tmp;
        tmp.x=lb;
        tmp.y=ub;
        return tmp;
    }
    int mid=(lb+ub)/2;
    point p=merging(lb,mid);
    point q=merging(mid+1,ub);
//    cout<<p.x<<" "<<p.y<<" "<<q.x<<" "<<q.y<<endl;
    make_merge_sort(p.x,p.y,q.x,q.y);
    point tmp;
    tmp.x=lb;tmp.y=ub;
    return tmp;
}

int main()
{
    int test,element,cas=0;
    cin>>test;
    while(test--)
    {
        cin>>element;
        for(int i=0;i<element;i++) cin>>data[i];
        merging(0,element-1);
        for(int i=0;i<element;i++) cout<<data[i]<<" ";
        cout<<endl;
    }
    return 0;
}
