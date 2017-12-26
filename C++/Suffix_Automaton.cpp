/**SUFFIX AUTOMATA*/
#include "bits/stdc++.h"
#define clrall(name,val) memset(name,(val),sizeof(name));
using namespace std;
#define MAX 10100
struct info
{
    int par,len;
    int child[26];
};
info T[(MAX<<1)];
int last,it;
char text[MAX];
void init(const int &);
void suffix_automata(int);
void add_char(int id);
void add_char(int id)
{
    int cur,clone,pre,next;
    cur=it++;
    init(cur);
    /**increment length;*/
    T[cur].len=T[last].len+1;
    /**parent to child connection;*/
    for(pre=last;pre!=-1&&T[pre].child[id]==-1;pre=T[pre].par) T[pre].child[id] = cur;
    /**find parent of current node or clone node if needed;*/
    if(pre==-1) T[cur].par=0;
    else
    {
        /**
        clone node needed if cur node is not the next node of pre;
        we need to split the edge. but it's unnecessary to split
        when two nodes are adjacent(means the length difference is one).
        */
        next=T[pre].child[id];
        if(T[next].len==T[pre].len+1) T[cur].par=next;
        else
        {
            /**
            make clone node and copy all data from which node
            is responsible for repeating to clone node;
            */
            clone=it++;
            init(clone);
            T[clone]=T[next];
            T[clone].len=T[pre].len+1;
            for(;T[pre].child[id]==next;pre=T[pre].par) T[pre].child[id]=clone;
            T[cur].par=T[next].par=clone;
        }
    }
    last=cur;
    return ;
}
void init(const int &node)
{
    T[node].len=0;
    T[node].par=-1;
    clrall(T[node].child,-1);
    return ;
}
void suffix_automata(int n)
{
    last=0;
    it=1;
    init(0);
    for(int i=0;i<n;i++) add_char(text[i]-'a');
    return ;
}
int main()
{
    int test,cas=1,len,low,high,l,r;
    long long ans;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",text);
        scanf("%d %d",&l,&r);
        len=strlen(text);
        suffix_automata(len);
        ans=0;
        for(int i=0;i<it;i++)
        {
            high=T[i].len;
            low=T[T[i].par].len+1;
            if(low>r || high<l) continue;
            high=min(high,r);
            low=max(low,l);
            ans+=(high-low+1);
        }
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}







