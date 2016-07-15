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
const int INF = 100000;
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
int dist[20][20];
int dp[(1<<16)+4];
int deg[20];
int call(int mask)
{
    if(__builtin_popcount(mask)==n)return 0;
    int &ret=dp[mask];//[strt][cur];
//    debug(mask)
    if(ret!=-1)return ret;
    int ans=INF;
    rep(i,n)
    {
        if(bitCheck(mask,i)==0)
        {
            int tmp=bitOn(mask,i);
            rep(j,n)
            {
                if(bitCheck(tmp,j)==0)
                {
//                    debug(i,j)
                    ans=min(ans,call(bitOn(tmp,j))+dist[i][j]);
                }
            }
        }
    }
    return ret=ans;
}
///http://lbv-pc.blogspot.com/2012/09/jogging-trails.html

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun

    while(~getI(n)&&n)
    {
        getI(m);
        CLR(deg);
        int ans=0;
//        debug(cs)
        rep(i,n)rep(j,n)dist[i][j]=(i==j?0:INF);
        rep(i,m)
        {
            int u,v,w;
            getIII(u,v,w);
            ans+=w;
            deg[u]++;
            deg[v]++;
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=dist[u][v];
        }
        rep(k,n)rep(i,n)rep(j,n)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//        rep(i,n){
//            rep(j,n)printf("%d ",dist[i][j]);
//            puts("");
//        }
        int mask=0;
        rep(i,n)if(deg[i]%2==0)mask=bitOn(mask,i);
//        debug(mask)
//rep(i,n)if(bitCheck(mask,i)==0)debug(i)
        SET(dp);
//        printf("Case %d: %d\n",cs,ans+call(mask));
        printf("%d\n",ans+call(mask));
    }



    return 0;
}


