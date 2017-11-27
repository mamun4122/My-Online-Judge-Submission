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
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

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
    map<char,int> white,black;
    white['Q']=9;
    white['R']=5;
    white['B']=3;
    white['N']=3;
    white['P']=1;
    white['K']=0;
    white['.']=0;
    white['q']=0;
    white['r']=0;
    white['b']=0;
    white['n']=0;
    white['p']=0;
    white['k']=0;
    black['Q']=0;
    black['R']=0;
    black['B']=0;
    black['N']=0;
    black['P']=0;
    black['K']=0;
    black['.']=0;
    black['q']=9;
    black['r']=5;
    black['b']=3;
    black['n']=3;
    black['p']=1;
    black['k']=0;
    char c;
    int ans1=0,ans2=0;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
           cin>>c;
           ans1+=white[c];
           ans2+=black[c];
        }
        getchar();
    }
    if(ans1>ans2)
        printf("White\n");
    else if(ans1<ans2)
        printf("Black\n");
    else
        printf("Draw\n");

    return 0;
}