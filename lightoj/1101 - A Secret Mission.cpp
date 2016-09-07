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
//    READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    getI(t);
    rep(cs,t)
    {
        e.clear();
        getII(n,m);
        int u,v,w;
        rep(i,m)
        {
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
//        int count=0;
        repI(i,e.size())
        {
            int x=e[i].u,y=e[i].v;
            int u=find(x);
            int v=find(y);
            if(u!=v)
            {
                int c=e[i].w;
                pr[u]=v;
//                count++;
                g[x].push_back(pii(y,c));
                g[y].push_back(pii(x,c));
//                if(count==n-1) break;
            }
        }
        dfs(-1,1,1);
        lca_init(n);
        int q,a,b;
        getI(q);
        printf("Case %d:\n",cs);
        while(q--)
        {
            getII(a,b);
            if(a==b)printf("0 0\n");
            else printf("%d\n",lca_query(n,a,b));
        }





    }





    return 0;
}

