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
#define MAX 10001000
#define MAX2 2500550

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

vector<ll> divs;
bool sieve[MAX];
int prime[MAX2];
vector<ll> prime_div;

void sieve_fun()
{
    int k=0,r;
    prime[k++]=2;
    for(int i=3;i<MAX;i+=2)
    {
        if(!sieve[i])
        {
            prime[k++]=i;
            r=i<<1;
            if(i<MAX/i)
            {
                for(int j=i*i;j<MAX;j+=r)
                {
                    sieve[j]=1;
                }
            }
        }
    }
    return ;
}

void div_find(ll n)
{
    int sq=sqrt(n)+1;
//    cout<<"here 1 :"<<sq<<endl;
    for(int i=0;prime[i]<sq;i++)
    {
        if(!(n%prime[i]))
        {
            while(!(n%prime[i]))
            {
                prime_div.psb((ll) prime[i]);
                n/=prime[i];
            }
            sq=sqrt(n)+1;
//            cout<<"here 2 :"<<sq<<endl;
        }
    }
    if(n>1) prime_div.psb((ll) n);
    return ;
}

void all_div_find()
{
    map<ll,int> data;
    divs.psb(1L);
    for(int i=0;i<prime_div.size();i++)
    {
        for(int j=divs.size()-1;j>-1;j--)
        {
            ll w=prime_div[i]*divs[j];
            if(data.find(w)==data.end())
            {
                divs.psb(w);
                data[w]=0;
            }
        }
    }
    return ;
}

int main()
{
    sieve_fun();
    int test,cas=0;
    ll n;
    cin>>test;
    while(test--)
    {
        cin>>n;
        divs.clear();prime_div.clear();
        div_find(n);
        cout<<"scenario#"<<++cas<<endl;
        for_i(0,prime_div.size())
        {
            if(i) cout<<" ";
            else cout<<"prime divisor : ";
            cout<<prime_div[i];
        }
        cout<<endl;
        all_div_find();
        sort(divs.begin(),divs.end());
        for_i(0,divs.size())
        {
            if(i) cout<<" ";
            else cout<<"all divisor : ";
            cout<<divs[i];
        }
        cout<<endl;
        cout<<"number of divisor : "<<divs.size()<<endl;
    }
    return 0;
}
