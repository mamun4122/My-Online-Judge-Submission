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
#define    pii   pair< ll, ll >
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

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t;//,n,m;
ll n,m;


#define int64 ll
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
int64 Pow(int64  b,int64  p)
{
    int64  ret = 1;
    while(p)
    {
        if(p&1) ret *= b ;
        p >>= (1LL), b *= b ;
    }
    return ret ;
}

pair<int64,pair<int64,int64 > > eea(int64 a, int64 b)
{
    int64 gcd,x=0,y=1;
    int64 u=1, v=0, m, n, q, r;
    gcd = b;
    while (a!=0)
    {
        q=gcd/a;
        r=gcd%a;
        m=x-u*q;
        n=y-v*q;
        gcd=a;
        a=r;
        x=u;
        y=v;
        u=m;
        v=n;
    }
    return make_pair(gcd,make_pair(x,y));
}

int64 BigMod(int64 B,int64 P,int64 M)
{
    int64 R=1;    //compute b^p%m
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (int64)R;
}
int64 modInverse_prime(int64 B,int64 P)
{
    return BigMod(B,P-1,P);
}
int64 modInverse_relativePrime(int64 B,int64 P)
{
    return eea(B,P).second.first;
}
int64 mod;
int64 fact[1000005];
vector<pii >primeDivisors;
vector<int64 >L;
vector<int64>N ;
vector<int64>R ;
vector<int64>M ;
vector<int64>N_js ;
vector<int64>M_js ;
vector<int64>R_js;
vector<int64 >e;
void generatefactorial(int64 p)
{
    fact[0] = fact[1 ]= 1;
    int64 i;
    for (i = 2; i < mod; i++)
    {
        if(i%p==0) fact[i] = fact[i-1];
        else fact[i] =  (fact[i - 1] * i)%mod;
    }
}

vector<int64 >v;
vector<int64 > tobase(int64 a,int64 b)
{
    v.clear();
    while(a)
    {
        v.PB(a%b);
        a /= b;
    }
    return v;
}
vector<int64 >tmp;
vector<int64 > compute_js(vector<int64 >v,int64 p,int64 q)
{
    int64 len = v.size();
    tmp.clear();
    tmp.resize(len);
    rep(i,len)
    {
        int64 a = 0,P = 1;
        for(int64 j = i; j<len && j < i+q ; j++)
        {
            a += (v[j]*P);
            P *= p;
        }
        tmp[i] = a;
    }
    return tmp;
}

vector<int64 > computeE(int64 len,vector<int64 >M,vector<int64 >R,int64 p)
{
    int64 m = M.size(),r = R.size(),c = 0;
    tmp.clear();
    tmp.resize(len);
    forab(i,m,len-1) M.PB(0);
    forab(i,r,len-1) R.PB(0);
    rep(i,len)
    {
        c += M[i];
        c += R[i];
        c /= p;
        tmp[i] = c;
    }
    per(i,len-1) tmp[i] = tmp[i] + tmp[i+1];
    return tmp;
}



int64 generelize_lucas_theoram(int64 n,int64 r,int64 p,int64 q)
{
    int64 m = (n-r);
    N = tobase(n,p);
    R = tobase(m,p);
    M = tobase(r,p);
    N_js = compute_js(N,p,q);
    M_js = compute_js(M,p,q);
    R_js = compute_js(R,p,q);
    int64 n_len = N.size(), m_len = M.size(), r_len = R.size();
    e =computeE(n_len,R,M,p);
    int64 ans = 1;
    mod = Pow(p,q);
    generatefactorial(p);
    rep(i,e[0]) ans = (ans*p)%mod;
    rep(i,n_len) ans = (ans*fact[N_js[i]%mod])%mod;
    rep(i,m_len) ans = (ans*modInverse_relativePrime(fact[M_js[i]%mod],mod))%mod;
    rep(i,r_len) ans = (ans*modInverse_relativePrime(fact[R_js[i]%mod],mod))%mod;
    if((p != 2 || q<3) && (q<=e.size() && e[q-1]%2)) ans = (-1*ans)%mod;
    return ans<0?ans+mod:ans;
}

void generate_primeDivisors(int64 n)
{
    primeDivisors.clear();

    int64 cnt = 0 ;

    while(n % 2 == 0 )
    {
        n>>=1, cnt++;
    }

    if(cnt) primeDivisors.push_back( pii(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 )
    {
        cnt = 0 ;
        while(n % i == 0 ) n /= i, cnt++ ;
        if(cnt) primeDivisors.push_back( pii(i,cnt) );
    }

    if(n > 1 ) primeDivisors.push_back( pii(n,1) ) ;
}


int64 Chinese_Remainder_Theorem(int64 m)
{
    int i = 0;
    int64 ans = 0;
    forstl(it,primeDivisors)
    {
        int64 p = Pow((*it).first,(*it).second);
        //cout << p << endl;
        int64 e = ((m/p) * modInverse_relativePrime(m/p,p))%m;
        ans = (ans + (L[i] * e)%m)%m;
        i++;
    }
    //cout << ans << endl;
    return ans<0?ans+m:ans;
}
ll binomial(ll n,ll r, ll m)
{

    generate_primeDivisors(mod);
    L.clear();
    forstl(it,primeDivisors)
    {
        L.PB(generelize_lucas_theoram(n,r,(*it).first,(*it).second));
    }
    return Chinese_Remainder_Theorem(m);
}
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
//    getI(t);
//    int64 mm = 1000001;
//    rep(cs,t)
//    {
//        SET(dp);
        getLLL(n,m,mod);
        ll ans = binomial(n,m,mod);
        printf("%lld\n",ans);
//    }

    return 0;
}