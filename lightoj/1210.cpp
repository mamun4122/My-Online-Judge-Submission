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
#define NODE 20005
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> adj[NODE],scc[NODE];
int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;
vector<int> tarjan;
int cycle[NODE];
int ans=0;
vector<int> sccnum;
void SCC ( int s ) {
    vis[s] = GRAY;
    disc[s] = low[s] = globalCnt++;
    tarjan.push_back(s);

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( vis[t] == WHITE ) { ///This is tree edge
            SCC ( t );
            low[s] = min ( low[s], low[t] );
        }
        else if ( vis[t] == GRAY ) { ///This is back edge
            ///Cycle detected
            low[s] = min ( low[s], low[t] );
        }
    }

    if ( disc[s] == low[s] ) {
        ans++;
        sccnum.push_back(s);
        while ( 1 ) {
            int lastNode = tarjan.back();
            cycle[lastNode] = s;
            tarjan.pop_back();
            vis[lastNode] = BLACK;
//            printf("%d ",lastNode);
            if ( lastNode == s ) break;
        }
//        puts("");
    }

}
///call SCC with vis[s]==white
///call shrink with the tot node number
///remember this is 0 indexed
bool shrink(int node)
{
    rep(i,node)
    {
        repI(j,adj[i].size())
        {
            if(cycle[i]!=cycle[adj[i][j]])
            {
                scc[cycle[i]].push_back(cycle[adj[i][j]]);
//                debug(cycle[i],cycle[adj[i][j]])
            }
        }
    }
	///this inserts same edge multiple times
}
int mark[NODE];
stack<int>st;
void dfs1(int src)
{
    mark[src]=1;
    repI(i,scc[src].size())
    {
        int v=scc[src][i];
        if(mark[v]==0)
        {
            dfs1(v);
        }
    }
    st.push(src);
}
int tot,leaf;
set<int>in,out;
void dfs2(int src)
{
    mark[src]=2;
    repI(i,scc[src].size())
    {
        int v=scc[src][i];
        if(mark[v]!=2)
        {
            dfs2(v);
//            break;
        }
    }
    if(scc[src].size()==0)
    {
//        debug(src)
        out.insert(src);
    }

}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        ///clear part
        rep(i,n)
        {
            scc[i].clear();
            adj[i].clear();
        }
        CLR(vis);
        globalCnt=0;
        ans=0;
        sccnum.clear();
        tarjan.clear();
        in.clear();
        out.clear();

        rep(i,m)
        {
            int a,b;
            getII(a,b);
            adj[a].push_back(b);
        }
        rep(i,n)if(vis[i]==WHITE)SCC(i);
        shrink(n);
        CLR(mark);
//        debug("")
//        debug(sccnum.size())
        repI(i,sccnum.size())
        {
            if(mark[sccnum[i]]==0)dfs1(sccnum[i]);
        }
         tot=0;
//        debug(ans,sccnum.size())
        int flag=0;
        leaf=0;
        while(!st.empty())
        {
            if(mark[st.top()]==1)
            {
                dfs2(st.top());
                leaf++;
            }
            st.pop();
        }
//        debug(leaf)
        leaf=max(leaf,(int)out.size());
        if(sccnum.size()==1)leaf=0;
        printf("Case %d: %d\n",cs,leaf);

    }




    return 0;
}
//3
//2
//0
//2
//1

