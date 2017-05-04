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

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int tot;
vector<int>dig;
int mark[20][2];
pair<ll,ll> dp[20][2];
pair<ll,ll> call(int pos,int flag)
{
    if(pos==tot)return MP(1,0);
    int &vis=mark[pos][flag];
    pair<ll,ll> &ret=dp[pos][flag];
    if(vis)return ret;
    vis=1;
//    if(ret!=-1)return ret;
    ll ans=0,sum=0;
    if(pos==0)
    {
        repI(i,dig[pos]+1)
        {
            ll val=call(pos+1,i==dig[pos]).ff;
            ans+=val;
            sum+=call(pos+1,i==dig[pos]).ss;
            ll tmp=val*i;//*pow(10,tot-pos-1);
            sum+=tmp;
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0; i<=dig[pos]; i++)
            {
                ll val=call(pos+1,i==dig[pos]).ff;
                ans+=val;
                sum+=call(pos+1,i==dig[pos]).ss;
                ll tmp=val*i;//*pow(10,tot-pos-1);
                sum+=tmp;
            }
        }
        else
        {
            repI(i,10)
            {
                ll val=call(pos+1,flag).ff;
                ans+=val;
                sum+=call(pos+1,flag).ss;
                ll tmp=val*i;//*pow(10,tot-pos-1);
                sum+=tmp;
            }
        }
    }
    return ret=MP(ans,sum);
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
//    READ("in.txt");
//    WRITE("out.txt");
    ll a,b;
    while(~getLL(a,b)&&(a||b))
    {
        CLR(mark);
//        SET(dp);
        calc(b);
        ll ans=call(0,0).ss;
//        debug(ans);
        a--;
        CLR(mark);
//        SET(dp);
        calc(a);
        ans-=call(0,0).ss;
        printf("%lld\n",ans);
    }






    return 0;
}
