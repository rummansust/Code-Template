#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 40010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair

using namespace std;

bool blk[205][205];
vector<int>adj[MAX];
int xx[]={1,1,2,2,-1,-1,-2,-2};
int yy[]={2,-2,1,-1,2,-2,1,-1};
int arr[MAX], col[MAX], CL;

bool dfs(int u)
{
    int v, i;
    if(col[u]==CL) return false;
    col[u]=CL;
    for(i=0;i<SZ(adj[u]);i++)
    {
        v = adj[u][i];
        if(arr[v]==-1)
        {
            arr[v] = u;
            return true;
        }
    }
    for(i=0;i<SZ(adj[u]);i++)
    {
        v = adj[u][i];
        if(dfs(arr[v]))
        {
            arr[v]=u;
            return true;
        }
    }
    return false;
}

int bpm(int n, int m)
{
    int i, j, ret=0, cur; CL=1;
    memset(arr, -1, sizeof arr);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if((i+j)&1) continue;
            cur = (i-1)*m + j;
            if(blk[i][j]==false)
            {
                CL++;
                if(dfs(cur))
                    ret++;
            }
        }
    }
    return ret;
}

int main()
{
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int u, v, n, m, i, j, k, K;
        scanf("%d%d%d", &n, &m, &K);
        memset(blk, false, sizeof blk);
        memset(col, 0, sizeof col);
        for(i=0;i<=(n*m);i++) adj[i].clear();
        for(i=0;i<K;i++)
        {
            scanf("%d%d", &u, &v);
            blk[u][v]=true;
        }
        int cnt=1, cur, nxt, nx, ny, N;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(blk[i][j]) continue;
                cur = (i-1)*m + j;
                for(k=0;k<8;k++)
                {
                    nx = i+xx[k], ny = j+yy[k];
                    if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
                    if(blk[nx][ny]) continue;

                    nxt = (nx-1)*m + ny;
                    adj[cur].pb(nxt);
                }
            }
        }
        N = n*m;
        int sol = bpm(n, m);
        int ans = N-sol-K;
        csprnt;
        printf("%d\n", ans);
    }
    return 0;
}
