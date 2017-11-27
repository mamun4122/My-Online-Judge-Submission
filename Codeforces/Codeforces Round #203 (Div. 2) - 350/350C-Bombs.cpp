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
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
int on(int n,int pos)
{
    return (n|(1<<pos));
}

int off(int n,int pos)
{
    return (n-(n & (1<<pos)));
}

bool check(int n,int pos)
{
    return (n & (1<<pos));
}
///start coding from here///
int t,n,m;
vector<pii> v;
bool cmp(const pii &a,const pii &b)
{
    if(a.ss==0&&b.ss==0)
    {
        if(a.ff>0&&b.ff>0)return a.ff<b.ff;
        if(a.ff<0&&b.ff<0)return a.ff>b.ff;
        return a.ff<b.ff;
    }
    if(a.ss==0)return true;
    if(b.ss==0)return false;
    if(a.ff==b.ff)
    {
        if(a.ss<0&&b.ss<0)return a.ss>b.ss;
        if(a.ss>0&&b.ss>0)return a.ss<b.ss;
        return a.ss<b.ss;
    }
//
//    if(a.ff==0&&b.ff!=0)return true;
//    if(a.ss==0&&b.ss!=0)return true;
//    if(a.ff==0&&b.ff==0)
//    {
//        if(a.ss<0&&b.ss<0)return a.ss>b.ss;
//        if(a.ss>0&&b.ss>0)return a.ss<b.ss;
//        return a.ss<b.ss;
//    }
//    if(a.ff==b.ff)
//    {
//        return a.ff<b.ff;
//    }
    return a.ff<b.ff;
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    while(~getI(n))
    {
        pii x;
        int ans=0;
        rep(i,n)
        {
            getII(x.ff,x.ss);
            v.push_back(x);
            if(x.ff==0||x.ss==0)
            {
                ans+=2;
            }
            else ans+=4;
            ans+=2;
        }
        printf("%d\n",ans);
        sort(ALL(v),cmp);
        repI(i,n)
        {
            x=v[i];
            if(x.ff!=0)
            {
                printf("%d %d ",1,abs(x.ff));
                if(x.ff<0)puts("L");
                else puts("R");
            }
            if(x.ss!=0)
            {
                printf("%d %d ",1,abs(x.ss));
                if(x.ss<0)puts("D");
                else puts("U");
            }
            puts("2");
            if(x.ss!=0)
            {
                printf("%d %d ",1,abs(x.ss));
                if(x.ss<0)puts("U");
                else puts("D");
            }
            if(x.ff!=0)
            {
                printf("%d %d ",1,abs(x.ff));
                if(x.ff<0)puts("R");
                else puts("L");
            }
            puts("3");
        }
    }





    return 0;
}