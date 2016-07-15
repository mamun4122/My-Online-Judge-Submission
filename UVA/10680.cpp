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
int mp[M+1];
int dp[M+1];
int two[M+1];
int five[M+1];
vector<int> primes; // we'll preload primes once at the beginning

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
vector<int>v;
int res;
void  countPrimeDivisor(int n)
{
//    int cnt = 0;
    int sqrtn=sqrt(n);
    for (int i = 0; i < primes.size()&&primes[i]<=sqrtn; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt=0;

            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
                if(cnt>mp[primes[i]]&&!(primes[i]==2||primes[i]==5))
                {
                    res=res*primes[i];
                    res%=10;
                }
//                debug(res,primes[i])
            }
            sqrtn=sqrt(n);
//            v.push_back(primes[i]);
            mp[primes[i]]=max(mp[primes[i]],cnt);
        }
    }
//    debug(res)
//    debug("m",n)
    if(n>1)
    {
        if(!(n==2||n==5)&&mp[n]==0)
        {
            res=res*n;
            res%=10;
        }
        mp[n]=max(mp[n],1);
    }
//    return cnt;
}

int main()
{
    ///check for 0 and negative if limit is not specified

    //READ("in.txt");
    //WRITE("out.txt");
    sieve(M-1);
    CLR(mp);
    res=1;
    rep(i,M-5)
    {
        countPrimeDivisor(i);
        dp[i]=res;
        two[i]=mp[2];
        five[i]=mp[5];
//            debug(res)
//            debug(res)
    }
    while(~getI(n)&&n)
    {
//        mp.clear();
//        CLR(mp);
//        res=1;
        int mn=min(two[n],five[n]);
//        debug(mp[2],mp[5])
//        mp[2]-=mn;
//        mp[5]-=mn;
        res=dp[n];
        rep(i,two[n]-mn)res=(res*2)%10;
        printf("%d\n",res);
    }





    return 0;
}


