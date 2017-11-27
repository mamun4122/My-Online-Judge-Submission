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
ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
ll modularInverse(ll a, ll m) {
    return bigmod(a, m-2, m);
}
ll MOD(ll num, ll m)
{
    if(num < 0)
        num = num % m + m;
    return num % m;
}
string s;
vector<int> v0,v1;
const ll mod = 1e9+7;
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
        v0.clear();v1.clear();
        ll n;
        getL(n);
        cin >> s;
        int zero = 0, one = 0, two = 0;
        repI(i,s.size())
        {
            if(s[i] == '0')zero++,v0.push_back(i+1);
            else if(s[i] == '1')one++,v1.push_back(i+1);
            else two++;
        }
        ll fck = 1;
        repI(i,v1.size())fck = lcm(fck,(ll)v1[i]);
        /// tot num
        /// we need  to find (10^n-1) / fck
        /// to do that we need to do ((10^n-1)-((10^n-1)%fck)) / fck
        /// otherwise fraction value will cause problem
        ll ans = bigmod(10, n, mod);
        ans = MOD(ans-1, mod);

        ll rem = bigmod(10, n, fck);
        rem = MOD(rem-1, fck);
        ans = MOD(ans-rem, mod);

//        debug(ans)
        ll fckInv = modularInverse(fck, mod);
        ans = (ans * fckInv)%mod;

        /// For 0 ai one jog hbe
        ans = MOD(ans + 1, mod);
//        debug(fckInv*ans)
//        debug(ans)
//        debug(zero)
        ll biog = 0;
        /// biog dibo j gula die vag jawa uchit na
        for(int mask = 1; mask < (1<<zero); mask++)
        {
            int totBit = POPCOUNT(mask);
            /// jog gula k consider korte hbe hisaber somoy
            ll lc = fck;

            repI(i,zero)if(bitCheck(mask,i))lc = lcm(lc,(ll)v0[i]);

            /// (tot/lc) ta number jog biog korte hbe
            ll tot = bigmod(10,n,mod);
            tot = MOD(tot-1,mod);

            ll rem = bigmod(10, n, lc);
            rem = MOD(rem-1, lc);
            tot = MOD(tot-rem, mod);

            ll modInv = modularInverse(lc, mod);

            ll  res  = (tot * modInv) % mod;
            res = MOD(res + 1, mod);

            if(totBit % 2) biog += res;
            else biog -= res;

            biog = MOD(biog, mod);

//            debug(lc,res,biog, totBit);
        }
//        debug(biog)
        ans = MOD(ans - biog, mod);
//        ans = (ans + biog) % mod;
        printf("%lld\n",ans);

    }

    return 0;
}