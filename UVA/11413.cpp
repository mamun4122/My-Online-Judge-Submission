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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mam
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
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
ll arr[1000005];
int n,m;

ll check(ll x)
{
    ll sum=0;
    int i,cnt=0;
    ll mx=-1;
    for(int i=1;i<=n;i++)
    {
        if(sum+arr[i]>x)
        {
            cnt++;
            sum=arr[i];
        }
        else
            sum+=arr[i];
        debug("*",sum)
        mx=max(sum,mx);
    }
    //debug(x,cnt);
    //debug("x",mx)
    cnt++;
    debug(cnt)
    if(cnt>m)return 0;
    return mx;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs;
    while(~getII(n,m))
    {
        ll mx=-1,sum=0;
        rep(i,n){
            getL(arr[i]);
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        ll low=mx,hi=sum,ans=-1;
        while(low<=hi)
        {
            ll mid=low+hi;
            mid/=2;
            debug(low,hi,mid)
            ll tmp=check(mid);
            debug(tmp)
            if(tmp)
            {
                ans=tmp;
                hi=tmp-1;
            }
            else
            {
                low=mid+1;

            }
        }
        printf("%lld\n",ans);

    }




    return 0;
}


