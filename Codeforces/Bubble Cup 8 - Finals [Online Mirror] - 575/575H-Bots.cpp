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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

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

int n;
#define mod 1000000007
int dp[2000016];

//ll call(int red,int blue)
//{
//    if(red>=n && blue>=n) return 0;
//    //if(dp[red]!=-1 && dp[n+blue]!=-1) return dp[red]+dp[n+blue];
//    ll p1=0;
//    if(red<n)
//        p1=(1+2call(red+1,blue))%mod;
//    ll p2=0;
//    if(blue<n)
//        p2=(1+call(red,blue+1))%mod;
////    dp[red]=p1;
////    dp[n+blue]=p2;
//    return (p1+p2)%mod;
//}

ll call1(int red,int blue)
{
    //debug(red,blue);
    if(red>=n && blue>=n) return 0;
    ll p1,p2;
    p1=p2=0;
    if(red==blue && red<n)
    {
        p1=(2+(2*call1(red+1,blue))%mod)%mod;
    }
    else
    {
        if(red<n)
            p1=(1+call1(red+1,blue))%mod;
        if(blue<n)
            p2=(1+call1(red,blue+1))%mod;
    }
   // debug(p1,p2,p1+p2,"*")
    return (p1+p2)%mod;
}

int binomialCoeff(int n, int k)
{
    int* C = (int*)calloc(k+1, sizeof(int));
    int i, j, res;

    C[0] = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }

    res = C[k];  // Store the result before freeing memory

    free(C);  // free dynamically allocated memory to avoid memory leak

    return res;
}

pii extendedEuclid(int a, int b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


int modularInverse(int a, int n) {  // returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, n);
  return ((ret.ff % n) + n) % n;
}

    ll fact[2000016];
    ll modI[1000016];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    fact[0]=1;
    for(int i=1;i<=2000004;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    modI[0]=modularInverse(1,mod);
    for(int i=1;i<=1000004;i++)
    {
        ll k = ((fact[i]%mod)*(fact[i]%mod))%mod;
        modI[i]=modularInverse(k,mod);
    }
    while(~getI(n))
    {
        n++;
        //debug(call1(0,0)+1);
        printf("%lld\n",(((fact[2*n]%mod)*(modI[n]%mod))%mod)-1);
    }



    return 0;
}