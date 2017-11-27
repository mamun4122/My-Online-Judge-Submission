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

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n)
    {
        int lft = 0, rght = 0;
        int up = 0, down = 0;
        string s;
        cin >> s;
        repI(i,s.size())
        {
            if(s[i] == 'L')lft++;
            else if(s[i] == 'R')rght++;
            else if(s[i] == 'U')up++;
            else down++;
        }
        int x,y;
        cin >> x >> y;
//        debug(n,s,x,y)
        int flag = 0;
        if(x < 0 && lft < abs(x))
            flag = 1;
        if(y < 0 && down < abs(y))
            flag = 1;
        if(x > 0 && rght < abs(x))
            flag = 1;
        if(y > 0 && up < abs(y))
            flag = 1;
        if(flag == 1)
        {
            puts("-1");
            continue;
        }
        int posl = 0, posr = 0;
        int posu = 0, posd = 0;
        if(x > 0)
        {
            repI(i,s.size())
            {
                if(s[i] == 'R')
                    x--;
                if(x == 0)
                {
                    posr = i+1;
                    break;
                }
            }
        }
        if(x < 0)
        {
            repI(i,s.size())
            {
                if(s[i] == 'L')
                    x++;
                if(x == 0)
                {
                    posl = i+1;
                    break;
                }
            }
        }
        if(y > 0)
        {
            repI(i,s.size())
            {
                if(s[i] == 'U')
                    y--;
                if(y == 0)
                {
                    posu = i+1;
                    break;
                }
            }
        }
        if(y < 0)
        {
            repI(i,s.size())
            {
                if(s[i] == 'D')
                    y++;
                if(y == 0)
                {
                    posd = i+1;
                    break;
                }
            }
        }
        printf("%d %d %d %d\n",posl,posu,posr,posd);
    }

    return 0;
}