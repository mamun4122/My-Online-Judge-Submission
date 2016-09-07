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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
int t,n,m,k;
int mark[1005];
#define mod 1000000007
ll ncr[1005][1005];
ll fact[1005];

void ncrcalc()
{
    ncr[0][0] = 1 ;
    int limncr = 1000 ;
    for (int i = 1 ; i <= limncr ; i++)
        for (int j = 0 ; j <= limncr ; j++)
        {
            if ( j > i ) ncr[i][j] = 0 ;
            else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
            else ncr [i][j] = (ncr[i-1][j - 1]%mod + ncr[i-1][j]%mod)%mod ;
        }
}

//ll call(int pos,int same)
//{
////    debug(pos,same)
//    if(pos>=m&&same!=k)return 0;
//    if(same==k&&pos==m)
//    {
////        debug(fact[n-pos])
//        return fact[n-pos];
//    }
//    ll &ret=dp[pos][same];
////    if(ret!=-1)return ret;
//    ll ans=0;
//    rep(i,n)
//    {
//        if(mark[i])continue;
//        mark[i]=1;
//        ans+=call(pos+1,(int)(i==pos+1)+same);
//        mark[i]=0;
//    }
//    return ret=ans;
//}
ll modulas(ll num)
{
    while(num<=0)num+=mod;
    return num%mod;
}

ll call()
{
    ll ans=ncr[m][k];
    ll res=fact[n-k];
    ll gun=-1;
    rep(i,m-k)
    {
//        res=(res%mod+(gun*((ncr[m-k][i]%mod)*(fact[n-k-i])%mod)%mod))%mod;
        res=modulas(modulas(res)+modulas((gun*((ncr[m-k][i]%mod)*(fact[n-k-i])%mod)%mod)));
        gun*=-1;
    }
    return ((ans%mod)*(res%mod))%mod;
}

int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    ncrcalc();
    fact[0]=1;
    rep(i,1000)
    {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;

    }

//    debug("mam")
    rep(cs,t)
    {
//        SET(dp);
        CLR(mark);
        getIII(n,m,k);
        printf("Case %d: %lld\n",cs,call());

    }





    return 0;
}
//Case 1: 596109592
//Case 2: 926183230
//Case 3: 253491038
//Case 4: 62400933
//Case 1: 220
//Case 2: 540298380
//Case 3: 868455893
