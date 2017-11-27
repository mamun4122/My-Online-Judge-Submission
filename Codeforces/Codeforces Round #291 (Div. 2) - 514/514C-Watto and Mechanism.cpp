#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld   long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}



//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************

int flag=0;
struct node
{
    bool endmark;
    node *next[3];
    node()
    {
        endmark=0;
        for(int i=0; i<3; i++)
            next[i]=NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;

}
char a[600005];
bool search(node *curr,int pos,int len,int flag)
{
    if(pos==len)return flag==1&&curr->endmark;
    bool ret=false;
    int id=a[pos]-'a';
    for(int i=0; i<3; i++)
    {
        if(curr->next[i]==NULL)continue;
        if(i!=id&&flag)continue;
        if(i==id)ret|=search(curr->next[i],pos+1,len,flag);
        else if(flag==0)ret|=search(curr->next[i],pos+1,len,1);
        if(ret)return ret;
    }
    return ret;   // returns 1 or 0
}


void del(node *cur)    // send root here
{
    for(int i=0; i<3; i++)
        if(cur->next[i])
            del(cur->next[i]) ;


    delete(cur) ;
}
int main()
{

//    READ("in.txt");
    //WRITE("out.txt");
    //node *root;
    root=new node();
    int n,m;
    getII(n,m);
    //debug(n,m);
    getchar();
    for(int i=1; i<=n; i++)
    {
        gets(a);
        //scanf("%s",a);
        // debug(a);
        insert(a,strlen(a));
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%s",a);
//        debug(a);
        int len=strlen(a);
        if(search(root,0,len,0))
            puts("YES");
        else
            puts("NO");
    }

    del(root);
    return 0;
}