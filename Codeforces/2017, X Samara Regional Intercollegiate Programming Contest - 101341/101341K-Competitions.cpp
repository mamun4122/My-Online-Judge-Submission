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
#define    ff   first
#define    ss   second
#define    ll  long long
#define    pii   pair< ll, ll >
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
ll t,n,m;
#define piii pair <pii, pii>
vector < piii > vp;
ll dp[200004];
ll dp1[200004];
ll pri[200004];

int bin_src(ll val)
{
    int low = 0, high = n-1;
    int res = n;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(vp[mid].ff.ff >= val)
        {
            res = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return res;
}

ll call(int in)
{
    if(in>=n) return 0;

    ll &ret = dp[in];
    if(ret!=-1) return ret;

    int pos = bin_src(vp[in].ff.ss);
    ll o1 = vp[in].ss.ff + call(pos);
    ll o2 = call(in+1);

    ll oo1 = vp[in].ff.ss - vp[in].ff.ff;

    if(o1 == o2)
    {
        if(oo1 + dp1[pos] < dp1[in+1])
        {
            pri[in] = 1;
            dp1[in] = oo1 + dp1[pos];
        }
        else
        {
            pri[in] = 1+1;
            dp1[in] = dp1[in+1];
        }
    }
    else if(o1 > o2)
    {
        pri[in] = 1;
        dp1[in] = oo1 + dp1[pos];
    }
    else
    {
        pri[in] = 1+1;
        dp1[in] = dp1[in+1];
    }
    return ret = max(o1, o2);
}

vi res;
void call1(int in)
{
    if(in>=n) return;
    int kk = pri[in];
    if(kk == 1)
    {
        int pos = bin_src(vp[in].ff.ss);
        res.PB(vp[in].ss.ss);
        call1(pos);
    }
    else
    {
        call1(in+1);
    }
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getL(n))
    {
        vp.clear();
        CLR(dp1);
        FOR(i,1,n)
        {
            ll x,y,z;
            getLLL(x,y,z);
            vp.PB(MP(MP(x,y),MP(z,i)));
        }
        sort(ALL(vp));
        SET(dp);
        ll res1 = call(0);
        res.clear();
        call1(0);
        printf("%d %lld %lld\n",(int)res.size(),res1,dp1[0]);
        FOR(i,0,(int)res.size()-1)
        {
            if(i) printf(" ");
            printf("%d",res[i]);
        }
        printf("\n");
    }

    return 0;
}