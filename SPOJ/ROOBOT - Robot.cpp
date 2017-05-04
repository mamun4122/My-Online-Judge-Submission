#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
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
double u,r,d,l;
int mark[505][505][505];
double dp[505][505][505];
int ci;
double call_rght(int mov,int x,int best_x)
{
    if(mov == 0)return (double)best_x;
    int &vis = mark[mov][x][best_x];
    double &ret = dp[mov][x][best_x];
    if(vis == ci)return ret;
    vis = ci;
    ret = r*call_rght(mov-1,x+1,max(best_x,x+1));
    ret += l*call_rght(mov-1,x-1,best_x);
    ret += (d+u)*call_rght(mov-1,x,best_x);
    return ret;
}
double call_lft(int mov,int x,int min_x)
{
    if(mov == 0)return (double)min_x;
    int &vis = mark[mov][x][min_x];
    double &ret = dp[mov][x][min_x];
    if(vis == ci)return ret;
    vis = ci;
    ret = r*call_lft(mov-1,x+1,min_x);
    ret += l*call_lft(mov-1,x-1,min(min_x,x-1));
    ret += (d+u)*call_lft(mov-1,x,min_x);
    return ret;
}
double call_up(int mov,int y,int best_y)
{
    if(mov == 0)return (double)best_y;
    int &vis = mark[mov][y][best_y];
    double &ret = dp[mov][y][best_y];
    if(vis == ci)return ret;
    vis = ci;
    ret = u*call_up(mov-1,y+1,max(best_y,y+1));
    ret += d*call_up(mov-1,y-1,best_y);
    ret += (l+r)*call_up(mov-1,y,best_y);
    return ret;
}

double call_down(int mov,int y,int min_y)
{
    if(mov == 0)return (double)min_y;
    int &vis = mark[mov][y][min_y];
    double &ret = dp[mov][y][min_y];
    if(vis == ci)return ret;
    vis = ci;
    ret = u*call_down(mov-1,y+1,min_y);
    ret += d*call_down(mov-1,y-1,min(y-1,min_y));
    ret += (l+r)*call_down(mov-1,y,min_y);
    return ret;
}
/// page 48
/// http://www.bubblecup.org/Content/Media/Booklet2016.pdf

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    ci = 1;
    CLR(mark);
    while(~getI(n))
    {
        getF(u);
        getF(r);
        getF(d);
        getF(l);
        double ans = 0.0;
        ci++;
        ans += call_rght(n,n,n);
////        debug(call_rght(n,n,0))
        ci++;
        ans -= call_lft(n,n,n);
        ci++;
        ans += call_up(n,n,n);
        ci++;
        ans -= call_down(n,n,n);
        printf("%.10lf\n",ans);

    }

    return 0;
}

