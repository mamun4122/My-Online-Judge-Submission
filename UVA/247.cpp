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
#define NODE 40
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> adj[NODE];
int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;
vector<int> tarjan;
//int cycle[NODE];
map<string,int> mp;
map<int,string> inv;
int flag;
void SCC ( int s )
{
//    debug(s)
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
//        ans++;
        while ( 1 )
        {
            int lastNode = tarjan.back();
//            debug(lastNode)
//            cycle[lastNode] = s;
            tarjan.pop_back();
            vis[lastNode] = BLACK;
            if(flag)printf(", ");
            flag=1;
            printf("%s",inv[lastNode].c_str());
            if ( lastNode == s ) break;
        }
        puts("");
        flag=0;
    }

}
///call with vis[s]==white

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    int cs=0;
    while(getII(n,m)&&(n||m))
    {
        tarjan.clear();
        globalCnt=1;
        if(cs)puts("");
        cs++;
        mp.clear();
        inv.clear();
        rep(i,n)adj[i].clear();
        string a,b;
        int cnt=1;
        rep(i,m)
        {
            cin>>a>>b;
//            debug(a,b)
            if(mp[a]==0)
            {
                inv[cnt]=a;
                mp[a]=cnt++;
            }
            if(mp[b]==0)
            {
                inv[cnt]=b;
                mp[b]=cnt++;
            }
            adj[mp[a]].push_back(mp[b]);
        }
        CLR(vis);
        printf("Calling circles for data set %d:\n",cs);
        rep(i,n)
        {
            flag=0;
            if(vis[i]==WHITE)SCC(i);
//            puts("");
        }

    }




    return 0;
}

