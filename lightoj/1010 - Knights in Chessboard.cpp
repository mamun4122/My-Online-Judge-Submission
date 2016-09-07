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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double



const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

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



int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        printf("Case %d: ",cs);
        if(n==1||m==1)printf("%d\n",n==1?m:n);
        else if(n==2||m==2)
        {
            int ans=0;
            int mx=(n==2?m:n);
            rep(i,mx)
            {
                if(i%4==1||i%4==2)ans+=2;
            }
            printf("%d\n",ans);
        }
        else
        {
            printf("%d\n",(int)ceil(((double)n*m)/2));
        }
    }



    return 0;
}
// First Category: If either m or n was 1 we were dealing with a long skinny
// board in which no knights could attack each other so it was fair to populate
// each cell. In the code I check if either m or n is one and if so I output MAX(m,n)

// Second Category: If either m or n was 2 the maximum number of knights followed
// a specific pattern that the maximum number of knights to be as many 2x2 groups
// of knights that could be fit onto the board given that they were separated by
// 2x2 groups of spaces and an extra 2 of after all 2x2 groups of knights were
// placed there existed still a 2x1 space above the separating 2x2 blanks.
// See captivating visualization below:

// K K O O K K O O K       For a 2x9 board 10 is the maximum
// K K O O K K O O K

// A Mathematical representation is seen below in the code.

// Third Category: If the n and m didnt fit any of the other categories
// the answer seeemed to always be rows * columns + 1) / 2
