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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
#define mx 50005
int depth[mx],sparse[mx][22],parent[mx];
int arr[mx],tree[mx*4];
vector<pii>adj[mx];

void dfs(int from,int u,int dep,int cost)
{
    parent[u]=from;
    depth[u]=dep;
    arr[u]=cost;
    for(int i=0; i<(int)adj[u].size(); i++)
    {
        int v=adj[u][i].ff;
        if(v==from) continue;
        dfs(u,v,dep+1,cost+adj[u][i].ss);
    }
}

int lca_query(int N, int p, int q) //N=???? ??????
{
    int tmp, log, i;

    if (depth[p] < depth[q])swap(p,q);

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>depth[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (depth[p] - (1 << i) >= depth[q])
            p = sparse[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i], q = sparse[q][i];

    return parent[p];
}

void lca_init(int N)
{
    SET(sparse);
    for (int i = 0; i < N; i++)sparse[i][0] = parent[i];
    for (int j = 1; (1 << j) < N; j++)
        for (int i = 0; i < N; i++)
            if (sparse[i][j - 1] != -1)
            {
                int tmp=sparse[i][j - 1];
                sparse[i][j] = sparse[tmp][j - 1];
            }
}
///segment tree
void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node];
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	return p1+p2;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        repI(i,n)adj[i].clear();
        rep(i,n-1)
        {
            int u,v,w;
            getIII(u,v,w);
            adj[u].PB(pii(v,w));
            adj[v].PB(pii(u,w));
        }
        dfs(0,0,0,0);
        lca_init(n);
        init(1,0,n-1);
        getI(m);
        rep(i,m)
        {
            int x,y;
            getII(x,y);
            int ans=query(1,0,n-1,x,x)+query(1,0,n-1,y,y);
            int lc=lca_query(n,x,y);
            ans-=2*query(1,0,n-1,lc,lc);
//            debug(lc)
            printf("%d\n",ans);
        }
    }


    return 0;
}
/**
7
0 2 1
1 2 2
2 3 4
3 4 8
4 5 16
4 6 32
5
0 1
0 3
2 5
1 6
1 5
Answer:
3
5
28
46
30

**/

