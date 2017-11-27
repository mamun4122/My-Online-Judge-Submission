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
#define mx 200005

ll bigmod ( ll b, ll p, ll m )
{
    ll res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
#define mod 1000000007
ll biog(ll num)
{
    if(num<0)num+=mod;
    return num%mod;
}
vector<int> adj[mx];
int vis[mx];
stack<int> st;
void dfs(int src)
{
    vis[src]=1;
    repI(i,adj[src].size())
    {
        int v=adj[src][i];
        if(vis[v])continue;
        dfs(v);
    }
    st.push(src);
}

int cnt,cycle,edge;
int strt[mx];
void dfs1(int src,int prev)
{
    strt[src]=cnt++;
    vis[src]=0;
    repI(i,adj[src].size())
    {
        int v=adj[src][i];
//        if(v==prev)continue;
        if(vis[v]==3)
        {
            edge++;
            continue;
        }
        if(vis[v]==0)
        {
//            debug("s",src,v)
            edge++;
            cycle=strt[src]-strt[v]+1;
            continue;
        }
        edge++;
        dfs1(v,src);
    }
    vis[src]=3;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        rep(i,n)adj[i].clear();
        rep(i,n)
        {
            getI(m);
            adj[i].PB(m);
//            adj[m].PB(i);
        }
        CLR(vis);
        CLR(strt);
        rep(i,n)if(vis[i]==0)dfs(i);
        ll ans=1;
//        debug("")
        while(!st.empty())
        {
            int src=st.top();
            st.pop();
            cnt=1;
            cycle=0;
            edge=0;
            if(vis[src]==1)
            {
                dfs1(src,-1);
//                debug(src,edge,cycle)
                ll tot;
                if(cycle)
                {
                    tot=bigmod(2,(ll)cycle,mod);
                    tot-=2;
                    tot=biog(tot);
                    ans=(ans*tot)%mod;
                }
                ll lft=edge-cycle;
                tot=bigmod(2,lft,mod);
                ans=(ans*tot)%mod;
            }
        }
        printf("%lld\n",ans);

    }


    return 0;
}