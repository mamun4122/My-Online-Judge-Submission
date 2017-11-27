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


#define M 5000002
bool marked[M];
vector <int> primes;

bool isPrime(int n) {
  if (n < 2) return 1;
  if (n == 2) return 0;
  if (n % 2 == 0) return 1;
  return marked[n];
}

void sieve(int n) {
 primes.push_back(2);
 for (ll i = 3; i * i <= n; i += 2) {
  if (marked[i] == 0) {
   primes.push_back(i);
   for (ll j = i * i; j <= n; j += i + i) {
    marked[j] = 1;
  }
    }
  }
}

const int MX = 5000002;
ll dp[5000004];
ll mod = 1e9+7;

void gen()
{
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    FOR(i,3,MX)
    {
        dp[i] = (ll)i*(i-1);
        dp[i] /= 2;
//        dp[i] %= mod;
        if(!isPrime(i))
            continue;
        int sq = sqrt(i);
        for(int j = 0; primes[j] <= sq;j++)
        {
            if(i % primes[j] == 0)
            {
                ll k1 = i/primes[j];
                ll k2 = primes[j];
                dp[i] = min(dp[i], k1*((k2 * (k2-1))/2) + dp[k1]);
                dp[i] = min(dp[i], k2*(k1*(k1-1)/2) + dp[k2]);
//                dp[i] %= mod;
                break;
            }
        }
    }
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(M-1);
    gen();
    int l,r;
    while(~getIII(t,l,r))
    {
        ll res = 0;
        ll tt = 1;
        FOR(i,l,r)
        {
            res += (tt * (dp[i]%mod) )%mod;
            res %= mod;
//            debug(i,tt,dp[i])
            tt *= (ll)t;
            tt %= mod;
        }
        printf("%lld\n",res%mod);
    }

    return 0;
}