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
int t,n,m;
int arr[2005][2005];
ll dp1[2005][2005];
ll dp2[2005][2005];
bool mark1[2005][2005];
bool mark2[2005][2005];
bool vis1[2005][2005];
bool vis2[2005][2005];

ll val;
int dirx1[]= {1,-1};
int diry1[]= {1,-1};
int dirx2[]= {1,-1};
int diry2[]= {-1,1};

bool check(pii src)
{
    if(src.ff>0&&src.ff<=n&&src.ss>0&&src.ss<=n)return true;
    return false;
}
void dfs1(pii src)
{
    if(mark1[src.ff][src.ss])return ;
    val+=(ll)arr[src.ff][src.ss];
    mark1[src.ff][src.ss]=1;
    pii pos;
    repI(i,2)
    {
        pos.ff=src.ff+dirx1[i];
        pos.ss=src.ss+diry1[i];
        if(check(pos))dfs1(pos);
    }

}
void putvaldfs1(pii src)
{
    if(vis1[src.ff][src.ss])return ;
    //val+=(ll)arr[src.ff][src.ss];
    dp1[src.ff][src.ss]=val;
    vis1[src.ff][src.ss]=1;
    pii pos;
    repI(i,2)
    {
        pos.ff=src.ff+dirx1[i];
        pos.ss=src.ss+diry1[i];
        if(check(pos))putvaldfs1(pos);
    }
}
void dfs2(pii src)
{
    if(mark2[src.ff][src.ss])return ;
    val+=(ll)arr[src.ff][src.ss];
    mark2[src.ff][src.ss]=1;
    pii pos;
    repI(i,2)
    {
        pos.ff=src.ff+dirx2[i];
        pos.ss=src.ss+diry2[i];
        if(check(pos))dfs2(pos);
    }

}
void putvaldfs2(pii src)
{
    if(vis2[src.ff][src.ss])return ;
    //val+=(ll)arr[src.ff][src.ss];
    vis2[src.ff][src.ss]=1;
    dp2[src.ff][src.ss]=val;
    pii pos;
    repI(i,2)
    {
        pos.ff=src.ff+dirx2[i];
        pos.ss=src.ss+diry2[i];
        if(check(pos))putvaldfs2(pos);
    }
}

int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    getI(n);
    rep(i,n)
    {
        rep(j,n)
        getI(arr[i][j]);
    }
    CLR(mark1);
    CLR(mark2);
    CLR(vis1);
    CLR(vis2);
    CLR(dp1);
    CLR(dp2);
    rep(i,n)
    {
        rep(j,n)
        {
            if(!mark1[i][j])
            {
                val=0;
                dfs1(make_pair(i,j));
                putvaldfs1(make_pair(i,j));
            }
            if(!mark2[i][j])
            {
                val=0;
                dfs2(make_pair(i,j));
                putvaldfs2(make_pair(i,j));
            }
        }
    }
    ll ans[2];//=-1,ans2=-1;
    SET(ans);
    pii res[2];//,res2;
    rep(i,n)
    {
        rep(j,n)
        {
            int vua=(i+j)%2;
            if(dp1[i][j]+dp2[i][j]-arr[i][j]>ans[vua])
            {
                ans[vua]=dp1[i][j]+dp2[i][j]-arr[i][j];
                res[vua].ff=i;
                res[vua].ss=j;
            }
        }
    }
//    rep(i,n)
//    {
//        rep(j,n)printf("%lld ",dp1[i][j]);
//        puts("");
//    }
//    puts("");
//    rep(i,n)
//    {
//        rep(j,n)printf("%lld ",dp2[i][j]);
//        puts("");
//    }
    printf("%lld\n",ans[0]+ans[1]);
    printf("%d %d %d %d\n",res[0].ff,res[0].ss,res[1].ff,res[1].ss);





    return 0;
}