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

struct point{
    int x,pos;
};

bool cmp(const point &a,const point&b)
{
    if(a.x<b.x)return true;
    else if(a.x==b.x)return a.pos<b.pos;
    return false;
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    vector<point>v;
    int n;
    getI(n);
    int maxi[n+1],mini[n+1];
    point val;
    for(int i=1;i<=n;i++)
    {
        getI(val.x);val.pos=i;
        v.push_back(val);
    }
    sort(ALL(v),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(i>0&&i<n-1)
        mini[v[i].pos]=min(abs(v[i].x-v[i+1].x),abs(v[i].x-v[i-1].x));
        else if(i==0)
            mini[v[i].pos]=abs(v[i].x-v[i+1].x);
        else
            mini[v[i].pos]=abs(v[i].x-v[i-1].x);
        maxi[v[i].pos]=max(abs(v[i].x-v[0].x),abs(v[i].x-v[n-1].x));
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",mini[i],maxi[i]);
    }
    return 0;
}