#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <algorithm>

#define clr(a,x) memset(a,x,sizeof(a));

using namespace std;

//int rr[]= {-1,-1,0,0,1,1};
//int cc[]= {-1,0,-1,1,0,1};
//int rr[]= {0,0,1,-1};/*4 side move*/
//int cc[]= {-1,1,0,0};/*4 side move*/
//int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int main(void)
{
    int p,x,y,flag,n,i,j,k;
    string s;
    stringstream ss;
    scanf("%d ",&n);
    while(n)
    {
        for(i=0;i<n-1;i++)
        {
            s.clear();
            ss.clear();
            getline(cin,s);
            cout<<s<<endl;
            ss<<s;
            flag=1;
            while(ss>>p)
            {
                if(flag)
                {
                    x=p;
                    flag=0;
                }
                else
                {
                    y=p;
                    cout<<x<<" "<<p<<endl;
                    flag=1;
                }
            }
        }
        scanf("%d ",&n);
    }
    return 0;
}
