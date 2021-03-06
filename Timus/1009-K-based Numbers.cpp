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
vector<int> dig;
int tot;
ll dp[200][3];

ll call(int pos,int zeroallow)
{
//    debug(pos)
    if(pos==tot)return 1;
    ll &ret=dp[pos][zeroallow];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        rep(i,dig[pos])
        {
            ans+=call(pos+1,i==0?0:1);
        }
    }
    else
    {
//        if(flag)
//        {
            repI(i,dig[pos]+1)
            {
                if(!zeroallow&&!i)continue;
                ans+=call(pos+1,i==0?0:1);
            }
//        }
//        else
//        {
//            repI(i,10)
//            {
//
//                if(!zeroallow&&!i)continue;
//                ans+=call(pos+1,0,i==0?0:1);
//            }
//        }
    }
    return ret=ans;
}

ll calc(int n,int base)
{
    SET(dp);
    dig.clear();
//    while(num)
//    {
//        dig.push_back(num%base);
//        num/=base;
//    }
    rep(i,n)dig.push_back(base-1);
    tot=dig.size();
    //reverse(ALL(dig));
//    debug("m")
    ll ans=call(0,0);
//    debug(tot,ans)
    return ans;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    while(~getII(n,m))
    {
//        ll num=0;
//        rep(i,n)
//        {
//            num*=10;
//            num+=9;
//        }
        cout<<calc(n,m)<<endl;
    }



    return 0;
}

