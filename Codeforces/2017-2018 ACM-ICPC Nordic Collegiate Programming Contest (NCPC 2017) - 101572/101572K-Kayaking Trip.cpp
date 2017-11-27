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
//int t,n,m;
int b,n,e;
int sb,sn,se;
int tot;
int c[100004];

struct data
{
    int speed;
    int a[3];

//    data()
//    {
//        CLR(a);
//    }
};

bool comp(const data &a, const data &b)
{
    if(a.speed <= b.speed) return true;
    return false;
}

vector < data > vd;

int check(int mini)
{
    int nb, nn, ne;
    nb = b, nn = n, ne = e;
    FOR(i,1,tot/2)
    {
        int flg = 0;
        repI(j, vd.size())
        {
            if(nb-vd[j].a[0] >= 0 && nn-vd[j].a[1] >= 0 && ne-vd[j].a[2] >= 0 && c[i]*vd[j].speed >= mini)
            {
                flg = 1;
                nb -= vd[j].a[0];
                nn -= vd[j].a[1];
                ne -= vd[j].a[2];
                break;
            }
        }

//        debug(mini,i, flg)
        if(flg == 0) return 0;
    }
    return 1;
}

void gen()
{
    vd.clear();
    data d;
    d.speed = sb + sb;
    CLR(d.a);
    d.a[0] = 2;
    vd.PB(d);

    d.speed = sb + sn;
    CLR(d.a);
    d.a[0] = d.a[1] = 1;
    vd.PB(d);

    d.speed = sb + se;
    CLR(d.a);
    d.a[0] = d.a[2] = 1;
    vd.PB(d);

    d.speed = sn + sn;
    CLR(d.a);
    d.a[1] = 2;
    vd.PB(d);

    d.speed = sn + se;
    CLR(d.a);
    d.a[1] = d.a[2] = 1;
    vd.PB(d);

    d.speed = se + se;
    CLR(d.a);
    d.a[2] = 2;
    vd.PB(d);

    sort(ALL(vd), comp);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("inI.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while( ~ getIII(b,n,e) )
    {
        tot = b+n+e;

        getIII(sb,sn,se);

        gen();

        FOR(i,1,tot/2)
        {
            getI(c[i]);
        }

        int low = 0, high = 200000004;
        int res = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;

            int kk = check(mid);

            if(!kk)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                res = mid;
            }
        }
        printf("%d\n",res);
    }

    return 0;
}