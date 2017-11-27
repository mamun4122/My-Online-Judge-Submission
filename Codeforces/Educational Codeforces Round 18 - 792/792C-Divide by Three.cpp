#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 1e7;
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
int t,n,m;
string s;
int dp[100005][5][2];
int pri[100005][5][2];
int call(int pos, int rem, int strt)
{
    int &ret = dp[pos][rem][strt];
    if(pos >= s.size())
    {
        if(rem == 0 && strt) return ret = 0;
        return ret = INF;
    }

//    debug(pos,rem,strt)
    if(ret != -1) return ret;
    ret = INF;
    if(!(s[pos] == '0' && strt == 0))
    {
//        debug((rem*10+(s[pos]-'0'))%3)
        ret = call(pos+1, (rem*10+(s[pos]-'0'))%3,strt||(s[pos]-'0'));
        pri[pos][rem][strt] = 1;
    }
//    debug("")
    if(call(pos+1, rem, strt)+1 < ret)
    {
        ret = min(ret, call(pos+1, rem, strt)+1);
        pri[pos][rem][strt] = 0;
    }
    return ret;
}
void print(int pos, int rem, int strt)
{
    if(pos == s.size())
    {
        puts("");
        return;
    }
    if(pri[pos][rem][strt]){
        printf("%c",s[pos]);
        print(pos+1, (rem*10+(s[pos]-'0'))%3,strt||(s[pos]-'0'));
        return;
    }
    print(pos+1, rem, strt);
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>s)
    {
        CLR(pri);
        SET(dp);
        int zero = 0;
        repI(i,s.size())if(s[i] == '0')zero = 1;
        int ret = call(0,0,0);
        if(ret == INF)
        {
            if(!zero)puts("-1");
            else puts("0");
        }
        else
            print(0, 0, 0);
    }
    return 0;
}