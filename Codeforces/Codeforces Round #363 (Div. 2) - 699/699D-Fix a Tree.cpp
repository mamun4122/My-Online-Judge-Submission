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

vector<int> adj[200005];
int par[200005];
int mark[200005],col[200005];
vector<int> v;
vector<int> org;
int cnt=0;
void dfs(int src,int par)
{
    mark[src]=1;
    repI(i,adj[src].size())
    {
        int vv=adj[src][i];
        if(vv==par)continue;
        if(vv==src)
        {
            if(col[vv]==0)
            {
                col[vv]=1;
                org.push_back(vv);
            }
            continue;
        }
        if(mark[vv]==0)
        {
            dfs(vv,src);
        }
        else
        {
            if(col[vv]==0&&col[src]==0)
            {
                v.push_back(vv);
                col[vv]=1;
            }
        }
    }
}
vector<int> fin;

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    while(~getI(n))
    {
        CLR(mark);
        CLR(col);
        rep(i,n)adj[i].clear();
        v.clear();
        SET(par);
        org.clear();

        rep(i,n)
        {
            getI(m);
            adj[i].push_back(m);
            adj[m].push_back(i);
            par[i]=m;
        }

        int tot=0;
        rep(i,n)
        {
            if(mark[i]==0)
            {
                dfs(i,-1);
//                debug(i,org.size())
//                repI(j,org.size())debug(org[j])
            }
        }
//        debug(org.size(),v.size())
        if(org.size()==0)
        {
            repI(i,v.size())
            {
                tot++;
                if(!i)par[v[i]]=v[i];
                else par[v[i]]=v[i-1];
            }
        }
        else
        {
            repI(i,v.size())
            {
                tot++;
                par[v[i]]=org[0];
            }
            repI(i,org.size())if(i)
            {
                tot++;
                par[org[i]]=org[0];
            }
        }
        printf("%d\n",tot);
        rep(i,n)printf("%d ",par[i]);
        puts("");

    }



    return 0;
}