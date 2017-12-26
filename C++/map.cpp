#include <cstdio>
#include <cmath>
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
#include <algorithm>

#define clr(a,x) memset(a,x,sizeof(a));

//reverse(a,a+n);
//binary_search(first,last);
//vector erase v.erase(v.begin(),position);
//map map<int , int > data;
//map clear  data.clear();

using namespace std;

int main(void)
{
    int n,i,s;
    map<int , int > data;
    vector <int> v;
    while(cin>>n)
    {
        if(data[n]==0) v.push_back(n);
        data[n]++;
    }
    s=(int) data.size();
    for(i=0;i<s;i++)
    {
        cout<<v[i]<<" "<<data[v[i]]<<endl;
    }
//    map<int , int>::const_iterator it;
//    for(it=data.begin();it!=data.end();++it)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
    return 0;
}
