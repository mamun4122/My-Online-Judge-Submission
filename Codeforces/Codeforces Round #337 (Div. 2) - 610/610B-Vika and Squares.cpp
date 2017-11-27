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
int t,n,m;
int arr[200005];
vector<int>zero;

int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    while(~getI(n))
    {
        int mn=INF;
        rep(i,n)
        {
            getI(arr[i]);
            mn=min(arr[i],mn);
        }
        ll ans=0;
        ans+=(ll)mn*n;
        rep(i,n)arr[i]-=mn;
        int pos1,pos2;
        rep(i,n)
        {
            if(arr[i]==0)zero.push_back(i);
        }
//        for(int i=n;i>0;i--)
//        {
//            if(arr[i]==0)
//            {
//                pos2=i;
//            }
//
//            if(arr[i]==0)break;
//
//        }
        int mx=-INF;
        sort(ALL(zero));
        if(zero.size()==1)
        {
            mx=zero[0]-1;
            mx+=n-zero[0];
//            debug(mx)

        }
        else
        {
            repI(i,zero.size())
            {
                if(i==0)continue;
                mx=max(mx,zero[i]-zero[i-1]-1);
            }
            mx=max(mx,n-zero[zero.size()-1]+zero[0]-1);
        }

//        ans+=n-pos2;
//        ans+=pos1-1;
        cout<<ans+mx<<endl;
    }




    return 0;
}