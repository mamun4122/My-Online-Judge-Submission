#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
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
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << ": " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << ": " << arg1 << " | ";
        __f(comma+1, args...);
    }
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define trace(...)
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

ll adj[504][504];
//int vis[504][504];

int dxx[] = {-1,0,1,1,1,0,-1,-1};
int dyy[] = {1,1,1,0,-1,-1,-1,0};
//
//int dfs(int x, int y, int mini)
//{
//    vis[x][y] = 1;
//    int ret = max(mini, adj[x][y]);
//
//    priority_queue < pair < int, pii > > pq;
//    FOR(i,0,7)
//    {
//        int X = x + dx[i];
//        int Y = y + dy[i];
//
//        if(X>=0 && Y>=0 && X<n && Y<m && adj[X][Y] < 0 && vis[X][Y]==0)
//        {
//            pq.push( MP( - adj[X][Y], MP(X,Y)));
////            ret += dfs(X,Y, max(mini,adj[x][y]));
//        }
//    }
//
//    while(!pq.empty())
//    {
//        pair < int, pii > p = pq.top();
//        pq.pop();
//        p.ff *= -1;
//
//        debug(p.ff, x,y)
//        if(vis[p.ss.ff][p.ss.ss]==0) ret += dfs(p.ss.ff, p.ss.ss, max(mini, p.ff));
//    }
//    return ret;
//}


int vis[504][504];
int tt;
ll dist[504][504];

int dj(int x, int y, int dx, int dy)
{
    debug("SADasdas")

CLR(vis);
    vis[x][y] = 1;
    priority_queue < pair < int, pii > > pq;
    pq.push( MP(adj[x][y], MP(x,y) ) );
    dist[x][y] = adj[x][y];

    while( !pq.empty() )
    {
        debug(pq.size())
        pair < ll, pii > p = pq.top();
        pq.pop();

        int ux = p.ss.ff;
        int uy = p.ss.ss;
//        debug("dfds", ux, uy, p.ff)
//        if(ux==dx && uy==dy) return p.ff;

        FOR(i, 0, 7)
        {
            int vx = ux + dxx[i];
            int vy = uy + dyy[i];


            if(vx >=0 && vy >= 0 && vx < n && vy < m && adj[vx][vy] > 0)
            {
                if(vis[vx][vy]==0)
                {
                    vis[vx][vy] = 1;
                    dist[vx][vy] = min(p.ff, (ll)adj[vx][vy]);
                    pq.push( MP(dist[vx][vy], MP(vx,vy)));
                }
                else if(dist[vx][vy] < min(p.ff, (ll)adj[vx][vy]))
                {
                    dist[vx][vy] = min(p.ff, (ll)adj[vx][vy]);
                    pq.push( MP(dist[vx][vy], MP(vx,vy)));
                }
            }
        }
    }

    return 0;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("inE.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    CLR(vis);
    while(~getII(n,m))
    {
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                getL(adj[i][j]);
                adj[i][j] *= -1;
            }
        }
        int sx,sy;
        getII(sx,sy);

        sx--,sy--;

        dj(sx,sy, n+1, m+1);


        tt=1;
        ll ans = 0;
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                debug(i, j, dist[i][j])
                if(adj[i][j] > 0) ans += dist[i][j];
            }
        }

        tt = 0;
//        FOR(i,0,n-1)
//        {
//            FOR(j,0,m-1)
//            {
//                tt++;
//                debug(i, j, adj[i][j])
//                if(adj[i][j] > 0) ans += dj(sx,sy, i, j);
//                debug(ans)
//            }
//        }
//        int ans = abs(dfs(sx,sy,adj[sx][sy]));

        printf("%lld\n",ans);
    }


    return 0;
}