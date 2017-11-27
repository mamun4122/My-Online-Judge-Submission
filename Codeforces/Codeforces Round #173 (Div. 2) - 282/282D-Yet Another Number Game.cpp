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

int arr[4];
int dp[305][305];

int call(int x,int y)
{
    if(x == 0 && y == 0)
        return 0;
    int  &ret = dp[x][y];
    if(ret != -1)
        return ret;
    ret = 0;
    rep(i,max(x,y))
    {
        if(i <= x && call(x-i,y) == 0)
            return ret = 1;

        if(i <= y && call(x, y-i) == 0)
            return ret = 1;

        if(i <= x && i <= y && call(x-i,y-i) == 0)
            return ret = 1;
    }
    return ret;
}
int dp1[305][305][305];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        rep(i,n)getI(arr[i]);
        if(n == 1)
        {
            if(arr[1])
                puts("BitLGM");
            else
                puts("BitAryo");
            continue;
        }
        if(n == 2)
        {
            SET(dp);
            if(call(arr[1],arr[2]))
                puts("BitLGM");
            else
                puts("BitAryo");
            continue;
        }
        CLR(dp1);
        int mx = max(max(arr[1],arr[2]),arr[3]) + 2;
//        repI(i,mx)dp1[i][0][0] = 1;
//        repI(j,mx)dp1[0][j][0] = 1;
//        repI(k,mx)dp1[0][0][k] = 1;
        repI(i,mx)repI(j,mx)repI(k,mx)
        {
            if(!dp1[i][j][k])
            {
                rep(l,mx)
                {
                    if(i+l > mx || j+l > mx || k+l > mx)break;
                    dp1[i+l][j+l][k+l] = 1;
                }
                rep(l,mx)
                {
                    if(i+l > mx)break;
                    dp1[i+l][j][k] = 1;
                }
                rep(l,mx)
                {
                    if(j+l > mx)break;
                    dp1[i][j+l][k] = 1;
                }
                rep(l,mx)
                {
                    if(k+l > mx)break;
                    dp1[i][j][k+l] = 1;
                }
            }
        }
        if(dp1[arr[1]][arr[2]][arr[3]])
            puts("BitLGM");
        else
            puts("BitAryo");
    }

    return 0;
}