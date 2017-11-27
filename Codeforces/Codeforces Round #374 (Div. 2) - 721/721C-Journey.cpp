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
const int INF = 1e9+7;
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
#define    ll  int
#define    ull   unsigned long long

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
#define mx 5005
vector<pii> adj[mx];
stack<int> res;
int dp[mx][mx];
int mark[mx][mx];
int tme,mxi;
//void dfs(int src,int lft,int cnt)
//{
//    if(lft<0)return;
//    if(src==n)
//    {
//        mxi=max(mxi,cnt);
//        return;
//    }
//    repI(i,adj[src].size())
//    {
//        int v=adj[src][i].ff;
//        int cost=adj[src][i].ss;
//        dfs(v,lft-cost,cnt+1);
//    }
//}
int call(int src,int lft)
{
    if(lft<0)return INF;
    if(lft==0)
    {
        if(src==n)return 0;
        return INF;
    }
    if(src==n)
    {
        return INF;
    }
    int &ret=dp[src][lft];
    int &vis=mark[src][lft];
    if(vis==mxi)return ret;
    vis=mxi;
    ret=INF;
    repI(i,adj[src].size())
    {
        int v=adj[src][i].ff;
        ll cost=(ll)call(v,lft-1)+(ll)adj[src][i].ss;
        ret=min((ll)ret,cost);
    }
    return ret;
}
int printans(int src,int lft)
{
    if(lft==0)
    {
        return src==n;
    }
    if(src==n)return false;
    repI(i,adj[src].size())
    {
        int v=adj[src][i].ff;
        int c=adj[src][i].ss;
        if(dp[src][lft]-c==dp[v][lft-1])
        {
            if(printans(v,lft-1))
            {
                res.push(v);
                return true;
            }
        }
    }
    return false;
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
        mxi=1;
    while(~getII(n,m))
    {
        getI(tme);
        rep(i,n)adj[i].clear();
//        SET(dp);
        rep(i,m)
        {
            int u,v,w;
            getIII(u,v,w);
            adj[u].PB(pii(v,w));
        }
        int low=1,high=n-1,ans;
        ll cost;
        mxi++;
        for(ans=n;ans>=0;ans--)
        {
            if(call(1,ans)<=(ll)tme)
            {
                cost=call(1,ans);
//                ans=mid+1;
                break;
            }
        }
        printf("%d\n",ans+1);
//        mxi++;
//        call(1,ans);
        printans(1,ans);
        res.push(1);
        while(!res.empty())
        {
            printf("%d ",res.top());
            res.pop();
        }
        puts("");
    }
    return 0;
}
/**
10
1 2 7 5 8 9 3 6 4 10
**/