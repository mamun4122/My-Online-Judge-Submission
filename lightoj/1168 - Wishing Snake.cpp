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
#define    bitOn(a,k)         (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
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
#define NODE 20005
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> adj[NODE],scc[NODE];
int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;
bool deg[NODE];
bool mark[NODE];

vector<int> tarjan;

int cycle[NODE];
int ans=0;
int tot;
int mp[NODE];
void Clear()
{
    tot=0;
    CLR(mark);
    CLR(deg);
    repI(i,NODE)adj[i].clear();
    repI(i,NODE)scc[i].clear();
    CLR(disc);
    CLR(low);
    CLR(vis);
    globalCnt=0;
    CLR(cycle);
    SET(mp);
    ans=0;
    tarjan.clear();

}

void SCC ( int s )
{
    vis[s] = GRAY;
    disc[s] = low[s] = globalCnt++;
    tarjan.push_back(s);

    for ( int i = 0; i < adj[s].size(); i++ )
    {
        int t = adj[s][i];

        if ( vis[t] == WHITE )   ///This is tree edge
        {
            SCC ( t );
            low[s] = min ( low[s], low[t] );
        }
        else if ( vis[t] == GRAY )   ///This is back edge
        {
            ///Cycle detected
            low[s] = min ( low[s], low[t] );
        }
    }

    if ( disc[s] == low[s] )
    {
        ans++;
        while ( 1 )
        {
            int lastNode = tarjan.back();

            cycle[lastNode] = s;
            tarjan.pop_back();
            vis[lastNode] = BLACK;
            if ( lastNode == s ) break;
        }
    }

}
///call with vis[s]==white
bool shrink(int node)
{
    repI(i,node)
    {
        repI(j,adj[i].size())
        {
            if(cycle[i]!=cycle[adj[i][j]])
            {
                if(deg[cycle[i]])return false;
                deg[cycle[i]]=true;
                scc[cycle[i]].push_back(cycle[adj[i][j]]);
            }
        }
    }
//    debug("");
    return true;
    ///this inserts same edge multiple times

}
bool flag;
int cnt;
void dfs(int src)
{
    cnt++;
    mark[src]=1;
    if(scc[src].size()>1)
    {
        flag=0;
        return;
    }
    repI(i,scc[src].size())
    {
        int v=scc[src][i];
        dfs(v);
        break;
    }
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        Clear();
        getI(n);
        cnt=0;
        rep(i,n)
        {
            getI(m);
            rep(j,m)
            {
                int a,b;
                getII(a,b);
                if(mp[a]==-1)mp[a]=cnt++;
                if(mp[b]==-1)mp[b]=cnt++;
                adj[mp[a]].push_back(mp[b]);
            }
        }
        repI(i,cnt)if(vis[i]==WHITE)SCC(i);
        flag=shrink(cnt);
        if(mp[0]==-1&&cnt!=0)flag=false;
//        debug(flag)
        CLR(mark);
        cnt=0;
        if(flag&&mp[0]!=-1)dfs(cycle[mp[0]]);
        if(cnt!=ans)flag=false;
        printf("Case %d: ",cs);
        if(flag)printf("YES");
        else printf("NO");
        puts("");
    }




    return 0;
}

