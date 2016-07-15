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
int dp[400][400];
int arr[400][400];
int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {1,-1,-1,1,2,-2,-2,2};
bool check(pii pos)
{
    if(pos.ff>0&&pos.ff<=n&&pos.ss>0&&pos.ss<=n)return true;
    return false;
}
int dfs(pii src)
{
    int &ret=dp[src.ff][src.ss];
    if(ret!=-1)return ret;
    ret=0;
    repI(i,8)
    {
        pii pos;
        pos.ff=src.ff+dx[i];
        pos.ss=src.ss+dy[i];
        if(check(pos)&&arr[pos.ff][pos.ss]>arr[src.ff][src.ss])
        {
            ret=max(ret,dfs(pos));
        }
    }
    return ret=ret+1;
}
void print(pii src)
{
    printf("%d\n",arr[src.ff][src.ss]);
//    debug(dp[src.ff][src.ss])
    pii nxt=MP(-1,-1);
    repI(i,8)
    {
        pii pos;
        pos.ff=src.ff+dx[i];
        pos.ss=src.ss+dy[i];
        if(check(pos)&&arr[pos.ff][pos.ss]>arr[src.ff][src.ss])
        {
//            debug(dp[pos.ff][pos.ss])
            if(dp[pos.ff][pos.ss]==dp[src.ff][src.ss]-1)
            {
                if(nxt.ff==-1)nxt=pos;
                else if(arr[pos.ff][pos.ss]<arr[nxt.ff][nxt.ss])nxt=pos;
            }
        }
    }
    if(nxt.ff!=-1)print(nxt);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    while(~getI(n))
    {
        SET(dp);
        rep(i,n)rep(j,n)getI(arr[i][j]);
        int res=0;
        pii src;
        src.ff=399;src.ss=399;
        arr[src.ff][src.ss]=366*366;
        rep(i,n)rep(j,n)
        {
            int tmp = dfs(pii(i,j));
            if(tmp>res)
            {
                res=tmp;
                src=MP(i,j);
            }
            else if(res==tmp&&arr[i][j]<arr[src.ff][src.ss])
            {
                src=MP(i,j);
            }
        }
        printf("%d\n",res);
        print(src);

    }



    return 0;
}


