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
int n,m,k;

int fans[12][4];
vi adj[12];
vi other[12];
double dp[12][12][(1<<10)+4];
int vis[12][12][(1<<10)+4];
int path[12][12][(1<<10)+4];
int tt;

double call(int u, int week, int mask)
{
//    debug(week, mask, "gf")
    if(week > n) return 0.0;

    double &ret = dp[u][week][mask];
    if(vis[u][week][mask] == tt)
        return ret;

    vis[u][week][mask] = tt;

    ret = 0.0;


    double ordinary = 0.0;
    set <int> o;
    /// ei week k k asbe ei city te
    FOR(i,0,k-1)
    {
        if(other[i][week]==u)
        {
            o.insert(i);
        }
    }

    int nije=0,ot[12];
    /// nije ashe pasher koita city te gesi?
    for(auto v: adj[u])
    {
        if(bitCheck(mask, v)==1) nije++;
    }
    CLR(ot);
    int ff = 0;
    /// other ra ashepasher koita city te gese?
    for (auto musician: o)
    {
        int tmp = 0;
        /// er ager week er modhe
        FOR(j,1,week-1)
        {
            tmp = bitOn(tmp, other[musician][j]);
        }
        /// jesob city te gese tader temp oi pos 1
        /// so oi pos jdi neighbour hoi then plus plus korlam
        for(auto v: adj[u])
        {
            if(bitCheck(tmp, v)==1)
            {
                ot[musician]++;
                ff= 1;
            }
        }

        if(bitCheck(tmp, u) == 1)
        {
            ot[musician]++;
        }
    }

    int maxy = -1;
    /// maximum info ber korlam
    FOR(i,0,k-1)
    {
        maxy = max(maxy, ot[i]);
    }

    /// nije jitle sb nijer tai aslo
//    if(nije > maxy || ff==0)
//    {
//        ordinary += fans[u][0];
//    }
//    /// nije soman hole koijn soman ber korlam
//    /// and oi khan theke ordinary o ber korlam
//    else
    if(nije >= maxy)
    {
        int cnt = 0;
        for(auto i: o)
        {
            if(nije == ot[i]) cnt++;
        }
        cnt++;
//        debug(u, week, cnt, maxy)

        ordinary += ((double)fans[u][0] / cnt);
    }
    /// nije kom hole keo asbe na
    else ordinary = 0.0;

    double crazy = 0.0;
    /// crazy te joto gula fan tara randomly jabe jkhn onkk e ek sathe thakbe
    crazy += ( ( (double)fans[u][1] / (o.size()+1) ) * 7.0 );

    double maniac = 0.0;
    /// ei week e pasher city gulai kara kara jabe?
    for(auto v: adj[u])
    {
        FOR(i,0,k-1)
        {
            if(other[i][week] == v)
            {
                o.insert(i);
            }
        }
    }

    /// ei city er fan der pailam
    maniac += ( ( (double) fans[u][2] / (o.size()+1 ) ) * 7.0 );

    /// ekhn pasher city gulai maniac khujte hbe
    /// ekhn pashe neighbour v te jai
    for(auto v: adj[u])
    {
        int concert = 0;
        /// v er neighbour vv te
        for(auto vv: adj[v])
        {
            /// vv te ei week kono concert hsse naki check kori
            /// hole concert++
            FOR(i,0,k-1)
            {
                if(other[i][week] == vv)
                {
                    concert++;
                }
            }
            /// nijer tao ar 1 ber count hbe
            if(vv == u) concert++;
        }
        FOR(i,0,k-1)
        {
            if(other[i][week] == v)
            {
                concert++;
            }
        }

        if(concert > 0 )
        {
//            debug(u, week, v, ( ( (double) fans[v][2] / (concert) ) * 7.0 ), maniac)
            maniac += ( ( (double) fans[v][2] / (concert) ) * 7.0 );
        }
//        else
//        {
////            debug(u, week, v, ( ( (double) fans[v][2] ) * 7.0 ), maniac)
//            maniac += ( ( (double) fans[v][2] ) * 7.0 );
//        }
    }


    double total = ordinary + crazy + maniac;

    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i)==0)
        {
            double kk = call(i, week+1, bitOn(mask, i));
//            if(mask == 3)debug(i,kk,ret)
            if(kk > ret + EPS || fabs(kk-ret) < EPS)
            {
//                if(mask == 3)debug("Duksi")
                path[u][week][mask] = i;
                ret = kk;
            }
        }
    }

//    debug(u, week, mask, ret+total, total, ordinary, crazy, maniac)
//    debug(u,week,mask,path[u][week][mask])
    ret = ret + total;
    return ret;
}
int flg;
void dpPrint(int u, int week, int mask)
{
    if(week > n) return;

    int kk = path[u][week][mask];

//    debug(u,week,mask,path[u][week][mask])

    if(flg) printf(" ");
    flg = 1;
    printf("%d",u+1);

    if(POPCOUNT(mask)==n) return;

    dpPrint(kk, week + 1, bitOn(mask, kk));

}

int main() {
    ///check for 0 or -1 if input not specified
    /// For printing double use %f
    #ifdef mamun
        READ("in.txt");
    #else
        READ("musical.in");
        WRITE("musical.out");
    #endif // mamun

//    int n,m,k;
    CLR(vis);
    tt=1;
    while(~getIII(n,m,k))
    {
        FOR(i,0,n-1)
        {
            FOR(j,0,2)
            {
                getI(fans[i][j]);
            }
        }

        FOR(i,0,11) adj[i].clear();

        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
            x--,y--;
            adj[x].PB(y);
            adj[y].PB(x);
        }

        FOR(i,0,k-1)
        {
            other[i].clear();
            other[i].PB(-1);
            FOR(j,1,n)
            {
                int x;
                getI(x);
                x--;
                other[i].PB(x);
            }
        }

        double res = 0.0;
        tt++;
        int strt=0;
        int mask = 0;
        flg = 0;
//        debug(call(0,1,bitOn(mask,0)));
////        debug(call(1,2,1), dp[1][2][1])
//        dpPrint(0,1,bitOn(mask,0));
//        continue;
        FOR(i,0,n-1)
        {
//            CLR(vis);
            tt++;
            double kk = call(i, 1, bitOn(mask, i));
//            debug(i, kk)
            if(kk > res + EPS)
            {
                res = kk;
                strt = i;
            }
        }
        tt++;
//        CLR(vis);
        res = call(strt, 1, bitOn(mask, strt));
        cout << setprecision(10) << fixed << res << endl;
        dpPrint(strt, 1, bitOn(mask, strt));
        printf("\n");
//        debug(dp[1][2][1]);
//        debug(dp[2][3][3]);
    }

    return 0;
}