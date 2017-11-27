#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <ctime>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double



const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}



//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
const double eps = 1e-11, pi = 2 * acos( 0.0 );
struct point   // Creates normal 2D point
{
    long double x, y;
    point() {}
    point( long double xx, long double yy )
    {
        x = xx, y = yy;
    }
};

struct circle
{
    point center;
    long double r;
    circle() {}
    circle( point P, long double rr )
    {
        center = P;
        r = rr;
    }
};
inline long double Distance( point a, point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
inline long double intersectionArea2C( circle C1, circle C2 )
{
    C2.center.x =Distance( C1.center, C2.center );
    C1.center.x = C1.center.y = C2.center.y =0;
    if( C1.r < C2.center.x - C2.r + eps )return 0;
    if(-C1.r + eps > C2.center.x - C2.r )return pi * C1.r * C1.r;
    if( C1.r + eps > C2.center.x + C2.r )return pi * C2.r * C2.r;
    long double c, CAD, CBD, res;
    c = C2.center.x;
    CAD =2*acos((C1.r * C1.r + c * c - C2.r * C2.r)/(2* C1.r * c));
    CBD =2*acos((C2.r * C2.r + c * c - C1.r * C1.r)/(2* C2.r * c));
    res=C1.r * C1.r *( CAD -sin( CAD ))+ C2.r * C2.r *( CBD -sin( CBD ));
    return .5* res;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    circle a,b;
    while(cin>>(a.center.x))
    {
        cin>>(a.center.y);
        cin>>(a.r);
        cin>>(b.center.x);
        cin>>(b.center.y);
        cin>>(b.r);
        cout.precision(20);
        cout<<fixed<<intersectionArea2C(a,b)<<endl;
    }





    return 0;
}