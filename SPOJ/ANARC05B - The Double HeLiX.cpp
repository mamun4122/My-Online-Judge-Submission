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
int arr1[10010],arr2[10010],pos1[10010],pos2[10010];
ll sum1[10010],sum2[10010];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,n;
    while(getI(n)&&n)
    {
        CLR(arr1);
        CLR(arr2);
        sum1[0]=sum2[0]=0;
        rep(i,n)
        {
            getI(arr1[i]);
            sum1[i]=sum1[i-1]+(ll)arr1[i];
        }
        getI(t);
        rep(i,t)
        {
            getI(arr2[i]);
            sum2[i]=sum2[i-1]+(ll)arr2[i];
        }
        j=1;
        int cnt=1;
        pos1[0]=0;
        pos2[0]=0;

        rep(i,n)
        {
            rep(j,t)
            {
                if(arr1[i]==arr2[j])
                {
                    pos1[cnt]=i;
                    pos2[cnt++]=j;
                    break;

                }
            }
        }
        pos1[cnt]=n;
        pos2[cnt++]=t;
        ll ans=0;
       // debug(cnt)
        rep(i,cnt-1)
        {
            //debug(pos1[i],pos2[i])
            ans+=max(sum1[pos1[i]]-sum1[pos1[i-1]],sum2[pos2[i]]-sum2[pos2[i-1]]);
        }
        printf("%lld\n",ans);


    }




    return 0;
}


