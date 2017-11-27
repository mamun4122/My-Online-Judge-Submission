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
int t,n,m;
string a,b;

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    cin>>a>>b;
    int flag1=1,flag2=1,cnt1=0,cnt2=0;
    repI(i,a.size())
    {
        if(a[i]=='0')cnt1++;
        else
        {
            flag1=0;break;
        }
    }
    repI(i,b.size())
    {
        if(b[i]=='0')cnt2++;
        else
        {
            flag2=0;break;
        }
    }
    if(flag1&&flag2)puts("=");
    else if(flag1)puts("<");
    else if(flag2)puts(">");
    else
    {
        int val1=a.size()-cnt1,val2=b.size()-cnt2;
        if(val1>val2)
        {
            puts(">");
            return 0;
        }
        else if(val1<val2)
        {
            puts("<");
            return 0;
        }
        for(;cnt1<a.size()&&cnt2<b.size();cnt1++,cnt2++)
        {
            if(a[cnt1]>b[cnt2])
            {
                puts(">");
                return 0;
            }
            else if(a[cnt1]<b[cnt2])
            {
                puts("<");
                return 0;
            }
        }
        if(cnt1==a.size()&&cnt2==b.size())
        {
            puts("=");
            return 0;
        }
        if(cnt1==a.size())
        {
            puts("<");
            return 0;
        }
        puts(">");
    }
    return 0;
}