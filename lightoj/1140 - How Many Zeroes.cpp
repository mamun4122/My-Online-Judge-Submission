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
int tot;
vector<int>dig;
ll dp[20][2][200][2];
ll call(int pos,int flag,int sum,int strt)
{
    if(pos==tot)return sum;
    ll &ret=dp[pos][flag][sum][strt];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig[pos]+1)
        {
            ans+=call(pos+1,i==dig[pos],sum+(i==0&&strt),(strt||i!=0));
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0;i<=dig[pos];i++)
            {
                ans+=call(pos+1,i==dig[pos],sum+(i==0&&strt),(strt||i!=0));
            }
        }
        else
        {
            repI(i,10)
                ans+=call(pos+1,0,sum+(i==0&&strt),(strt||i!=0));
        }
    }
    return ret=ans;
}
void calc(ll num)
{
    dig.clear();
    while(num)
    {
        dig.push_back(num%10);
        num/=10;
    }
    reverse(ALL(dig));
    tot=dig.size();
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    getI(t);
    rep(cs,t)
    {
        SET(dp);
        ll a,b;
        getL(a);
        getL(b);
        a--;
        ll ansa,ansb;
        if(a<0)ansa=0;
        else if(a<10)ansa=1;
        else
        {
            calc(a);
            ansa=call(0,0,0,0)+1;
        }
        SET(dp);
        calc(b);
        ansb=call(0,0,0,0)+1;
       // debug(ansa,ansb)
        printf("Case %d: %lld\n",cs,ansb-ansa);
    }




    return 0;
}

