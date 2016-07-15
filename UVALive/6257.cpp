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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

map <string, int> mp;
int dp[50004][4];

string st;
int len;

int call(int pos, string now,int tot)
{
    if(pos==len)
    {
        if(mp[now]==1)return 1;
        return 0;
    }
    if(tot>2)return 0;
    int &ret=dp[pos][tot];
    if(ret!=-1)return ret;
//    debug(now)
    int ans=0;
    if(mp[now]==1)
    {
        ans|=call(pos+1,st.substr(pos,1),1);
    }
    ans|=call(pos+1,now+st[pos],tot+1);
    return  ret=ans;
}

int main() {
    #ifdef mamun
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    mp["h"]=1;
    mp["li"]=1;
    mp["na"]=1;
    mp["k"]=1;
    mp["rb"]=1;
    mp["cs"]=1;
    mp["fr"]=1;
    mp["be"]=1;
    mp["mg"]=1;
    mp["ca"]=1;
    mp["sr"]=1;
    mp["ba"]=1;
    mp["ra"]=1;
    mp["sc"]=1;
    mp["y"]=1;
    mp["ti"]=1;
    mp["zr"]=1;
    mp["hf"]=1;
    mp["rf"]=1;
    mp["v"]=1;
    mp["nb"]=1;
    mp["ta"]=1;
    mp["db"]=1;
    mp["cr"]=1;
    mp["mo"]=1;
    mp["w"]=1;
    mp["sg"]=1;
    mp["mn"]=1;
    mp["tc"]=1;
    mp["re"]=1;
    mp["bh"]=1;
    mp["fe"]=1;
    mp["ru"]=1;
    mp["os"]=1;
    mp["hs"]=1;
    mp["co"]=1;
    mp["rh"]=1;
    mp["ir"]=1;
    mp["mt"]=1;
    mp["ni"]=1;
    mp["pd"]=1;
    mp["pt"]=1;
    mp["ds"]=1;
    mp["cu"]=1;
    mp["ag"]=1;
    mp["au"]=1;
    mp["rg"]=1;
    mp["zn"]=1;
    mp["cd"]=1;
    mp["hg"]=1;
    mp["cn"]=1;
    mp["b"]=1;
    mp["al"]=1;
    mp["ga"]=1;
    mp["in"]=1;
    mp["tl"]=1;
    mp["c"]=1;
    mp["si"]=1;
    mp["ge"]=1;
    mp["sn"]=1;
    mp["pb"]=1;
    mp["fl"]=1;
    mp["n"]=1;
    mp["p"]=1;
    mp["as"]=1;
    mp["sb"]=1;
    mp["bi"]=1;
    mp["o"]=1;
    mp["s"]=1;
    mp["se"]=1;
    mp["te"]=1;
    mp["po"]=1;
    mp["lv"]=1;
    mp["f"]=1;
    mp["cl"]=1;
    mp["br"]=1;
    mp["i"]=1;
    mp["at"]=1;
    mp["he"]=1;
    mp["ne"]=1;
    mp["ar"]=1;
    mp["kr"]=1;
    mp["xe"]=1;
    mp["rn"]=1;
    mp["la"]=1;
    mp["ce"]=1;
    mp["pr"]=1;
    mp["nd"]=1;
    mp["pm"]=1;
    mp["sm"]=1;
    mp["eu"]=1;
    mp["gd"]=1;
    mp["tb"]=1;
    mp["dy"]=1;
    mp["ho"]=1;
    mp["er"]=1;
    mp["tm"]=1;
    mp["yb"]=1;
    mp["lu"]=1;
    mp["ac"]=1;
    mp["th"]=1;
    mp["pa"]=1;
    mp["u"]=1;
    mp["np"]=1;
    mp["pu"]=1;
    mp["am"]=1;
    mp["cm"]=1;
    mp["bk"]=1;
    mp["cf"]=1;
    mp["es"]=1;
    mp["fm"]=1;
    mp["md"]=1;
    mp["no"]=1;
    mp["lr"]=1;

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        SET(dp);
        cin>>st;
//        debug(st)
        len = st.size();
//        debug(st);
        if(call(0,"",0)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}


