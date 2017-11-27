#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
int tot1,tot2;
vector<int>dig1,dig2,dig;
ll dp[20][2][(1<<8)+4];
ll dp1[20][2][(1<<8)+4];
ll call2(int pos,int flag,int mask)
{
//    debug(pos)
    if(pos==tot2)
    {
//        debug(mask)
        return 1;
    }
    ll &ret=dp1[pos][flag][mask];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig2[pos]+1)
        {
            if(bitCheck(mask,i)==0)
            {
//                debug("v",i)
                ans+=call2(pos+1,i==dig2[pos],bitOn(mask,i));
            }
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0;i<=dig2[pos];i++)
            {
                if(bitCheck(mask,i)==0)
                    ans+=call2(pos+1,i==dig2[pos],bitOn(mask,i));
            }
        }
        else
        {
            repI(i,7)
                if(bitCheck(mask,i)==0)
                    ans+=call2(pos+1,0,bitOn(mask,i));
        }
    }
    return ret=ans;
}

ll call1(int pos,int flag,int mask)
{
//    debug(pos)
    if(pos==tot1)
    {
//        debug("a",mask);
        return call2(0,flag,mask);
    }
    ll &ret=dp[pos][flag][mask];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig1[pos]+1)
        {
            if(bitCheck(mask,i)==0)
                ans+=call1(pos+1,i==dig1[pos],bitOn(mask,i));
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0;i<=dig1[pos];i++)
            {
                if(bitCheck(mask,i)==0)
                    ans+=call1(pos+1,i==dig1[pos],bitOn(mask,i));
            }
        }
        else
        {
            repI(i,7)
                if(bitCheck(mask,i)==0)
                    ans+=call1(pos+1,0,bitOn(mask,i));
        }
    }
    return ret=ans;
}

void calc(int n,int m)
{
    dig1.clear();dig2.clear();
    if(!n)dig1.push_back(n);
    while(n)
    {
        dig1.push_back(n%7);
        n/=7;
    }
    reverse(ALL(dig1));
    n=m;
    if(!n)dig2.push_back(n);
    while(n)
    {
        dig2.push_back(n%7);
        n/=7;
    }
    reverse(ALL(dig2));
//    dig.clear();
//    repI(i,dig1.size())dig.push_back(dig1[i]);
//    repI(i,dig2.size())dig.push_back(dig2[i]);
    tot1=dig1.size();
    tot2=dig2.size();
//    debug(tot1,tot2)
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    while(~getII(n,m))
    {
        n--;m--;
        calc(n,m);
        SET(dp);
        SET(dp1);
        printf("%lld\n",call1(0,0,0));
    }



    return 0;
}