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
int parent[505][505];
int sparse[505][505][25];
int height;
void build_sparse(int N)
{
    CLR(sparse);
    repI(i,N)repI(j,N)sparse[i][j][0] = parent[i][j];
    for (int dep = 1; (1 << dep) <= N; dep++)
    {
        repI(row,N)
        {
            height=dep;
            int prev=1<<(dep-1);
            int rr=row+prev;
            rr=min(rr,n-1);
            repI(col,N)
            {
                int cc=col+prev;
                cc=min(cc,n-1);
                sparse[row][col][dep]=max(sparse[row][col][dep-1],sparse[row][cc][dep-1]);
                sparse[row][col][dep]=max(sparse[row][col][dep],sparse[rr][col][dep-1]);
                sparse[row][col][dep]=max(sparse[row][col][dep],sparse[rr][cc][dep-1]);
            }
        }
    }
    height++;
}
int rmq(int i,int j,int k)
{
    int len=k;
    int dep=height;
    int scnd=pow(2,height);
    while(scnd>len)
    {
        scnd/=2;
        dep--;
    }
//    debug(scnd,dep,log2(k),i,j)
    int res=max(sparse[i][j][dep],sparse[min(n-1,i+k-scnd)][j][dep]);
    res=max(res,sparse[i][min(n-1,j+k-scnd)][dep]);
    res=max(res,sparse[min(n-1,i+k-scnd)][min(n-1,j+k-scnd)][dep]);
    return res;
}
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in1.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        repI(i,n)repI(j,n)getI(parent[i][j]);
        build_sparse(n);
//        debug(height);
//        repI(k,height)
//        {
//            debug(k)
//            repI(i,n)
//            {
//                repI(j,n)
//                {
//                    printf("%d ",sparse[i][j][k]);
//                }
//                puts("");
//            }
//            puts("");
//            puts("");
//        }
        printf("Case %d:\n",cs);
        rep(i,m)
        {
            int x,y,z;
            getIII(x,y,z);
            x--;y--;
            printf("%d\n",rmq(x,y,z));
        }
    }


    return 0;
}


