#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 850350000;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
int t,n,m;

#define MAX 10005
int arr[MAX];

struct info
{
    int pre,suf,sum,tot;
} tree[MAX*4],demo,vua;
info call(info a,info b)
{
    info tmp;

    tmp.sum=max(a.sum,b.sum);
    tmp.sum=max(tmp.sum,a.suf+b.pre);
    tmp.sum=max(tmp.sum,a.tot+b.pre);
    tmp.sum=max(tmp.sum,a.suf+b.tot);
    tmp.sum=max(tmp.sum,a.tot+b.tot);

    tmp.tot=a.tot+b.tot;

    tmp.pre=a.pre;tmp.suf=b.suf;

    tmp.pre=max(tmp.pre,a.tot+b.pre);
    tmp.pre=max(tmp.pre,a.tot+b.tot);

    tmp.suf=max(tmp.suf,a.suf+b.tot);
    tmp.suf=max(tmp.suf,a.tot+b.tot);

    return tmp;

}
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].suf=tree[node].pre=arr[b];
        tree[node].tot=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
}
info query(int node,int b,int e,int i,int j)
{
//    if (i > e || j < b)	return demo;
    if(i>j)return vua;
    if (b >= i && e <= j) return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    if(j<=mid)return query(Left,b,mid,i,j);
    else if(i>mid)return query(Right,mid+1,e,i,j);
    info p1=query(Left,b,mid,i,j);
    info p2=query(Right,mid+1,e,i,j);
    return call(p1,p2);
}

///tiny-code.blogspot.com/2013/08/spoj-2916can-you-answer-these-queries-v.html

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    demo.suf=demo.pre=demo.sum=-INF;
    demo.tot=0;
    vua.suf=vua.pre=vua.sum=0;
    vua.tot=0;
    getI(t);
    rep(cs,t)
    {
        getI(n);
        rep(i,n)getI(arr[i]);
        init(1,1,n);
//        debug(tree[1].sum)
        getI(m);
        rep(i,m)
        {
            int x1,y1,x2,y2;
            getII(x1,y1);
            getII(x2,y2);
//            debug("")
            int ans=0;
            if(y1<x2)
            {
                ans+=query(1,1,n,x1,y1).suf;
                ans+=query(1,1,n,x2,y2).pre;
//                debug("")
                if(y1+1<=x2-1)
                ans+=query(1,1,n,y1+1,x2-1).tot;
            }
            else
            {

                ans=query(1,1,n,x1,x2-1).suf+query(1,1,n,x2,y2).pre;
                ans=max(query(1,1,n,x1,y1).suf+query(1,1,n,y1+1,y2).pre,ans);
                ans=max(ans,query(1,1,n,x2,y1).sum);
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}


