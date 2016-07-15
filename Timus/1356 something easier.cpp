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
//#define mx 1000000000
//bool Check(int N,int pos)
//{
//    return (bool)(N & (1<<pos));
//}
//int Set(int N,int pos)
//{
//    return N=N | (1<<pos);
//}
//int status[(mx/32)+2];
//void sieve()
//{
//    int i, j;
//    for( i = 3; i*i <=mx; i += 2 )
//    {
//        if( Check(status[i>>5],i%31)==0)
//            for( j = i*i; j <= mx; j += (i<<1) )
//                status[j>>5]=Set(status[j>>5],j & 31)   ;
//    }
//}
bool isprime(int num)
{
    if(num<2)return false;
    if(num==2)return true;
    if(num%2==0)return false;
    for(int i=2; i*i<=num; i++)if(num%i==0)return false;
    return true;
}

int main()
{
//    READ("in.txt");
//    WRITE("out.txt");
    int t,n,m;
//    sieve();
    getI(t);
    while(t--)
    {
        getI(n);
        if(isprime(n))
        {
            printf("%d\n",n);
        }
        else if(n%2==0)
        {
            rep(i,n)
            {
                if(i==1)continue;

                if(isprime(i)&&isprime(n-i))
                {
                    printf("%d %d\n",i,n-i);
                    break;
                }
            }
        }
        else if(isprime(n-2))
        {
            printf("2 %d\n",n-2);
        }
        else
        {
            printf("3 ");
            n-=3;
            if(isprime(n))
            {
                printf("%d\n",n);
            }
            else
                rep(i,n)
            {
                if(i==1)continue;
                if(isprime(i)&&isprime(n-i))
                {
                    printf("%d %d\n",i,n-i);
                    break;
                }
            }
        }

    }



    return 0;
}

