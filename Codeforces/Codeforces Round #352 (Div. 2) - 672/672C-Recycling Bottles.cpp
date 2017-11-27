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
struct point   // Creates normal 2D point     double x, y;
{
    double x,y;
    point() {}
    point(double xx, double yy)
    {
        x = xx, y = yy;
    }
};
inline double Distance( point a, point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
double rcycle[100005],adi[100005],bella[100005];
double dp[100005][(1<<3)+3];
int mark[100005][(1<<3)+3];
double call(int pos,int mask)
{
    if(pos==n+1)
    {
        if(__builtin_popcount(mask)>=1)return 0;
        return INF;
    }
    double &ret=dp[pos][mask];
    if(mark[pos][mask])return ret;
    mark[pos][mask]=1;
    double ans1=INF,ans2=INF,ans3=INF;
    if(bitCheck(mask,1)==0)ans1=call(pos+1,bitOn(mask,1))+adi[pos]-rcycle[pos];
    if(bitCheck(mask,2)==0)ans2=call(pos+1,bitOn(mask,2))+bella[pos]-rcycle[pos];
    ans3=call(pos+1,mask);

    return ret=min(ans1,min(ans2,ans3));
}



int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    point ad,bel,rc;
    getF(ad.x);
    getF(ad.y);
    getF(bel.x);
    getF(bel.y);
    getF(rc.x);
    getF(rc.y);
    getI(n);
    point tmp;
    double ans=0.0;
    CLR(mark);
    rep(i,n)
    {
        getF(tmp.x);
        getF(tmp.y);
        rcycle[i]=Distance(tmp,rc);
        adi[i]=Distance(tmp,ad)+rcycle[i];
        bella[i]=Distance(tmp,bel)+rcycle[i];
        rcycle[i]*=2.0;
        ans+=rcycle[i];
    }
    /* double pl=-1,mn=-1,dif=-1;
     rep(i,n)
     {
         if(adi[i]+EPS<rcycle[i]&&adi[i]+EPS<bella[i])
         {
             if(pl==-1)
             {
                 pl=adi[i];
                 mn=rcycle[i];
                 dif=mn-pl;
             }
             else if((rcycle[i]-adi[i])>dif+EPS)
             {

                 pl=adi[i];
                 mn=rcycle[i];
                 dif=mn-pl;
             }
         }
     }
     int flag=1;
     if(pl!=-1)flag=0;
     if(pl!=-1)
     {
         ans-=mn;
         ans+=pl;
     }
     pl=-1;mn=-1;
     rep(i,n)
     {
         if(bella[i]+EPS<rcycle[i]&&bella[i]+EPS<adi[i])
         {
             if(pl==-1)
             {
                 pl=bella[i];
                 mn=rcycle[i];
                 dif=mn-pl;
             }
             else if((rcycle[i]-bella[i])>dif+EPS)
             {

                 pl=bella[i];
                 mn=rcycle[i];
                 dif=mn-pl;
             }
         }
     }
     if(pl!=-1)flag=0;
     if(pl!=-1)
     {
         ans-=mn;
         ans+=pl;
     }
     if(flag)
     {

     }
     */
    ans+=call(1,0);
    printf("%.12lf\n",ans);



    return 0;
}