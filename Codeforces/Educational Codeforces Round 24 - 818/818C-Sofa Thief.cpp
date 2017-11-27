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
#define MAX 100005
int lft[MAX],rght[MAX],up[MAX],down[MAX];
int minX[MAX],maxX[MAX],minY[MAX],maxY[MAX];
int somanX[MAX],somanY[MAX];
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
//        CLR(bit);
        int x,y;
        getII(x,y);
        CLR(lft),CLR(rght),CLR(up),CLR(down),CLR(somanX),CLR(somanY);
        rep(i,n)
        {
            pii a,b;
            getII(a.ff,a.ss);
            getII(b.ff,b.ss);
            minX[i] = min(a.ff,b.ff);
            maxX[i] = max(a.ff,b.ff);
            minY[i] = min(a.ss,b.ss);
            maxY[i] = max(a.ss,b.ss);
            somanX[i] = a.ff == b.ff;
            somanY[i] = a.ss == b.ss;
            lft[minX[i]]++;
            rght[maxX[i]]++;
            down[minY[i]]++;
            up[maxY[i]]++;
        }
        rep(i,100000)lft[i] += lft[i-1],down[i] += down[i-1];
        ROF(i,100000,1)rght[i] += rght[i+1], up[i] += up[i+1];
        int flag = 1;
        int cntl,cntr,cntu,cntd;
        getII(cntl,cntr);
        getII(cntu,cntd);
        rep(i,n)
        {
            int sum1 = lft[maxX[i]-1] - (1-somanX[i]);
            if(sum1 != cntl)continue;
            int sum2 = rght[minX[i]+1] - (1-somanX[i]);
            if(sum2 != cntr)continue;
            int sum3 = down[maxY[i]-1] - (1-somanY[i]);
            if(sum3 != cntu)continue;
            int sum4= up[minY[i]+1] - (1-somanY[i]);
            if(sum4 != cntd)continue;
            flag = 0;
            printf("%d\n",i);
            break;
            debug(sum1,sum2,sum3,sum4)
        }
        if(flag)puts("-1");
    }

    return 0;
}