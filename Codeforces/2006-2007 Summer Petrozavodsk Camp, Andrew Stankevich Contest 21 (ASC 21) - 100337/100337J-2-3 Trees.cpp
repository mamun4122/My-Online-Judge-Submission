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

#ifdef mamunSobPar
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
int t,n,m;
int dp[5004];
int two[5004];
int three[5004];
int ncr[5004][2504];
int mod;

int call(int n)
{
    if(n==1) return 1;

    int &ret = dp[n];
    if(ret!=-1) return ret;

    ll res = 0;
    FOR(i,0,5000)
    {
        if(two[i] > n) break;

//        int tin = n - two[i];
//        debug(i, n, two[i], n-two[i], binary_search(three, three+5001,n-two[i]))

        if(binary_search(three, three+5001,n-two[i])==true)
        {
            int dui = two[i] / 2;
            int tin = (n - two[i]) / 3;
            int tot = dui + tin;

            ll now = ncr[tot][min(dui,tot-dui)];
            debug(tot,dui, now);

            res += now * (call(dui + tin)%mod);
            res %= mod;
        }
    }

    ret = res;
    return ret;
}

int main()
{
    ///check for 0 or -1 if input not specified
    /// For printing double use %f
//#ifdef mamunSobPare
    READ("twothree.in");
        WRITE("twothree.out");
//#endif // mamun

    debug(sizeof(int))
    two[0] = three[0] = 0;
    FOR(i,1,5000)
    {
        two[i] = two[i-1] + 2;
        three[i] = three[i-1] + 3;
    }
    int x;
    while(~getII(x, mod))
    {

        ncr[0][0] = 1;
        FOR(i,1,5000)
        {
            FOR(j,0,2500)
            {
                if(j > i) ncr[i][j] = 0;
                else if(j==i || j==0) ncr[i][j] = 1;
                else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];

                ncr[i][j] %= mod;
            }
        }

//        debug(ncr[6][0])


        SET(dp);
        printf("%d\n",call(x));
    }

    return 0;
}