#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

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

struct Edge{
    int from,to,cap,flow,cost;
    Edge(int from, int to, int cap, int flow, int cost): from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

const int MAXN = 1604;

struct MCMF
{
    int n,m,s,t;
    vector < Edge > edges;
    vi G[MAXN];
    bool inq[MAXN];
    int d[MAXN], p[MAXN], a[MAXN];

    void init(int n)
    {
        this->n = n;
        edges.clear();
        FOR(i,0,n) G[i].clear();
    }
    void addEdge(int from, int to, int cap, int cost)
    {
        edges.PB( Edge(from, to, cap, 0, cost));
        edges.PB( Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].PB(m-2);
        G[to].PB(m-1);
    }

    bool spfa(int &flow, int &cost)
    {
        FOR(i,0,n-1) d[i] = INF, inq[i] = 0;

        queue <int> q;
        q.push(s);
        inq[s] = 1;d[s]=0;
        p[s]=0;
        a[s]=INF;

        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            inq[x] = 0;

            FOR(i,0,(int)G[x].size()-1)
            {
                Edge &e = edges[G[x][i]];
                if(e.cap > e.flow && d[e.to] > d[x] + e.cost)
                {
                    d[e.to] = d[x] + e.cost;
                    p[e.to] = G[x][i];
                    a[e.to] = min(a[x], e.cap - e.flow);
                    if(!inq[e.to]) inq[e.to] = 1, q.push(e.to);
                }
            }
        }

        if(d[t] == INF) return 0;
        flow += a[t];
        cost += d[t];
        int u = t;

        while(u!=s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return 1;
    }

    pii minCost(int s, int t)
    {
        this->s = s;
        this->t =t;
        int flow =0,cost = 0;
        while(spfa(flow,cost)) ;
        return MP(flow,cost);
    }
}mcmf;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n,m;
        cin >> n >> m;

        int a[n][m];
        CLR(a);
        vector < pii > src,dest;
        FOR(i,0,n-1)
        {
            string st;
            cin >> st;
            FOR(j,0,m-1)
            {
                if(st[j]=='#') a[i][j] = 1;
                else if(st[j]=='B')
                {
                    src.PB( MP(i,j) );
                }
                else if(st[j]=='X')
                {
                    dest.PB( MP(i,j) );
                }
            }
        }

        mcmf.init(n*m+10);
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                FOR(k,0,3)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x>=0 && y>=0 && x<n && y<m && a[x][y]==0)
                    {
                        int n1 = i*m + j;
                        int n2 = x*m + y;

                        mcmf.addEdge(n1, n2, 400, 1);
                    }
                }
            }
        }

        FOR(i,0,(int)src.size()-1)
        {
            int n1 = src[i].ff * m + src[i].ss;
            mcmf.addEdge(n*m+2, n1, 1, 0);
        }
        FOR(i,0,(int)dest.size()-1)
        {
            int n1 = dest[i].ff * m + dest[i].ss;
            mcmf.addEdge(n1, n*m+4, 1, 0);
        }

        pii ans = mcmf.minCost(n*m+2, n*m+4);
        printf("%d\n",ans.ss);
    }

    return 0;
}
