#pragma comment(linker, "/stack:640000000")

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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
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
ll ncr[105][105];
#define mod 1000000007
ll dp[102][102];
ll call(int pos,int tot)
{
//    if(tot==0)return 1;
    if(pos>n)return (tot==0);
    ll &ret=dp[pos][tot];
    if(ret!=-1)return ret;
    ll res=0;
    rep(i,m)
    {
        if(tot-(i-1)<0)break;
        res=(res%mod+(ncr[tot][i-1]*call(pos+1,tot-(i-1)))%mod)%mod;
    }
    return ret=res%mod;
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ncr[0][0] = 1 ;
    int limncr = 100 ;
    int i,j;
    for ( i = 1 ; i <= limncr ; i++)
        for ( j = 0 ; j <= limncr ; j++)
        {
            if ( j > i ) ncr[i][j] = 0 ;
            else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
            else ncr [i][j] = (ncr[i-1][j - 1] + ncr[i-1][j])%mod ;
        }
        while(~getII(n,m))
        {
            if(n==1&&m==1)
            {
                puts("1");
                continue;
            }
            SET(dp);
            printf("%lld\n",call(1,n-2));

        }



    return 0;
}


