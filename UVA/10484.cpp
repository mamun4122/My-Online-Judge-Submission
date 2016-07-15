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
#define M 1000
bool marked[M];
vector<int> primes;   // we'll preload primes once at the beginning

void sieve(int n)
{
    primes.push_back(2);
    int i;
    for (i = 3; i * i <= n; i += 2)
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
int cnt[M];
void countdiv(int n)
{
    int sqrtn=sqrt(n);
    for(int i=0; i<primes.size()&&primes[i]<=sqrtn; i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                cnt[primes[i]]++;
                n/=primes[i];
            }
            sqrtn=sqrt(n);
        }
    }
    if(n>1)cnt[n]++;
}

int main()
{
    ///check for 0 and negative if limit is not specified

    //READ("in.txt");
    //WRITE("out.txt");
    sieve(M-1);
    while(~getII(n,m))
    {
        if(n==0&&m==0)break;
        CLR(cnt);
        rep(i,n)countdiv(i);
        int sqrtn=sqrt(m);
        int flag=0;
        for(int i=0;i<primes.size()&&primes[i]<=sqrtn;i++)
        {
            if(m%primes[i]==0)
            {
                while(m%primes[i]==0)
                {
                    cnt[primes[i]]--;
                    m/=primes[i];
                }
                if(cnt[primes[i]]<0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(m>1)
        {
            if(m>100)flag=1;
            else if(cnt[m]==0)flag=1;
            else cnt[m]--;
        }
        if(flag)puts("0");
        else
        {
            ll res=1;
            rep(i,n)
            {
                res*=(ll)(cnt[i]+1);
            }
            printf("%lld\n",res);
        }
    }




    return 0;
}


