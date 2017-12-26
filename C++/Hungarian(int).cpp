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
#define Write freopen("1206M.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)
//*************************************************My Code Starts Here*********************************************************************************
//Andrei Lopatin
//return minimum cost (multiply -1 in each entry for maximum cost)
//1 based (0 is used for algorithm)
//Complexity O(n^2*m) or O(n^3)
#define INF 2000000000
#define rows 110
#define clms 110
int arr[rows][clms]; //main matrix
int  u[rows], v[clms]; //used for labeling
int p[clms] , way[clms]; //p = match , way = the augmenting path

//n = number of rows
//m = number of columns
//n<=m
int hungarian(int n,int m) {

    clrall(p,0);
    clrall(u,0);
    clrall(v,0);
    for ( int i = 1 ; i <= n ; ++ i ) {
        p [ 0 ] = i ;
        int j0 = 0 ;
        vector < int > minv ( m + 1 , INF ) ;
        vector < bool > used ( m + 1 , false ) ;
        do { //works like bfs
            used [ j0 ] = true ;
            int i0 = p [ j0 ] ,  delta = INF,  j1 ;
            for ( int j = 1 ; j <= m ; ++ j )
                if ( ! used [ j ] ) {
                    int cur = arr [ i0 ] [ j ] - u [ i0 ] - v [ j ] ;
				if ( cur < minv [ j ] )
					minv [ j ] = cur,  way [ j ] = j0 ;
				if ( minv [ j ] < delta )
					delta = minv [ j ] ,  j1 = j ;
                }

            //matrix doesn't change here
            for ( int j = 0 ; j <= m ; ++ j )
                if ( used [ j ] )
                    u [ p [ j ] ] += delta,  v [ j ] -= delta ;
                else
                    minv [ j ] -= delta ;
            j0 = j1 ;
            } while ( p [ j0 ] != 0 ) ;
        do {
                int j1 = way [ j0 ] ;
                p [ j0 ] = p [ j1 ] ;
                j0 = j1 ;
            } while ( j0 ) ;

    }

    return -v[0]; //minimum cost is stored here
}


int main()
{
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
        SF("%d",&arr[i][j]);
    cout<<hungarian(3,3)<<endl;
    return 0;
}

/**
100   4 900  25 900 900
900 100   9 900 900 900
900 900 100 900 900   1
900 900 900 100 900 900
900 900 900 900 100 900
900 900 900 900 900 100
*/













