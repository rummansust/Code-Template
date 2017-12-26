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
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

#define casePrint PF("Case #%d: ",++cas);


const int MAX = 1000100;

//pointer=0,last=0 should be made initially
ll M[MAX],C[MAX]; //y=mx+c we need only m(slope) and c(constant)

//Returns true if either line l1 or line l3 is always better than line l2
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (c1-c2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (c1-c3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	//if the query x values is non-decreasing (reverse(> sign) for vice verse)
	return (C[l3]-C[l1])*(M[l1]-M[l2])<=(C[l2]-C[l1])*(M[l1]-M[l3]);
}

//Adding should be done serially
//If we want minimum y coordinate(value) then maximum valued m should be inserted first
//If we want maximum y coordinate(value) then minimum valued m should be inserted first
void add(long long m,long long c,int &last)
{
	//First, let's add it to the end
	M[last]=m;
	C[last++]=c;
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	//in short convex hull main convex hull tecnique is applied here
	while(last>=3&&bad(last-3,last-2,last-1))
	{
		M[last-2]=M[last-1];
		C[last-2]=C[last-1];
		last--;
	}
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//line(x) and the lower/upper envelope(pointer)
//This can only be applied if the query of vertical line(x) is already sorted
//works better if number of query is huge
long long query(long long x,int &pointer,int last)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=last)
		pointer=last-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
    // Min Value wanted... (reverse(> sign) for max value)
	while (pointer<last-1 && M[pointer+1]*x+C[pointer+1]<=M[pointer]*x+C[pointer])
		pointer++;
	return M[pointer]*x+C[pointer];
}

//for any kind of query(sorted or not) it can be used
//it works because of the hill property
//works better if number of query is few
long long bs(int st,int end,long long x,int last)
{
    int mid=(st+end)/2;
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid+1<last && M[mid+1]*x+C[mid+1]<M[mid]*x+C[mid]) return bs(mid+1,end,x,last);
    // Min Value wanted... (reverse(> sign) for max value)
    if(mid-1>=0 && M[mid-1]*x+C[mid-1]<M[mid]*x+C[mid]) return bs(st,mid-1,x,last);
    return M[mid]*x+C[mid];
}


int main()
{
    #ifdef rumman
//    Read;
//    Write;
    #endif // rumman
    return 0;
}

















