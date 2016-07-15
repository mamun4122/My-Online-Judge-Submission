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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
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
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
//******************DELETE****************
int t,n,m;

ll ext_gcd ( ll A, ll B, ll *X, ll *Y )
{
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}
bool linearDiophantine ( ll A, ll B, ll C, ll *x, ll *y )
{
    ll g = gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution

    ll a = A / g, b = B / g, c = C / g;
    ext_gcd( a, b, x, y ); //Solve ax + by = 1

    if ( g < 0 )   //Make Sure gcd(a,b) = 1
    {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    *x *= c;
    *y *= c; //ax + by = c
    return true; //Solution Exists
}

int main ()
{
//    READ("in.txt");
    //WRITE("out.txt");
    ll n;
    while(getL(n)&&n)
    {
        ll a,b,c,d;
        getL(c);
        getL(a);
        getL(d);
        getL(b);

        ll x,y;
        bool res=linearDiophantine(a,b,n,&x,&y);
        if(res)
        {
            ll gc=gcd(a,b);
            ll rise=b/gc;
            ll run=a/gc;
            ll cnt=0;
            if(x<0)
            {
                cnt=ceil((double)abs(x)/rise);
                x+=cnt*rise;
                y-=cnt*run;
            }
            if(y<0)
            {
                cnt=ceil((double)abs(y)/run);
                y+=cnt*run;
                x-=cnt*rise;
            }
//            debug(x,y)
            ll sol1=INF,sol2=INF;

            ///x k 0 er kache nilam
            ll x1=x,y1=y;
            cnt=floor((double)abs(x)/rise);
            x1-=cnt*rise;
            y1+=cnt*run;
            sol1=x1*c+y1*d;
            if(x1<0||y1<0)sol1=INF;

            ///Y k nilam 0 er kache
            ll x2=x,y2=y;
            cnt=floor((double)abs(y)/run);
            y2-=cnt*run;
            x2+=cnt*rise;
            sol2=x2*c+y2*d;
            if(x2<0||y2<0)sol2=INF;

//            debug(sol1,sol2)
            if(sol1==INF&&sol2==INF)printf("failed\n");
            else if(sol1<=sol2)printf("%lld %lld\n",x1,y1);
            else printf("%lld %lld\n",x2,y2);

        }
        else
        {
            puts("failed");
        }
    }




    return 0;
}


