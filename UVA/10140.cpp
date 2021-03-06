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
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
//******************DELETE****************
int t,n,m;
#define M 1000005
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    int i;
    for ( i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    while(i<=n)
    {
        if(marked[i]==0)primes.push_back(i);
        i+=2;
    }
}

#define SIZE 1000005
int arr[SIZE];

struct data
{
    ll a,b,dif;
    data()
    {
        ;
    }
    data(ll aa,ll bb,ll cc)
    {
        a=aa;
        b=bb;
        dif=cc;
    }
} first,last;

///Returns number of primes between segment [a,b]

void segmentedSieve ( ll a, ll b )
{
    if ( a == 1 ) a++;

    ll sqrtn = sqrt ( b );

    memset ( arr, 0, sizeof(arr) ); ///Make all index of arr 0.
//    debug("")
    for ( int i = 0; i < primes.size() && (ll)primes[i] <= sqrtn; i++ )
    {
        ll p = primes[i];
        ll j = p * p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
//        debug(a,b,b-j,j,p)
        for ( ; j <= b; j += p )
        {
//                debug(j-a)
            //debucg(j)
            arr[j-a] = 1; ///mark them as not prime
        }
//        debug("")
    }
    data tmpf(-1,-1,0);
    data tmpl(-1,-1,0);
    for ( ll i = a; i <= b; i++ )
    {
        ///If it is not marked, then it is a prime
        if ( arr[i-a] == 0 )
        {
                if(first.a==-1)
                {
                    first.a=i;
                    last.a=i;
                }
                else if(first.b==-1)
                {
                    first.b=i;
                    tmpf.a=i;
                    tmpl.a=i;
                    last.b=i;
                    first.dif=first.b-first.a;
                    last.dif=last.b-last.a;
                }
                else
                {
                    if(tmpf.a==-1)tmpf.a=i;
                    else if(tmpf.b==-1)
                    {
                        tmpf.b=i;
                        tmpf.dif=tmpf.b-tmpf.a;
                        if(tmpf.dif<first.dif)
                        {
                            first=tmpf;
                        }
                        tmpf.a=tmpf.b;
                        tmpf.b=-1;
                    }
                    if(tmpl.a==-1)tmpl.a=i;
                    else if(tmpl.b==-1)
                    {
                        tmpl.b=i;
                        tmpl.dif=tmpl.b-tmpl.a;
                        if(tmpl.dif>last.dif)
                        {
                            last=tmpl;
                        }
                        tmpl.a=tmpl.b;
                        tmpl.b=-1;
                    }
                }
            }
    }
}

int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    sieve(M-1);
    while(~getII(n,m))
    {
        first=data(-1,-1,INF);
        last=data(-1,-1,0);
        segmentedSieve((ll)n,(ll)m);
        if(first.a==-1||first.b==-1)
        {
            puts("There are no adjacent primes.");
        }
        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",first.a,first.b,last.a,last.b);
    }



    return 0;
}


