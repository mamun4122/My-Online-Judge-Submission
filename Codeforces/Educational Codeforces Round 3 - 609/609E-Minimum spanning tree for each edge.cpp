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


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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
#define mamun
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
#define MAXN 200005
struct edge
{
    int u,v,pos;
    ll w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
int pr[MAXN];
vector<edge>e;
int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
vector< pair<int,ll> > g[MAXN];
ll ans[MAXN];

///LCA HERE

int depth[MAXN];
int parent[MAXN][30];
int T[MAXN];
ll dist[MAXN][30];
void dfs(int from,int u,int dep)
{
    T[u]=from;
    depth[u]=dep;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i].ff;
        if(v==from) continue;
        dist[v][0]=g[u][i].ss;
        dfs(u,v,dep+1);
    }
}
void lca_init(int N)
{
    memset (parent,-1,sizeof(parent));
    int i, j;
    for (i = 1; i <= N; i++)
        parent[i][0] = T[i];
    //can be modified here by looping only to depth from dfs
    for (j = 1; 1 << j < N; j++)
        for (i = 1; i <= N; i++)
            if (parent[i][j - 1] != -1)
            {
                dist[i][j]=max(dist[i][j-1],dist[parent[i][j-1]][j-1]);
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
}
ll lca_query(int N, int p, int q) //N=নোড সংখ্যা
{
    int tmp, log, i;

    if (depth[p] < depth[q])swap(p,q);

    ll tmpans=0;
    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>depth[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (depth[p] - (1 << i) >= depth[q])
        {
            tmpans=max(tmpans,dist[p][i]);
            p = parent[p][i];
        }

    if (p == q)
        return tmpans;

    for (i = log; i >= 0; i--)
        if (parent[p][i] != -1 && parent[p][i] != parent[q][i])
        {
            tmpans=max(tmpans,dist[p][i]);
            tmpans=max(tmpans,dist[q][i]);
            p = parent[p][i];
            q = parent[q][i];
        }

    tmpans=max(tmpans,dist[p][0]);
    tmpans=max(tmpans,dist[q][0]);

    return tmpans;
}

///LCA END


int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    int n,m;
    getII(n,m);
    edge get;
    rep(i,m)
    {
        getII(get.u,get.v);
        getL(get.w);
        get.pos=i;
        e.push_back(get);

    }
    CLR(ans);
    ///mst here
    ll mst=0;
    sort(e.begin(),e.end());
    for(int i=1; i<=n; i++)pr[i]=i;

    int count=0;
    for(int i=0; i<(int)e.size(); i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            count++;
            mst+=e[i].w;
            ans[e[i].pos]=1;
            g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
            if(count==n-1) break;
        }
    }
    dfs(-1,1,1);
    lca_init(n);
    repI(i,m)
    {
        if(ans[e[i].pos])ans[e[i].pos]=mst;
        else
        {
            ans[e[i].pos]=mst-lca_query(n,e[i].u,e[i].v);
            ans[e[i].pos]+=e[i].w;
        }
    }
    rep(i,m)printf("%lld\n",ans[i]);


    return 0;

}