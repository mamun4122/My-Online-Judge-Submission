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
vector<string> v;
int a,b,d;
bool visited[1004][1004],dp[1004][1004];
bool call(int aa,int bb)
{
    if(bb==d)
    {
        repI(i,v.size())printf("%s\n",v[i].c_str());
        puts("success");
        return 1;
    }
    if(visited[aa][bb])return dp[aa][bb];
    visited[aa][bb]=1;
    bool &ret=dp[aa][bb];
    if(aa<a)
    {
        v.push_back("fill A");
        if(call(a,bb))return ret=1;
        v.pop_back();
    }
    if(bb<b)
    {
        v.push_back("fill B");
        if(call(a,bb))return ret=1;
        v.pop_back();
    }
    if(aa)
    {
        v.push_back("empty A");
        if(call(0,bb))return ret=1;
        v.pop_back();
    }
    if(bb)
    {
        v.push_back("empty B");
        if(call(aa,0))return ret=1;
        v.pop_back();
    }
    int mn=min(aa,b-bb);
    if(mn)
    {
        v.push_back("pour A B");
        if(call(aa-mn,bb+mn))return ret=1;
        v.pop_back();
    }
    mn=min(bb,a-aa);
    if(mn)
    {
        v.push_back("pour B A");
        if(call(aa+mn,bb-mn))return ret=1;
        v.pop_back();
    }
    return ret=0;



}



int main() {
    ///check for 0 and negative if limit is not specified

    //READ("in.txt");
    //WRITE("out.txt");
    while(~getIII(a,b,d))
    {
        v.clear();
        CLR(dp);
        CLR(visited);
        call(0,0);
    }




    return 0;
}


