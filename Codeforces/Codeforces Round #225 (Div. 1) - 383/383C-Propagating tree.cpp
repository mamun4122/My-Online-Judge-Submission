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
#define mx 200001
int arr[mx];
vector<int> adj[mx];
int strt[mx],fin[mx],org[mx],lvl[mx];
int cur;

void dfs(int src,int prev,int l)
{
    strt[src]=++cur;
    arr[cur]=org[src];
    lvl[cur]=l%2;
    repI(i,adj[src].size())
    {
        int v=adj[src][i];
        if(v!=prev)dfs(v,src,l+1);
    }
    fin[src]=cur;
}

int tree[mx*4][4];

void propagate(int node,int b,int e)
{
    if(b==e)
    {
        arr[b]+=tree[node][lvl[b]];
        tree[node][0]=tree[node][1]=0;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    tree[Left][0]+=tree[node][0];
    tree[Left][1]+=tree[node][1];
    tree[Right][0]+=tree[node][0];
    tree[Right][1]+=tree[node][1];
    tree[node][0]=0;
    tree[node][1]=0;
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)return 0;
    propagate(node,b,e);
    if(b>=i && e<=j)
    {
        ///do something
        return arr[b];
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return  p1+p2;

}

void update(int node,int b,int e,int i,int j,int val,int l)
{
    if (i > e || j < b) return;
    propagate(node,b,e);
    if (b >= i && e <= j)
    {
        ///do something
        tree[node][l]+=val;
        tree[node][1-l]-=val;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,val,l);
    update(Right,mid+1,e,i,j,val,l);
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
        cur=0;
        rep(i,n)adj[i].clear();
        rep(i,n)getI(org[i]);
        CLR(arr);
        rep(i,n-1)
        {
            int a,b;
            getII(a,b);
            adj[a].PB(b);
            adj[b].PB(a);
        }
        dfs(1,-1,0);
        rep(i,m)
        {
            int x,y,type;
            getII(type,x);
            if(type==1)
            {
                getI(y);
                update(1,1,n,strt[x],fin[x],y,lvl[strt[x]]);
            }
            else
            {
                int ans=query(1,1,n,strt[x],strt[x]);
                printf("%d\n",ans);
            }
        }
    }


    return 0;
}