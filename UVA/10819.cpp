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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
int t,n,m;
int dp[13000][120];//[120];
vector<pii>v;

int call(int pos,int sum)
{
    if(sum>n&&n<1800)return -2000;
    if(sum>n+200)return -2000;
    if(pos==m)
    {
        if(sum>n&&sum<=2000)return -2000;
        return 0;
    }
    int &ret=dp[sum][pos];
    if(ret!=-1)return ret;
    int ans=0;
//    if(sum+v[pos].ff<=n+200)
    ans=v[pos].ss+call(pos+1,sum+v[pos].ff);
    ans=max(ans,call(pos+1,sum));
    return ret=ans;
}

int main() {
//    READ("in.txt");
//    WRITE("out.txt");
    while(~getII(n,m))
    {
        v.clear();
        SET(dp);
        pii x;
//        if(n>=2000)n+=200;
        rep(i,m)
        {
            getII(x.ff,x.ss);
            v.push_back(x);
        }
        printf("%d\n",call(0,0));
//        rep(i,n)dp[0][i]=0;
//        rep(i,m)dp[i][0]=0;
//        dp[0][0]=0;
//        rep(i,m)
//        {
//            repI(j,v[i-1].ff)dp[i][j]=dp[i-1][j];
//            for(int j=v[i-1].ff;j<=n;j++)
//            {
//                dp[i][j]=max(dp[i-1][j],v[i-1].ss+dp[i-1][j-v[i-1].ff]);
//            }
////            debug(dp[i][n])
//        }
////        rep(i,m)
////        {
////            rep(j,n)printf("%d ",dp[i][j]);
////            puts("");
////        }
//        printf("%d\n",dp[m][n]);
    }




    return 0;
}

