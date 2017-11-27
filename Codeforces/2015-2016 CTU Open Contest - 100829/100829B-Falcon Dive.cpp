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
int t,n,m;
#define MAX 1005
char arr[2][MAX][MAX];
char ans[MAX][MAX];
char x;
char pat[10];

void printAns()
{
    repI(i,n)puts(ans[i]);
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int space = 0;
    while(scanf("%d %d %s",&n,&m,pat))
    {
//        debug(n,m)
//        getchar();getchar();
//        getline(cin,pat);
//        debug(pat)
        if(!(n||m))break;
        if(space)puts("");
        space = 1;
//        debug("ff")
        x = pat[1];
//        debug(n,m,pat,x)
//        debug(pat.size());
        repI(i,n)scanf("%s",arr[0][i]);
//        getchar();
        repI(i,n)scanf("%s",arr[1][i]);
//        getchar();
//        repI(i,n)debug(arr[0][i]);
//        repI(i,n)debug(arr[1][i]);
//        getchar();
        CLR(ans);
        repI(i,n)repI(j,m)ans[i][j] = '.';
        repI(i,2)repI(j,n)repI(k,m)
        {
            if(arr[i][j][k] != x)
                ans[j][k] = arr[i][j][k];

        }
        repI(i,n)ans[i][m] = '\0';
        pii lst = {-1,-1};
        ROF(i,n-1,0)
        {
            repI(j,m)
            {
                if(arr[1][i][j] == x)
                {
                    lst = {i,j};
                    break;
                }
            }
        }
        if(lst.ff == -1)
        {
            printAns();
            continue;
        }
        pii anthr;
        ROF(i,n-1,0)
        {
            repI(j,m)
            {
                if(arr[0][i][j] == x)
                {
                    anthr = {i,j};
                    break;
                }
            }
        }
        int xshift = lst.ff-anthr.ff;
        int yshift = lst.ss-anthr.ss;
        repI(i,n)
        {
            repI(j,m)
            {
                if(arr[1][i][j] == x)
                {
                    int xx = i + xshift;
                    int yy = j + yshift;
                    if(xx >= 0 && xx <n && yy >= 0 && yy < m )
                        ans[xx][yy] = x;
                }
            }
        }
        printAns();
    }

    return 0;
}