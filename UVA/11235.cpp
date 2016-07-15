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
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)


#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double


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
#define mam
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
#define mx 100001
int arr[mx];

struct node
{
    int lval,rval,lcnt,rcnt,ans;
    int tlval,trval,tlcnt,trcnt,tans;
} tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        //debug(node)
        tree[node].lval=tree[node].rval=arr[b];
        tree[node].lcnt=tree[node].rcnt=tree[node].ans=1;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);

    tree[node].lval=tree[Left].lval;
    tree[node].rval=tree[Right].rval;

    tree[node].lcnt=tree[Left].lcnt;
    tree[node].rcnt=tree[Right].rcnt;

    if(tree[Left].lval==tree[Right].lval)
    {
        tree[node].lcnt+=tree[Right].lcnt;
    }
    if(tree[Left].rval==tree[Right].rval)
    {
        tree[node].rcnt+=tree[Left].rcnt;
    }

    tree[node].ans=max(tree[Left].ans,tree[Right].ans);

    if(tree[Left].rval==tree[Right].lval)
        tree[node].ans=max(tree[node].ans,tree[Left].rcnt+tree[Right].lcnt);
    if(node==1)debug(tree[node].ans)
    tree[node].ans=max(tree[node].ans,max(tree[node].lcnt,tree[node].rcnt));
    debug(node,tree[node].lval,tree[node].lcnt,tree[node].rval,tree[node].rcnt,tree[node].ans)
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)	return 0;
    if (b >= i && e <= j)
    {
        tree[node].tans=tree[node].ans;
        tree[node].tlcnt=tree[node].lcnt;
        tree[node].trcnt=tree[node].rcnt;
        tree[node].tlval=tree[node].lval;
        tree[node].trval=tree[node].rval;
        return tree[node].tans;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    if(p1==0)
    {
        tree[node].tans=tree[Right].tans;
        tree[node].tlcnt=tree[Right].tlcnt;
        tree[node].trcnt=tree[Right].trcnt;
        tree[node].tlval=tree[Right].tlval;
        tree[node].trval=tree[Right].trval;
    }
    else if(p2==0)
    {
        tree[node].tans=tree[Left].tans;
        tree[node].tlcnt=tree[Left].tlcnt;
        tree[node].trcnt=tree[Left].trcnt;
        tree[node].tlval=tree[Left].tlval;
        tree[node].trval=tree[Left].trval;

    }
    else
    {
        tree[node].tlval=tree[Left].tlval;
        tree[node].trval=tree[Right].trval;

        tree[node].tlcnt=tree[Left].tlcnt;
        tree[node].trcnt=tree[Right].trcnt;
        if(tree[Left].tlval==tree[Right].tlval)
        {
            tree[node].tlcnt+=tree[Right].tlcnt;
        }
        if(tree[Left].trval==tree[Right].trval)
        {
            tree[node].trcnt+=tree[Left].trcnt;
        }

        tree[node].tans=max(tree[Left].tans,tree[Right].tans);

        if(tree[Left].trval==tree[Right].tlval)
            tree[node].tans=max(tree[node].tans,tree[Left].trcnt+tree[Right].tlcnt);

        tree[node].tans=max(tree[node].tans,max(tree[node].tlcnt,tree[node].trcnt));
        //if(node==2)debug(tree[node].tans,tree[node].tlval)
    }

    return max(tree[node].tans,max(p1,p2));
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    while(~getI(n)&&n)
    {
        int t;
        getI(t);
        for(int i=1; i<=n; i++)
            getI(arr[i]);
        init(1,1,n);
        //debug(tree[3].ans,tree[3].lval,tree[3].lcnt,tree[3].rval,tree[3].rcnt);
        //debug(tree[2].ans,tree[2].lval,tree[2].lcnt,tree[2].rval,tree[2].rcnt);
//        for(int i=1;i<=25;i++)
//            printf("%d ",tree[i].lval);
        int x,y,ans;
        while(t--)
        {
            getII(x,y);
            ans=query(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }

    return 0;
}
