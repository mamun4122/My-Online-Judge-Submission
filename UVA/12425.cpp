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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
#define M 1000005
ll phi[M];
bool marked[M];
vector<ll> primes;
vector<ll> mainfactor;
vector<int> countfactor;
vector<ll>allfactor;
vector<pair<ll,ll> > ans;
ll cum[M];
void sieve(ll n)
{
    primes.push_back(2);
    ll i;
    for (i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i + i)
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
void divisor ( ll n )
{
    ll sqrtn = sqrt ( n );
    for ( ll i = 0; i < primes.size() && (ll)primes[i] <= sqrtn; i++ )
    {
        if ( n % (ll)primes[i] == 0 )
        {
            int p = 0; /*Counter for power of prime*/
            while ( n % (ll)primes[i] == 0 )
            {
                n /= (ll)primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            mainfactor.push_back((ll)primes[i]);
            countfactor.push_back(p);
        }
    }
    if ( n != 1 )
    {
        mainfactor.push_back((ll)n);
        countfactor.push_back(1);
    }
}
void calculatePhi()
{
    for (int i = 1; i < M; i++)
    {
        phi[i] = i;
    }
    for (int p = 2; p < M; p++)
    {
        if (phi[p] == p)   // p is a prime
        {
            for (int k = p; k < M; k += p)
            {
                phi[k] -= phi[k] / p;
            }
        }
    }
}
void alldivisor(int idx,ll num)
{
    if(idx==mainfactor.size())
    {
        allfactor.push_back(num);
        return;
    }
    alldivisor(idx+1,num);
//    alldivisor(idx+1,mainfactor[idx]);
    for(int i=countfactor[idx];i;i--)
    {
        alldivisor(idx+1,num*mainfactor[idx]);
        num*=mainfactor[idx];
    }

}

ll eulerPhi ( ll n ) {
    if(n<M)return phi[n];
    ll res = n;
    ll sqrtn = sqrt ( n );
    for ( ll i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {
        if ( n % primes[i] == 0 ) {
            while ( n % primes[i] == 0 ) {
                n /= primes[i];
            }
            sqrtn = sqrt ( n );
            res /= primes[i];
            res *= primes[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    calculatePhi();
    sieve(M-1);

    int t;
    getI(t);
    rep(cs,t)
    {
        ll n,m;
        int q;
        mainfactor.clear();
        allfactor.clear();
        ans.clear();
        CLR(cum);
        countfactor.clear();
        getL(n);
        getI(q);
        ///getting the prime factor of n
        divisor(n);
//        repI(i,mainfactor.size())debug(mainfactor[i],countfactor[i])
        ///getting all the factor of n
        alldivisor(0,1);
        sort(ALL(allfactor));
//        repI(i,allfactor.size())debug(allfactor[i]);
        ///generating phi value for all the factor
        repI(i,allfactor.size())
        {
            ans.push_back(make_pair(allfactor[i],eulerPhi(n/allfactor[i])));
        }
//        repI(i,ans.size())debug(ans[i].ff,ans[i].ss)
        printf("Case %d\n",cs);
        int sz=ans.size();

        ///generating cumalitive sum of phi value
        repI(i,sz)
        {
            if(i)cum[i]=cum[i-1]+ans[i].ss;
            else cum[i]=ans[i].ss;
        }
        rep(i,q)
        {
            getL(m);

            ///binary searching the answer based on the gcd see khata for explaination
            int low=0,high=sz-1,flag=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(ans[mid].ff<=m)
                {
                    flag=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            ///flag==-1 means m is negative or zero
            printf("%lld\n",flag==-1?0:cum[flag]);
        }
    }





    return 0;
}

