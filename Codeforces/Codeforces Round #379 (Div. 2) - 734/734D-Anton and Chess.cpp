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
map<pii,int>mp;
vector<pii> v;
pii src;
#define bishop 1
#define rook 2
#define queen 3
int call(char x)
{
    if(x=='B')return bishop;
    if(x=='R')return rook;
    return queen;
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        v.clear();mp.clear();
        getII(src.ff,src.ss);
        v.push_back(src);
        rep(i,n)
        {
            getchar();
            char x;int a,b;
            scanf("%c %d %d",&x,&a,&b);
//            debug(x,a,b)
            v.push_back(MP(a,b));
            mp[MP(a,b)]=call(x);
        }
        sort(ALL(v));
        int pos=lower_bound(ALL(v),pii(src))-v.begin();
//        debug(v[pos].ff,v[pos].ss)
        int uplft,uprght,lowlft,lowrght;
        int upore,niche,baye,dane;
        uplft=uprght=lowlft=lowrght=1;
        upore=niche=baye=dane=1;
        int flag=0;
        for(int i=pos-1;i>=0;i--)
        {
            if(flag)break;
            if(v[i].ff==src.ff&&baye)
            {
                if(mp[v[i]]!=bishop)
                {
                    flag=1;
                    break;
                }
                else baye=0;
            }
            if(v[i].ss==src.ss&&upore)
            {
                if(mp[v[i]]!=bishop)
                {
                    flag=1;
                    break;
                }
                else upore=0;
            }
            if(v[i].ss<src.ss&&uplft&&(abs(v[i].ff-src.ff)==abs(v[i].ss-src.ss)))
            {
                if(mp[v[i]]!=rook)
                {
                    flag=1;
                    break;
                }
                else uplft=0;
            }
            if(v[i].ss>src.ss&&uprght&&abs(v[i].ff-src.ff)==abs(v[i].ss-src.ss))
            {
                if(mp[v[i]]!=rook)
                {
                    flag=1;
                    break;
                }
                else uprght=0;
            }
        }
        int sz=v.size();
        for(int i=pos+1;i<sz;i++)
        {
            if(flag)break;
            if(v[i].ff==src.ff&&dane)
            {
                if(mp[v[i]]!=bishop)
                {
                    flag=1;
                    break;
                }
                else dane=0;
            }
            if(v[i].ss==src.ss&&niche)
            {
                if(mp[v[i]]!=bishop)
                {
                    flag=1;
                    break;
                }
                else niche=0;
            }
            if(v[i].ss>src.ss&&lowrght&&abs(v[i].ff-src.ff)==abs(v[i].ss-src.ss))
            {
                if(mp[v[i]]!=rook)
                {
                    flag=1;
                    break;
                }
                else lowrght=0;
            }
            if(v[i].ss<src.ss&&lowlft&&abs(v[i].ff-src.ff)==abs(v[i].ss-src.ss))
            {
                if(mp[v[i]]!=rook)
                {
                    flag=1;
                    break;
                }
                else lowlft=0;

            }
        }

        if(flag)puts("YES");
        else puts("NO");
    }

    return 0;
}