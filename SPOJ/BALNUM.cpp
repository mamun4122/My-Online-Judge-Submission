
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
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
int t;
ull n,m;
ull dp[20][2][(1<<10)+4][(1<<10)+4];
int mark[20][2][(1<<10)+4][(1<<10)+4];
vector<int> dig;
int tot;
int ci;
void calc(ull num)
{
    dig.clear();
    while(num)
    {
        dig.push_back(num%10);
        num/=10;
    }
    if(dig.size()==0)dig.push_back(0);
    reverse(ALL(dig));
    tot = dig.size();
}
int cur ;
int check(int mask,int digit)
{
    repI(i,10)
    {
        if(bitCheck(digit,i))
        {
            if(i%2==0 && bitCheck(mask,i) == 0)return 0;
            if(i%2==1 && bitCheck(mask,i) == 1)return 0;
        }
    }
    return 1;
}
ull call(int pos,int flag,int mask,int digit)
{
    if(pos == cur)return check(mask,digit);
    ull &ret = dp[pos][flag][mask][digit];
    int &vis = mark[pos][flag][mask][digit];
    if(vis == ci)return ret;
    vis = ci;
    ret = 0;
    if(flag)
    {
        int suru = (pos == 0 ? 1:0);
        FOR(i,suru,dig[pos])
        {
            ret +=  call(pos+1,i==dig[pos],bitFlip(mask,i),bitOn(digit,i));
        }
    }
    else
    {
        int suru = (pos == 0 ? 1:0);
        FOR(i,suru,9)
        {
            ret +=  call(pos+1,0,bitFlip(mask,i),bitOn(digit,i));
        }
    }
    return ret;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    ci = 1;
    CLR(mark);
    int dummy = 0;
//    repI(i,10)if(i%2 == 0)dummy = bitOn(dummy,i);
    rep(cs,t)
    {
        scanf("%llu %llu",&n,&m);
        calc(m);
        ll ans = 0;
        rep(i,tot)
        {
            cur = i;
            ci++;
            ans += call(0,i==tot,0,0);

        }
        debug(ans)
        calc(n-1);
        rep(i,tot)
        {
            cur = i;
            ci++;
            ans -= call(0,i==tot,0,0);
        }
        printf("%llu\n",ans);
    }

    return 0;
}

