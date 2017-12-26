#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define clrall(name,val) memset(name,(val),sizeof(name))
#define ll long long

///0 based indexing

const int MAX = 100105;

int tree[MAX],bitN;

void init (int n)
{
	bitN = n;
	memset(tree,0,sizeof(int)*n);
}
/**
1 based indexing
compute SUM(1->i)
*/
int query(int i)
{
    int res=0;
    while(i>0)
    {
        res+=tree[i];
        i-=(i & -i);
    }
    return res;
}

void update(int i,int delta)
{
    while(i<bitN)
    {
        tree[i]+=delta;
        i+=(i & -i);
    }
}

/**
for SUM(MAX->i) just reverse the process.
void update(int i,int delta)
{
    while(i>0)
    {
        tree[i]+=delta;
        i-=(i & -i);
    }
}
int query(int i)
{
    int res=0;
    i=max(1,i);
    while(i<bitN)
    {
        res+=tree[i];
        i+=(i & -i);
    }
    return res;
}
*/

int val[105],s;

int main()
{
    int test,cas=0,i,j,k,a,b,c,n;
    ll res;
    int d;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
        }
        sort(val,val+n);
        res=1;
        for(i=0;i<6;i++) res*=(ll)(n-i);
        res/=720ll;
        s=MAX-10;
        init(s+5);
        for(i=2;i<n-2;i++)
        {
            a=val[i];
            for(j=i+2;j<n;j++)
            {
                b=val[j];
                for(k=i+1;k<j;k++)
                {
                    c=val[k];
                    res-=(ll)query(b-a-c);
                }
            }
            for(j=0;j<i;j++)
            {
                b=val[j];
                for(k=j+1;k<i;k++)
                {
                    c=val[k];
                    update(a+b+c,1);
                }
            }
        }
        printf("Case %d: %lld\n",++cas,res);
    }
    return 0;
}













