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
#define    pii   pair< ll, int >
#define    ff   first
#define    ss   second
#define    ll  long long
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
ll adj[2005][2005];
ll dist[2005][2005];
ll tmp[2005];
ll s;
vector<pii> weight[2005];
vector<int> v[105];
ll tmpdist[2005];

void gen()
{
    CLR(adj);
    rep(i,n)rep(j,n)if(i != j)
    {
        dist[i][j] = s % 1000;
        weight[i].PB(pii((int)dist[i][j], j));
        s = (s * 16807) % 2147483647;
    }
    rep(i,n)sort(ALL(weight[i]));
}
int vis[2005];
void solve1()
{
    rep(k,n)
        rep(i,n)
            rep(j,n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void solve2(int src)
{
    rep(i,n)
    {
        tmpdist[i] = dist[src][i];
        if(tmpdist[i] <= 100)
            v[tmpdist[i]].PB(i);
    }
    repI(i,101)
    {
        while(!v[i].empty())
        {
            int cur = v[i].back();
            v[i].pop_back();
            if(tmpdist[cur] < i)continue;
            repI(j,weight[cur].size())
            {
                int to = weight[cur][j].ss;
                int cost = weight[cur][j].ff;
                if(i+cost > 100)break;
                if(i+cost < tmpdist[to]){
                    tmpdist[to] = i + cost;
                    v[i+cost].PB(to);
                }
            }
        }
    }

    rep(i,n)
        dist[src][i] = tmpdist[i];
}
void solve()
{
    if(n <= 200)
        solve1();
    else
        rep(i,n)
            solve2(i);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    READ("floyd.in");
    WRITE("floyd.out");
    while(~getI(n))
    {
        rep(i,n)weight[i].clear();
        getL(s);
        gen();
        solve();
        ll ans = 0;
        rep(i,n)
            rep(j,n)
                ans = (ans * 16807 + dist[i][j]) % 2147483647;
        printf("%lld\n",ans);
    }
    return 0;
}