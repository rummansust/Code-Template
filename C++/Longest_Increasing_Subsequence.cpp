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

#define clr(a,x) memset(a,x,sizeof(a));
#define ll long long
#define pb(b) push_back(b)
#define oo 100000000000000000LL
#define SZ 1000000

//reverse(a,a+n);
//binary_search(first,last);
//vector erase v.erase(v.begin(),position);
//map map<int , int > data;
//map clear  data.clear();

using namespace std;
//bool colour[210][210];
//int rr[]= {-1,-1,0,0,1,1};
//int cc[]= {-1,0,-1,1,0,1};
//int rr[]= {0,0,1,-1};/*4 side move*/
//int cc[]= {-1,1,0,0};/*4 side move*/
//int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

ll arr[SZ],tmp[SZ],L[SZ],lis_seq[SZ];

ll bin_search(ll item,ll start,ll end)
{
    ll mid=(start + end) / 2;
    while(start <= end)
     {
//        if(tmp[mid]==item) return mid;
        if(start==end) break;
        if(tmp[mid] > item) end=mid;
        else start=mid+1;
        mid=(start+end)/2;
    }
    return end;
}
ll lis_constructor_fun(ll n)
{
    ll start=0,end=n,lis_len=0,loc;//set lowerbound & upper bound for b_search
    tmp[0]=-oo;//set -infinity
    for(ll i=1;i<=n;i++)//set infinity
        tmp[i]=oo;
    for(ll i=0;i<n;i++)//construct L[] arry.
    {
        loc=bin_search(arr[i],start,end);//pick loc and set element.
        tmp[loc]=arr[i];
        lis_len=max(loc,lis_len);//find maximum length
        L[i]=loc;//set loc in L[] for find lis next.
        end=lis_len+1;//this is k
    }
    return lis_len;
}
void print_fun(ll len,ll n)//printing lis.
{
    ll tt=len;
    for(ll i=n-1;i>-1;i--)
    {
        if(L[i]==len)
        {
            lis_seq[--len]=arr[i];
            if(!len) break;
        }
    }
    for(ll i=0;i<tt;i++) cout<<lis_seq[i]<<" ";
    cout<<endl;
    return;
}
int main()
{
    ll n,len;
    while(cin>>n)
    {
        for(ll i=0;i<n;i++)//input sequence
        {
            cin>>arr[i];
        }
        len=lis_constructor_fun(n);//find lis length
//        for(ll i=0;i<n;i++) cout<<L[i]<<" ";
//        cout<<endl;
        cout<<len<<endl;//print lis length
        print_fun(len,n);//print lis
        for(ll i=0;i<n;i++) cout<<L[i]<<" ";
        cout<<endl;
    }
    return 0;
}
