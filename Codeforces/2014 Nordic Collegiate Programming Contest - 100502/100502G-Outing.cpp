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
#define     SZ(v) v.size()
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

#define NODE 1005
int totNode[NODE];
int fuck[NODE];
vector<int> rev[NODE];
struct SCC{
    int num[NODE], low[NODE], col[NODE], cycle[NODE], st[NODE];
    int tail, cnt, cc;
    vi adj[NODE];

    SCC():tail(0),cnt(0),cc(0) {}
    void clear () {
        cc += 3;
        CLR(totNode);
        FOR(i,0,NODE-1) adj[i].clear();
        FOR(i,0,NODE-1) rev[i].clear();
        tail = 0;
    }
    void tarjan ( int s ) {
//        debug(s)
        num[s] = low[s] = cnt++;
        col[s] = cc + 1;
        st[tail++] = s;
        FOR(i,0,SZ(adj[s])-1) {
            int t = adj[s][i];
            if ( col[t] <= cc ) {
                tarjan ( t );
                low[s]=min(low[s],low[t]);
            }
            /*Back edge*/
            else if (col[t]==cc+1)
                low[s]=min(low[s],low[t]);
        }
        if ( low[s] == num[s] ) {
            while ( 1 ) {
                int temp=st[tail-1];
                tail--;
                col[temp] = cc + 2;
                cycle[temp] = s;
                totNode[s]++;
                if ( s == temp ) break;
            }
        }
    }
    void shrink( int n ) {
        FOR(i,1,n){
            FOR(j,0,SZ(adj[i])-1){
                adj[i][j] = cycle[adj[i][j]]; ///Careful. This will create self-loop. Just ignore i->i edges when processing.
            }
        }
        FOR(i,1,n){
            if ( cycle[i] == i ) continue;
            int u = cycle[i];
            FOR(j,0,SZ(adj[i])-1){
                int v = adj[i][j];
                adj[u].PB ( v );
            }
            adj[i].clear();
        }
        FOR(i,1,n){ ///Not always necessary
            sort ( ALL(adj[i]) );
            UNIQUE(adj[i]);
        }
    }

    void findSCC( int n ) {
        FOR(i,1,n) {
            if ( col[i] <= cc ) {
                tarjan ( i );
            }
        }
    }
}graph;

int dp[1005][1005];
int dp1[1005][1005];
int call(int pos,int src,int rem);
int fuck_me(int src, int rem)
{
    int &ret = dp1[src][rem];
    if(ret != -1)return ret;
    ret = 0;
    ret = call(0,src,rem);
    return ret;
}
int call(int pos,int src,int rem)
{
    if(pos == rev[src].size())
        return 0;
    int v = rev[src][pos];
    if(v == src)return call(pos+1,src,rem);
    int &ret = dp[v][rem];
    if(ret != -1)return ret;
//    debug(v,rem)
    ret = call(pos+1,src,rem);
    int lft = rem-totNode[v];
//    debug(v,lft)
    FOR(i,0,lft)
    {
        int ans = totNode[v] + fuck_me(v,i) + call(pos+1,src,lft-i);
        ret = max(ret,ans);
    }

    return ret;
}

void dfs(int src)
{
//    debug(src,totNode[src]);
    for(auto v: rev[src])
        if(v != src)
        dfs(v);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        graph.clear();
        rep(i,n)
        {
            int x;
            getI(x);
            graph.adj[i].PB(x);
        }
//        debug("");
        graph.findSCC(n);
//        debug("");
        graph.shrink(n);
//        debug("");
        CLR(fuck);
        rep(i,n)
        {
//            debug(i,totNode[i]);
                for(auto v: graph.adj[i])
                 {
//                     debug(i,v)
                     if(v != i)fuck[i] = 1;
                     rev[v].push_back(i);
                 }
        }
        int supersrc = n+1;
        rep(i,n)
            if(fuck[i] == 0 && totNode[i])
                rev[supersrc].push_back(i);
//        rep(i,n)if(fuck[i] == 0 && totNode[i])debug(i);
        SET(dp);
        SET(dp1);
        dfs(supersrc);
        int ans = fuck_me(supersrc,m);
        printf("%d\n",ans);
    }
    return 0;
}