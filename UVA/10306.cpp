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
int t,n,m;
int dp[305][305];
pii v[50];
int flag,tmp;
int call(int pos,int x,int y)
{
    //debug(pos,x,y)
    if(x*x+y*y>m)
    {
        tmp=1;
        return 20000;
    }
//    if(x*x+y*y==m)
//    {
//        flag=true;
//        return 0;
//    }
    if(pos==n)
    {
        if(x*x+y*y==m)
        {
            flag=true;
            return 0;
        }
        return 20000;
    }
    int &ret=dp[x][y];
    if(ret!=-1)return ret;
    int ans=INF;
    for(int i=0;;i++)
    {
        tmp=0;
//        if(i*i*v[pos].ff*v[pos].ff+i*v[pos].ss*i*v[pos].ss>m)break;
        ans=min(ans,i+call(pos+1,x+i*v[pos].ff,y+i*v[pos].ss));
        if(tmp)
        {
            tmp=0;
            break;
        }
    }
    return ret=ans;
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        flag=false;
        tmp=0;
        getII(n,m);
        m*=m;
//        debug(m)
        repI(i,n)getII(v[i].ff,v[i].ss);
        SET(dp);
        int ans=call(0,0,0);
        if(flag)
        printf("%d\n",ans);
        else puts("not possible");

    }



    return 0;
}

