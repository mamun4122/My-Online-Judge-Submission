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


long long base = 10007;
long long mod = 1000000007;
ll val[200005];//, pre[200005],rev[200005];
ll cumpre[200005],cumsuf[200005];
ll suru , sesh;
void get_hash(string str)
{
    suru = sesh = 0;
 long long hash_val =0;
 for(int i=0;str[i];i++)
 {
  hash_val = val[i] * (str[i]-'a');
  hash_val %= mod;
  suru += hash_val;
  suru %= mod;
  debug(i,suru)
  cumpre[i] = suru;
 }
 int sz = str.size();
 ROF(i,sz-1,0)
 {
        hash_val = val[sz - i -1] * (str[i] - 'a');
        hash_val %= mod;
        sesh += hash_val;
        sesh %= mod;
        debug(sz-i-1,sesh,hash_val)
        cumsuf[i] = sesh;
 }

}
void call()
{
    val[0] = 1;
    rep(i,200001)
    {
        val[i] = val[i-1]*base;
        val[i] %= mod;
    }
}
ll modula(ll num)
{
    if(num < 0)
        num = ((num%mod)+mod)%mod;
    return num;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    call();
    string s;
    while(cin >> s)
    {
//        s = "ab";
        ll gun = modularInverse(base, mod);
        int ans = -1;
        get_hash(s);
        debug(suru,sesh)
        int sz = s.size();
        repI(i,sz)
        {
            ll val1 = 0;
            if(i)val1 = cumpre[i-1];
            ll anthr = cumpre[sz-1]-cumpre[i];
            anthr = modula(anthr);
            anthr *= gun;
            anthr %= mod;
            val1 += anthr;
            val1 %= mod;
            debug(i,val1)

            ll val2 = 0;
            if(i!=sz)val2 = cumsuf[i+1];
            anthr = cumsuf[0] - cumsuf[i];
            anthr = modula(anthr);
            anthr *= gun;
            anthr %= mod;
            val2 += anthr;
            val2 %= mod;

            if(val1 == val2)
            {
                ans = i;
                break;
            }
        }
        if(ans == -1)puts("NO");
        else
        {
            puts("YES");
            printf("%d\n",ans+1);
        }
    }
    return 0;
}