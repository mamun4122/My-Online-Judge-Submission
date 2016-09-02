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
const int INF = 10000000;
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
int dp1[105][105][105],dp2[105][105][105];
int mark1[105][105][105],mark2[105][105][105];
int cc;
int arr[105][105];

int call1(int x,int y,int lft)
{
    if(lft==0)return 0;
    if(x==n||y==m)
    {
        return INF;
    }
    int &vis=mark1[x][y][lft];
    int &ret=dp1[x][y][lft];
    if(vis==cc)return ret;
    vis=cc;
    int ans=INF;
    ans=min(ans,call1(x+1,y,lft));
    ans=min(ans,call1(x,y+1,lft));
    ans=min(ans,call1(x+1,y+1,lft-1)+arr[x][y]);
    return ret=ans;
}
int call2(int x,int y,int lft)
{
    if(lft==0)return 0;
    if(x==n||y==m)
    {
        return -INF;
    }
    int &vis=mark2[x][y][lft];
    int &ret=dp2[x][y][lft];
    if(vis==cc)return ret;
    vis=cc;
    int ans=-INF;
    ans=max(ans,call2(x+1,y,lft));
    ans=max(ans,call2(x,y+1,lft));
    ans=max(ans,call2(x+1,y+1,lft-1)+arr[x][y]);
    return ret=ans;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    cc=1;
    CLR(mark1);
    CLR(mark2);
    rep(cs,t)
    {
        cc++;
        getII(n,m);
        repI(i,n)repI(j,m)getI(arr[i][j]);
        int ans=0;
        for(int i=1;2*i<=min(n,m);i++)
        {
            int nourish=call1(0,0,2*i);
            int dhorbo=call2(0,0,i);
//            debug(nourish,dhorbo)
            int tot=dhorbo-nourish;
            ans=max(ans,tot);
        }
        printf("%d\n",ans);
    }

    return 0;
}

