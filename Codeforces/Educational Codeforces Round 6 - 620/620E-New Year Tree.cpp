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
#include <ctime>
using namespace std;

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
int t,n,m;
#define mx 400005

int arr[mx];
bool mark[mx];
int in[mx],out[mx],org[mx];
vector<int>adj[mx];

struct info{
    int tot;
    ll mask;
    int prop;
    info()
    {
        prop=0;
        tot=0;
        mask=0;
    }
}tree[mx*3];
info dummy;


info gett(info a,info b)
{
    info x;
    x.mask=a.mask|b.mask;
    x.tot=__builtin_popcountll(x.mask);
    return x;
}

void init(int node,int b,int e)
{
 if(b==e)
 {
  tree[node].mask=1LL << arr[org[b]];
  tree[node].tot=__builtin_popcountll(tree[node].mask);
//     debug(b,arr[org[b]],tree[node].tot)
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node]=gett(tree[Left],tree[Right]);
}
void propagate(int node,int b,int e)
{
    int Left=node*2;
 int Right=node*2+1;
 tree[Left]=tree[node];
 tree[Right]=tree[node];
 tree[node].prop=0;
}
info query(int node,int b,int e,int i,int j)
{
 if (i > e || j < b) return dummy;
 if (b >= i && e <= j)
    {
//        debug(b,e,tree[node].tot)
        return tree[node];
    }
    if(tree[node].prop)propagate(node,b,e);
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 info p1=query(Left,b,mid,i,j);
 info p2=query(Right,mid+1,e,i,j);
 return gett(p1,p2);
}
void update(int node,int b,int e,int i,int j,int newvalue)
{
 if (i > e || j < b) return;
 if (i > e || j < b) return;
 if (b >= i && e <= j) {
  tree[node]=dummy;
  tree[node].prop=1;
  tree[node].mask=1LL << newvalue;
  tree[node].tot=1;
  return;
 }
    if(tree[node].prop)propagate(node,b,e);
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 update(Left,b,mid,i,j,newvalue);
 update(Right,mid+1,e,i,j,newvalue);
 tree[node]=gett(tree[Left],tree[Right]);
}
int tme=1;
void dfs(int src)
{
    in[src]=tme;
    org[tme]=src;
    mark[src]=1;
    int sz=adj[src].size();
    repI(i,sz)
    {
        if(!mark[adj[src][i]])
        {
            tme++;
            dfs(adj[src][i]);
        }
    }
    out[src]=tme;
}
int main()
{
// READ("in.txt");
    //WRITE("out.txt");
    getII(n,m);
    rep(i,n)getI(arr[i]);
    int a,b;
    rep(i,n-1)
    {
        getII(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    CLR(mark);
    rep(i,n)
    {
        if(!mark[i])dfs(i);
    }
    int c;
    init(1,1,n);
//    debug(getmask(dummy.mask))
//    rep(i,n)debug(i,in[i],arr[org[in[i]]],query(1,1,n,in[i],out[i]).tot)
    rep(i,m)
    {
        getII(a,b);
        if(a==1)
        {
            getI(c);
//            debug(in[b],c)
            update(1,1,n,in[b],out[b],c);
        }
        else
        {
//            debug(in[b],out[b])
            printf("%d\n",query(1,1,n,in[b],out[b]).tot);
        }
    }

 return 0;
}