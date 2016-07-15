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
int t,n,m;
struct Point {
    int x, y;
    Point() { x=y=0; }
    Point(int X, int Y) : x(X), y(Y) {}
    bool collinear(const Point &b, const Point &c) const {
//        return (b.y - y) * (c.x - x) == (c.y - y) * (b.x - x);
        return ((b.x-x)*(c.y-y)==(b.y-y)*(c.x-x));
    }
};
Point arr[20];
int dp[(1<<16)+10];
int call(int mask)
{
    if(__builtin_popcount(mask)==n)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    int ans=INF;
    bool mark[20];
    CLR(mark);
    repI(i,n)
    {
        if(bitCheck(mask,i)==0)
        {
            ans=min(ans,call(bitOn(mask,i))+1);
//            int tmp=bitOn(mask,i);
            FOR(j,i+1,n-1)
            {
                if(mark[i])continue;
                if(bitCheck(mask,j)==0)
                {
                    mark[j]=1;
                    int anthr=bitOn(mask,j);
                    anthr=bitOn(anthr,i);
                    FOR(k,j+1,n-1)
                    {
//                        if(bitCheck(tmp,k)==0)
////                        {
                            if(arr[i].collinear(arr[j],arr[k]))
                            {
                                mark[k]=1;
                                anthr=bitOn(anthr,k);
//                                tmp=bitOn(tmp,k);
                            }
//                        }
                    }
                    ans=min(ans,1+call(anthr));
                }
            }
            break;
        }
    }
    return ret=ans;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        getI(n);
        repI(i,n)getII(arr[i].x,arr[i].y);
        SET(dp);
        printf("Case %d: %d\n",cs,call(0));
    }



    return 0;
}

