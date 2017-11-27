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
#define MAX 100005
const int MOD = 1e9+7;
vector<int> adj[MAX];
int k,x;
ll dp[MAX][15][5];
ll dp1[MAX][15][5];
ll call(int src,int par,int rem,int cond);
ll fuck_me(int pos,int src,int par,int rem,int cond)
{
    if(rem < 0)return 0;
    if(pos == adj[src].size())return rem == 0;
    int v = adj[src][pos];
    if(v  == par)return fuck_me(pos+1, src, par, rem, cond);
    ll &ret = dp1[v][rem][cond];
    if(ret != -1)return ret;
    ret = 0;
    repI(i,rem+1)
    {
        ret += (call(v,src,i,cond) * fuck_me(pos+1, src, par, rem-i,cond))%MOD;
    }
    ret %= MOD;
    return ret;
}


ll call(int src,int par,int rem,int cond)
{
    ll &ret = dp[src][rem][cond];
    if(ret != -1)return ret;
    ret = 0;
    /// par is less than k
    if(cond == 0)
    {
        /// src e k er cheye choto bosailam
        ret += (fuck_me(0, src, par, rem, 0)*(k-1))%MOD;
        ret %= MOD;
        /// src e k bosailam
        ret += fuck_me(0, src, par, rem-1, 1);
        ret %= MOD;
        /// src e k er cheye boro bosailam
        ret += (fuck_me(0, src, par, rem, 2)*(m-k))%MOD;
        ret %= MOD;
    }
    /// par is equal to k
    else if(cond == 1)
    {
        /// sudu k er cheye choto bosaite parbo
        ret += (fuck_me(0, src, par, rem, 0)*(k-1))%MOD;
    }
    /// par is bigger than k
    else
    {
        /// par boro tai sudu choto or boro bosaite parbo
        ret += (fuck_me(0, src, par, rem, 0)*(k-1))%MOD;
        ret += (fuck_me(0, src, par, rem, 2)*(m-k))%MOD;
    }
    ret %= MOD;
    return ret;
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
        rep(i,n)adj[i].clear();
        SET(dp);
        SET(dp1);
        rep(i,n-1)
        {
            int a,b;getII(a,b);
            adj[a].PB(b);adj[b].PB(a);
        }
        getII(k,x);
//        debug(k,x)
        ll ans = 0;
        repI(i,x+1)
            ans += call(1,0,i,0),ans %= MOD;
        printf("%lld\n",ans);

    }

    return 0;
}