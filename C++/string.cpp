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

using namespace std;

int main (void)
{
    stringstream ss;
    int i,j,k,test,itgr,a,arr10[]= {1,10,100},s;
    char ch;
    string inp;
    while(cin>>test)
    {
        cin>>ch;
        while (test--)
        {
            getline (cin, inp);
            ss.clear ();
            ss.str ("");
            ss << inp;
            while (ss >> inp)
            {
                s=0;
                if(inp[0]>='0'&&inp[0]<='9')
                {
                    a=inp.size();
                    for(i=0; i<a; i++) if(inp[i]!='0') break;
                    if(i==a)
                    {
                        inp[0]='0';
                        inp[1]='\0';
                        a=1;
                    }
                    else
                    {
                        for(k=i,j=0; k<a; j++,k++)
                        {
                            inp[j]=inp[k];
                        }
                        inp[j]='\0';
                        a-=i;
                    }
                    for(i=a-1,j=0; i>-1; i--,j++)
                    {
                        s+=(inp[i]-'0')*arr10[j];
                    }
                    cout << s << endl;
                }
            }
        }
    }
    return 0;
}
