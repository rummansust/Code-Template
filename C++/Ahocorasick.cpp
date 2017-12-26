#include <bits/stdc++.h>

using namespace std;

#define SZ(s)       ((int)s.size())
#define pb          push_back
#define wnum  510
#define wsize 510
#define strsize 1000010 //size of the main string
#define bacca   27     //number of child
#define mem(a,b)    memset(a,b,sizeof(a))

#define Read freopen("in.txt","r",stdin)
#define Write freopen("outR.txt","w",stdout)



struct state
{
    int child[bacca],link,depth;
    vector<int>matched;
    void initialize(int dep)
    {
        mem(child,0);
        matched.clear();
        link=0;
        depth=dep;
    }
};
state T[wnum*wsize]; //normally total character
char words[wnum][wsize]; //1 based
int sz,last;  //sz=node no(1 based)(0 is root),last is used while iteration
char str[strsize];
int height[wsize],top[wnum*wsize]; //for topological sort
int freq[wsize*wnum],ans[wnum]; //O based. ans=occurance of the word in the string(not always needed). freq=substring frequency

void Initialize()  //normally only 1st node (initialize all for safety)
{
    T[0].initialize(0);
    sz=1;
    mem(height,0);
}

void Build_Aho_Corasick(int N) //how many node
{
    Initialize();
    int i,j,len,u,v,p;
    char ch;
    queue<int>Q;

    for(i=1;i<=N;i++)
    {
        last=0;
        len=strlen(words[i]);
        for(j=0;j<len;j++)
        {
            ch=words[i][j]-'a'; //sometimes change here
            if(T[last].child[ch]==0){
                T[sz].initialize(j+1);
                T[last].child[ch]=sz++;
            }
            last=T[last].child[ch];
        }
        T[last].matched.pb(i);
    }

    for(i=0;i<bacca;i++)
    {
        if(T[0].child[i])
        {
            Q.push(T[0].child[i]);
            T[T[0].child[i]].link=0;
        }
    }

    while(!Q.empty())
    {
        u=Q.front();Q.pop();

        for(i=0;i<bacca;i++)
        {
            if(T[u].child[i])
            {
                p=T[u].link;
                v=T[u].child[i];
                while(p!=0 && T[p].child[i]==0)
                      p=T[p].link;
                T[v].link=T[p].child[i];
                Q.push(v);
            }
            else
                T[u].child[i] = T[T[u].link].child[i];
        }
    }

   for(i=0;i<sz;i++) height[T[i].depth]++;//,cout<<"i : "<<i<<" dep : "<<T[i].depth<<endl;
   for(i=1;i<wsize;i++) height[i]+=height[i-1];
   for(i=0;i<sz;i++) top[--height[T[i].depth]] = i;
}

void Search()
{
    int i,j,len,cur,p,v;
    char ch;

    cur=0;
    len=strlen(str);
    mem(freq,0);

    for(i=0;i<len;i++)
    {
        ch=str[i]-'a';
        if(T[cur].child[ch]==0)
        {
            p=T[cur].link;
            while(p>0 && T[p].child[ch]==0)
                p=T[p].link;
            cur=T[p].child[ch];
        }
        else
            cur=T[cur].child[ch];
        freq[cur]++;
    }

    for(i=sz-1;i>=0;i--)
    {
        v=top[i];
        freq[T[v].link]+=freq[v];
    }

    for(i=1;i<sz;i++)
    {
        if(SZ(T[i].matched))
        {
            for(j=0;j<SZ(T[i].matched);j++)
                ans[T[i].matched[j]]=freq[i];
        }
    }
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    //ios_base::sync_with_stdio(false);

//    Read;
//    Write;
    int test,Case=1,i,j,k,minv,u,v,id_no,N;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        scanf(" %s",str);

        for(i=1;i<=N;i++)
            scanf(" %s",words[i]);

        Build_Aho_Corasick(N);

        Search();
        printf("Case %d:\n",Case++);
        for(i=1;i<=N;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
