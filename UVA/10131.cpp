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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
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
pair<pii,int> arr[1005];

int dp[1010][1010];
int mark[1005][1005];//,mark2[1005];
//queue<int>q;
bool cmp(const pair<pii,int> &a,const pair<pii,int> &b)
{
    if(a.ff.ff<b.ff.ff)return true;
    if(a.ff.ff==b.ff.ff)return a.ff.ss>b.ff.ss;
    return false;
}
int call(int pos,int prev)
{
    if(pos==n)return 0;
    int &ret=dp[pos][prev];
    if(ret!=-1)return ret;
    int val1=-1,val2;
    val2=call(pos+1,prev);
    if(arr[pos].ff.ff>arr[prev].ff.ff&&arr[pos].ff.ss<arr[prev].ff.ss)
        val1=call(pos+1,pos)+1;
    if(val1>val2)mark[pos][prev]=1;
    return ret=max(val1,val2);
}
void print(int pos,int prev)
{
    if(pos==n)return;
    if(mark[pos][prev])
    {
        printf("%d\n",arr[pos].ss);
//        debug(arr[pos].ff.ff,arr[pos].ff.ss)
        print(pos+1,pos);
    }
    else print(pos+1,prev);
}
int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    int pos=1;
    while(~getII(arr[pos].ff.ff,arr[pos].ff.ss))
    {
        arr[pos].ss=pos;pos++;
    }
    n=pos;
    arr[0].ff.ff=-1;arr[0].ff.ss=INF;arr[0].ss=0;
    sort(arr,arr+n,cmp);
    SET(dp);CLR(mark);
    int ans=call(1,0);
    printf("%d\n",ans);
    print(1,0);




    return 0;
}


