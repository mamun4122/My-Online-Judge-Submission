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
#define M 1000000
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    int i;
    for ( i = 3; i * i < n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j < n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    //debug(i)
    for(; i<M; i+=2)
        if(marked[i]==0)primes.push_back(i);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,m;
    ll input;
    sieve(M);
    while(~getL(input)&&input)
    {
        int primecnt=-1;
        ll x=fabs(input);
        //debug(x)
        for(int i=0; (ll)primes[i]*(ll)primes[i]<=x; i++)
        {
            if(x%(ll)primes[i]==0)
            {
                int tmp=0;
                while(x%(ll)primes[i]==0)
                {
                    tmp++;
                    x/=(ll)primes[i];
                }
                //debug(x,primes[i],tmp)
                if(primecnt==-1)
                {
                    primecnt=tmp;
                    //ans*=(ll)primes[i];
                }
                else
                {
                    primecnt=gcd(primecnt,tmp);
                    //break;
                }

            }
        }
        //debug(x,primecnt)
        if(x>1)
        {
            primecnt=1;
        }
        if(primecnt==-1)
            primecnt=1;
        if(input<0&&primecnt%2==0)
        {
            while(primecnt%2==0)
                primecnt/=2;
            printf("%d\n",primecnt);
        }
        else if(input<0)
            printf("%d\n",primecnt);
        else
            printf("%d\n",primecnt);



    }



    return 0;
}


