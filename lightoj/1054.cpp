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

#define mod 1000000007
#define    pii 	 pair< ll, ll >


ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

#define M 1000005
bool marked[M];
vector <int> primes;

void sieve(int n) {
	primes.push_back(2);
	int i;
	for ( i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i + i) {
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
int sz;
vector<pair<int,int> > v;
void countPrimeDivisor(int n)
{
    int sqrtn=sqrt(n);
    for (int i = 0; i < sz&&i<=sqrtn; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt=0;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            sqrtn=sqrt(n);
            v.push_back(make_pair(primes[i],cnt));
        }
    }
    if(n>1)
    {
        v.push_back(make_pair(n,1));
    }
}
pii extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(ll a, ll n) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, n);
  return ((ret.ff % n) + n) % n;
}

int main() {
    ///check for 0 and negative if limit is not specified

    //READ("in.txt");
    //WRITE("out.txt");
    sieve(M-1);
    getI(t);
    sz=primes.size();
    rep(cs,t)
    {
        v.clear();
        getII(n,m);
        countPrimeDivisor(n);
        ll ans=1;
        repI(i,v.size())
        {
            ll a=(ll)v[i].ff;
            ll b=(ll)v[i].ss;
            b*=(ll)m;
            b++;
            ll x=bigmod(a,b,mod);
            x--;
            if(x<0)x+=mod;
            ll y=modularInverse(a-1,mod);
            x=((x%mod)*(y%mod))%mod;
            ans=((ans%mod)*(x%mod))%mod;

        }
        printf("Case %d: %lld\n",cs,ans);
    }






    return 0;
}


