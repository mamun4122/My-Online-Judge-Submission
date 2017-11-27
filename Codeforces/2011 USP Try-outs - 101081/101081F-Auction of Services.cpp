#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

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
#define MAXN 100005
struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
int pr[MAXN];
vector<edge>e;
vector< pii > g[MAXN];
int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
int depth[MAXN];
int parent[MAXN][30];
int T[MAXN],D[MAXN]; //
int dist[MAXN][30];
void dfs(int from,int u,int dep)
{
//    T[u]=from;
    depth[u]=dep;
    repI(i,g[u].size())
    {
        int v=g[u][i].ff;
        if(v==from) continue;
        T[v]=u;
        D[v]=g[u][i].ss;
        dfs(u,v,dep+1);
    }
}
void lca_init(int N)
{
    SET(parent);
    int i, j;
    for (i = 1; i <= N; i++)
    {
        parent[i][0] = T[i];
        dist[i][0]=D[i];
    }
    //can be modified here by looping only to depth from dfs
    for (j = 1; 1 << j < N; j++)
        for (i = 1; i <= N; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                dist[i][j]=max(dist[i][j-1],dist[parent[i][j-1]][j-1]);
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
}
int lca_query(int N, int p, int q)
{
    int  log, i;

    if (depth[p] < depth[q])swap(p,q);

    for (log = 1; 1 << log <= depth[p]; log++);
    log--;
    int ans=0;
    for (i = log; i >= 0; i--)
        if (depth[p] - (1 << i) >= depth[q])
        {
            ans=max(ans,dist[p][i]);
            p = parent[p][i];
        }

    if (p == q)
        return ans;

    for (i = log; i >= 0; i--)
        if (parent[p][i] != -1 && parent[p][i] != parent[q][i])
        {
            ans=max(ans,dist[p][i]);
            ans=max(ans,dist[q][i]);

            p = parent[p][i];
            q = parent[q][i];
        }
    ans=max(D[p],ans);
    ans=max(D[q],ans);

    return ans;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        e.clear();
        rep(i,m)
        {
            int u,v,w;
            getIII(u,v,w);
            e.push_back(edge(u,v,w));
        }
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
            pr[i]=i;
        }

        ///mst here
        sort(e.begin(),e.end());
        repI(i,e.size())
        {
            int x=e[i].u,y=e[i].v;
            int u=find(x);
            int v=find(y);
            if(u!=v)
            {
                int c=e[i].w;
                pr[u]=v;
                g[x].push_back(pii(y,c));
                g[y].push_back(pii(x,c));
            }
        }
        dfs(-1,1,1);
        lca_init(n);
        int q,a,b;
        getI(q);
        while(q--)
        {
            getII(a,b);
            printf("%d\n",lca_query(n,a,b));
        }
    }

    return 0;
}