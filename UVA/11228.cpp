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
#define    bitOn(a,k)         (a|(1<<(k)))
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
///****************** template ends here ****************
int t,n,m;
#define mxi 1005
struct edge
{
	int u,v;
	double w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[mxi];
vector<edge>e;
int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
pii ans;
int cnt;
void calc()
{

    rep(i,n)cnt+=(pr[i]==i?1:0);
}
void mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)pr[i]=i;
    double val1=0.0,val2=0.0;
	int count=0;
	int flag=1;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v&&e[i].w+EPS<=(double)m)
		{
			pr[u]=v;
			val1+=e[i].w;
			count++;
			if(count==n-1) break;
		}
		else if(u!=v&&e[i].w>(double)m+EPS)
        {
            if(flag)
            {
                calc();
                flag=0;
            }
            val2+=e[i].w;
            pr[u]=v;
            count++;
            if(count==n-1)break;
        }
	}
	if(flag)calc();
	val1=round(val1);
	val2=round(val2);
	ans=make_pair((int)val1,(int)val2);
}
pii arr[mxi];

inline double Distance( pii a, pii b ) {
	return sqrt( ( a.ff - b.ff ) * ( a.ff - b.ff ) + ( a.ss - b.ss ) * ( a.ss - b.ss ) );
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
//        state.clear();
        e.clear();
        getII(n,m);
        rep(i,n)getII(arr[i].ff,arr[i].ss);
        rep(i,n)
        {
            for(int j=i+1;j<=n;j++)
            {
                edge get;
                get.u=i;get.v=j;
                get.w=Distance(arr[i],arr[j]);
                e.push_back(get);
            }
        }
        cnt=0;
        mst(n);
        printf("Case #%d: %d %d %d\n",cs,cnt,ans.ff,ans.ss);
    }




    return 0;
}
