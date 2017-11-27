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
ll arr[105][105];

ll bit[10005];
void update ( int x, int v )
{
    while ( x < 10005 )
    {
        bit[x] += v;
        x += x & (-x);
    }
}
ll query ( int x )
{
    ll res = 0;
    while ( x )
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        ll k;
        getL(k);
        int x,y;
        getII(x,y);
        ll tot=n*m;
        CLR(bit);
        int modde=max(n-2,0);
        ll sum=m+modde*m;
        ll cnt=k/sum;
        ll lft=k%sum;
//        debug(sum,cnt,lft)
        CLR(arr);
        if(n==1)
        {
            rep(i,n)rep(j,m)arr[i][j]=cnt;
            rep(i,n)rep(j,m)if(lft)arr[i][j]++,lft--;
            ll mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
            rep(i,n)rep(j,m)
            {
                mn=min(mn,arr[i][j]);
                mx=max(mx,arr[i][j]);
            }
            printf("%lld %lld %lld\n",mx,mn,arr[x][y]);
            continue;
        }
        rep(i,n)rep(j,m)
        {
            if(i==1)arr[i][j]=cnt/2+cnt%2;
            else if(i==n)arr[i][j]=cnt/2;
            else arr[i][j]=cnt;
        }
        if(cnt%2==1)
        {
            for(int i=n; i>=1; i--)
            {
                rep(j,m)
                {
                    if(lft)lft--,arr[i][j]++;
                }
            }
        }
        else rep(i,n)rep(j,m)if(lft)lft--,arr[i][j]++;
//        rep(i,n)
//        {
//            rep(j,m)printf("%lld ",arr[i][j]);
//            puts("");
//        }
        ll mn=LONG_LONG_MAX,mx=LONG_LONG_MIN;
        rep(i,n)rep(j,m)
        {
            mn=min(mn,arr[i][j]);
            mx=max(mx,arr[i][j]);
        }
        printf("%lld %lld %lld\n",mx,mn,arr[x][y]);

    }
    return 0;
}