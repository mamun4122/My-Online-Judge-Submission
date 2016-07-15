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
#define BRIDGENODE 10010
vector<pii>ans;
class BridgeFinding {
    int disc[BRIDGENODE]; ///Discovery time of nodes
    int low[BRIDGENODE]; ///Lowest back edge extension
    int col[BRIDGENODE]; ///Color for marking node

    int cnt; ///Timer
    int cc; ///Color

    void tarjan ( int s, int parentEdge ) {
        disc[s] = low[s] = cnt++;
        col[s] = cc + 1;

        for ( int i = 0; i < adj[s].size(); ++i ) {

            int t = adj[s][i];
            if ( t == parentEdge ) continue; ///Don't use the same edge from parent

            if ( col[t] <= cc ) { ///New node. Discovery.

                tarjan ( t, s );
                low[s]=min(low[s],low[t]); ///Update back edge extension for S

                if ( low[t] > disc[s] ) { ///Back edge of T did not go above S
                    ///This edge is Bridge
                    ans.push_back(pii(min(s,t),max(s,t)));
                }
            }
            else if ( col[t] == cc + 1 ) { ///Back Edge
                low[s]=min(low[s],disc[t]);
            }
        }
    }

public:

    vector< int > adj[BRIDGENODE]; ///Enter target and edge number as pair

    void clear ( int n ) {
        cc += 3; ///cc is now 0. cc+1 is 1
        for (int i = 0; i <= n; i++ ) {
            adj[i].clear();
        }
    }

    void findBridge( int n, int start = 0 ) {
        for ( int i = start; i <= n; i++ ) {
            if ( col[i] <= cc ) {
                tarjan ( i, -1 );
            }
        }
    }
}bridge;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        getI(n);
        bridge.clear(n);
        ans.clear();
        rep(i,n)
        {
            int a,b;
            scanf("%d (%d)",&a,&b);
            rep(j,b)
            {
                int x;
                getI(x);
                bridge.adj[a].push_back(x);
            }
        }
        bridge.findBridge(n-1);
        printf("Case %d:\n",cs);
        printf("%d critical links\n",ans.size());
        sort(ALL(ans));
        repI(i,ans.size())
        {
            printf("%d - %d\n",ans[i].ff,ans[i].ss);
        }


    }



    return 0;
}

