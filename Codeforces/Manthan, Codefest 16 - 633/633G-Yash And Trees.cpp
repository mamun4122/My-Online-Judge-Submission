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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
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
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

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

#define mx 100005
vector<int> adj[mx];
int arr[mx];

const int M = 1005;
bitset<M> all,primes,res;
inline void apply(bitset<M> &b, int sh)
{
    b = ((b << sh) & all) | (b >> (m - sh));
}
struct info
{
    bitset<M> sum;
    int prop;
} tree[mx*4];

info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.sum=a.sum|b.sum;
    tmp.prop=0;
    return tmp;
}
void init(int node,int b,int e)
{
    if(b==e)
    {
        ///do something
        tree[node].sum=bitset<M>();
        tree[node].sum.set(arr[b]);
        tree[node].prop=0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
}
void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop=0;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ///update propagation
    tree[Left].prop+=tree[node].prop;
    tree[Left].prop%=m;
    apply(tree[Left].sum,tree[node].prop);
    tree[Right].prop+=tree[node].prop;
    tree[Right].prop%=m;
    apply(tree[Right].sum,tree[node].prop);
    tree[node].prop=0;
    ///update tree[left]
    ///update tree[right]

}
void query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)return;
    if(tree[node].prop)propagate(node,b,e);
    if(b>=i && e<=j)
    {
        ///do something
        res|=tree[node].sum;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    query(Left,b,mid,i,j);
    query(Right,mid+1,e,i,j);
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(tree[node].prop)propagate(node,b,e);
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        ///do something
        apply(tree[node].sum,val);
        tree[node].prop+=val;
        tree[node].prop%=m;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,val);
    update(Right,mid+1,e,i,j,val);
    tree[node]=call(tree[Left],tree[Right]);
}

int org[mx],strt[mx],fin[mx],tme;
void dfs(int src,int prev)
{
    strt[src]=++tme;
    arr[tme]=org[src];
    repI(i,adj[src].size())
    {
        int v=adj[src][i];
        if(v==prev)continue;
        dfs(v,src);
    }
    fin[src]=tme;
}
void findprime()
{
    primes.reset();
    for (int i = 2; i < m; i++)
    {
        bool prime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.set(i);
        }
    }
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        tme=0;
        rep(i,n)
        {
            adj[i].clear();
            getI(org[i]);
            org[i]%=m;
        }
        rep(i,n-1)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }
        dfs(1,-1);
        findprime();
        init(1,1,n);
        all.reset();
        repI(i,m)all.set(i);
        int q;
        getI(q);
        while(q--)
        {
            int type,x,y;
            getII(type,x);
            if(type==1)
            {
                getI(y);
                y%=m;
                if(y==0)continue;
                update(1,1,n,strt[x],fin[x],y);
            }
            else
            {
                res.reset();
                query(1,1,n,strt[x],fin[x]);
                int ans=(res & primes).count();
                printf("%d\n",ans);
            }
        }
    }


    return 0;
}