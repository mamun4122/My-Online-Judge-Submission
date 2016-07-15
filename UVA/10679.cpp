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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}



//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************


const int MM = 100005, NN = 1005;	// MM - long string length, NN – small string length
const int MAXCHAR = 52, MAX = 200000;	// MAXCHAR maximum characters, MAX maximum nodes
char T[MM], a[NN][NN];					// Long string T, small strings a[]
int val( char ch )
{
    if( ch >= 'a' ) return ch - 97;
    else return ch - 39;
}
struct Trie
{
    int N;				// Contains the number of nodes of the Trie
    struct node
    {
        int edge[MAXCHAR], f;	// The alphabets, f failure function
        bool out; // out function, gives the set of patterns recognized entering this state
        void clear()  			// Clears the node
        {
            memset( edge, -1, sizeof( edge ) );
            f = out = false;
        }
    } P[MAX];
    void clear()  		// Clears the Trie, Initially g( 0, x ) = 0, for all x
    {
        N = 1;
        P[0].clear();
        memset( P[0].edge, 0, sizeof( P[0].edge ) );
    }
    void insert( char *a )  			// Inserts an element into the trie
    {
        int p = 0, i, k;
        for( i = 0; a[i]; i++ )
        {
            k = val( a[i] );
            if( P[p].edge[k] <= 0 )  	// Edge is not available
            {
                P[p].edge[k] = N;
                P[N++].clear();			// Clear the edge, and increase N
            }
            p = P[p].edge[k];			// Go to the next edge
        }
        P[p].out = true;
    }
    void computeFailure()  				// Computes the failure function
    {
        int i, u, v, w;
        queue <int> Q;
        for( i = 0; i < MAXCHAR; i++ ) if( P[0].edge[i] )
            {
                u = P[0].edge[i];
                P[u].f = 0;
                Q.push(u);
            }
        while( !Q.empty() )
        {
            u = Q.front();
            Q.pop();
            for( i = 0; i < MAXCHAR; i++ ) if( P[u].edge[i] != -1 )
                {
                    v = P[u].edge[i];
                    Q.push(v);
                    w = P[u].f;
                    while( P[w].edge[i] == -1 ) w = P[w].f;
                    w = P[v].f = P[w].edge[i];
                    P[v].out |= P[w].out;
                }
        }
    }
} A;
int n, cases;
bool mark[MAX];
void AhoCorasick( Trie &A, char *T )  // Finds the occurences of strings in the trie, in T
{
    int i, q = 0, k; // q Initial State
    for( i = 0; i < A.N; i++ ) mark[i] = false;
    for( i = 0; T[i]; i++ )
    {
        k = val( T[i] );
        while( A.P[q].edge[k] == -1 ) q = A.P[q].f;
        q = A.P[q].edge[k];
        int x = q;
        if( A.P[x].out && !mark[x] )
        {
            mark[x] = true;
            x = A.P[x].f;
        }
    }
}
bool exists( Trie &A, char *a )
{
    int i, q = 0, k;
    for( i = 0; a[i]; i++ )
    {
        k = val(a[i]);
        q = A.P[q].edge[k];
    }
    return mark[q];
}
int main()
{
    int t;
    getI(t);
    int cs;
    rep(cs,t)
    {
        scanf("%s %d", T, &n);
        A.clear();
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", a[i]);
            A.insert( a[i] );
        }
        A.computeFailure();
        AhoCorasick( A, T );
        for( int i = 0; i < n; i++ )
        {
            if( exists( A, a[i] ) ) puts("y");
            else puts("n");
        }
    }
    return 0;
}

