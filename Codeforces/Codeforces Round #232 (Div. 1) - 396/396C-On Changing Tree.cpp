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
#define mx 300005
ll bit1[mx],bit2[mx];
const int mod=1e9+7;
//inline ll sum(ll num)
//{
////    while(num<0)num+=mod;
//    return num%mod;
//}

void update ( int x, ll val1,ll val2 )
{
    while ( x <= n )
    {
        bit1[x]=(((bit1[x]+val1)%mod)+mod)%mod;
        bit2[x]=(((bit2[x]+val2)%mod)+mod)%mod;
        x += x & (-x);
    }
}
pair<ll,ll> query ( int x )
{
    int res1 = 0,res2=0;
    while ( x )
    {
        res1= (res1+bit1[x])%mod;
        res2=  (res2+bit2[x])%mod;
        x -= x & (-x);
    }
    return MP(res1,res2);
}
ll query1 ( int x )
{
    int res1 = 0,res2=0;
    while ( x )
    {
        res2=  (res2+bit2[x])%mod;
        x -= x & (-x);
    }
    return res2;
}
int lvl[mx],strt[mx],fin[mx],tme;
vector<int> adj[mx];
void dfs(int src,int level)
{
    lvl[src]=level;
    strt[src]=++tme;
    repI(i,adj[src].size())
    {
        int v=adj[src][i];
        dfs(v,level+1);
    }
    fin[src]=tme;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(n);
    {
//        CLR(bit1);CLR(bit2);
//        rep(i,n)adj[i].clear();
        rep(i,n)
        {
            if(i==1)continue;
            getI(m);
            adj[m].PB(i);
        }
        tme=0;
        dfs(1,0);
        getI(m);
//        debug(m)
        rep(i,m)
        {
            int type,v;
            ll x,k;
            getII(type,v);
            if(type==1)
            {
                getLL(x,k);
                ll val=x+(ll)lvl[v]*k;
//                val%=mod;
                update(strt[v],val,k);
                update(fin[v]+1,-val,-k);
            }
            else
            {
                pair<ll,ll> ans=query(strt[v]);
                ll res=ans.ff-ans.ss*lvl[v];//+mod;
//                while(res<0)res+=mod;
//                res%=mod;
                res=((res%mod)+mod)%mod;
                printf("%lld\n",res);
            }
        }

    }


    return 0;
}