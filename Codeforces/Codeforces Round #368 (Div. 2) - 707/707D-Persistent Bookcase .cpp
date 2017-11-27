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
#define mx 1000005

int ans[100005],tot;
vector<pair<pii,pii> > v[100005];
bitset<1005> tree[1005],all;
void dfs(int src)
{
    repI(i,v[src].size())
    {
        int pos=v[src][i].ff.ff;
        int type=v[src][i].ff.ss;
        int x=v[src][i].ss.ff;
        int y=v[src][i].ss.ss;
        if(type==1)
        {
            tot-=tree[x].count();
            int val=tree[x][y];
            tree[x][y]=1;
            tot+=tree[x].count();
            ans[pos]=tot;
            dfs(pos);
            tot-=tree[x].count();
            tree[x][y]=val;
            tot+=tree[x].count();
        }
        else if(type==2)
        {
            tot-=tree[x].count();
            int val=tree[x][y];
            tree[x][y]=0;
            tot+=tree[x].count();
            ans[pos]=tot;
            dfs(pos);
            tot-=tree[x].count();
            tree[x][y]=val;
            tot+=tree[x].count();
        }
        else if(type==3)
        {
            tot-=tree[x].count();
            tree[x]^=all;
            tot+=tree[x].count();
            ans[pos]=tot;
            dfs(pos);
            tot-=tree[x].count();
            tree[x]^=all;
            tot+=tree[x].count();
        }
        else
        {
            ans[pos]=tot;
            dfs(pos);
        }
    }
}
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
    WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        rep(i,m)all[i]=1;
        int q;
        getI(q);
        int cur=0;
//    repI(i,)
        rep(i,q)
        {
            int type,x,y;
            getII(type,x);
            if(type==1||type==2)getI(y);
            if(type!=4)
            {
                v[cur].PB(MP(pii(i,type),pii(x,y)));
                cur=i;
            }
            else
            {
                cur=x;
                v[cur].PB(MP(pii(i,type),pii(x,y)));
                cur=i;
            }
        }
        tot=0;
        dfs(0);
        rep(i,q)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}