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
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define repI(i,n) for( i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************
#define MAX 10050
// result[i] will contain true if the ith node is an articulation
int deg[MAX], n, visited[MAX], assignedVal;
vector<int> adj[MAX];
bool result[MAX];
int articulation( int u, int depth ) {
	if( visited[u] > 0 ) return visited[u];
	visited[u] = ++assignedVal;
	int mn = visited[u], rootCalled = 0;
	for(int i = 0; i < deg[u]; i++) {
		int v = adj[u][i];
		if( !visited[v] ) {
			if( !depth ) rootCalled++;
			int k = articulation( v, depth + 1 );
			if( k >= visited[u] ) result[u] = true;
		}
		mn = min( mn, visited[v] );
	}
	if( !depth ) result[u] = ( rootCalled >= 2 );
	return visited[u] = mn;
}
void processArticulation() {
	assignedVal = 0;
	memset( result, 0, sizeof( result ) );
	memset( visited, 0, sizeof( visited ) );
	for( int i = 0; i < n; i++ ) if( !visited[i] ) articulation( i, 0 );
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,m;
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        repI(i,n)adj[i].clear();
        int x,y;
        CLR(deg);
        rep(i,m)
        {
            getII(x,y);
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            deg[x]++;deg[y]++;
        }
        processArticulation();
        int ans=0;
        repI(i,n)if(result[i])ans++;
        printf("Case %d: %d\n",cs,ans);


    }




    return 0;
}


