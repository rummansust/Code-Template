#include <cstdio>
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

using namespace std;

deque <string> dQ;
//void insert(bool f,string &s)
//{
//    if(f)dQ.push_back(s);
//    else dQ.push_front(s);
//    s="";
//    return;
//}

int main(void)
{
    char c;
    bool flag=true;
    string s;
    while(c=getchar())
    {
        if(c==EOF) break;
        if(c=='\n')
        {
//            insert(flag,s);
            while(dQ.size())
            {
                printf("%s",dQ.front().c_str());
                dQ.pop_front();
            }
            printf("\n");
            dQ.clear();
            s = "";
//            flag=true;
        }
//        else if(c=='[')
//        {
//            if(s!="")
//            {
//                insert(flag,s);
//            }
//            flag=false;
//        }
//        else if(c==']')
//        {
//            if(s!="")
//            {
//                insert(flag,s);
//            }
//            flag=true;
//        }
        else
        {
            s=c;
            dQ.push_front(s);
        }
    }
    return 0;
}
