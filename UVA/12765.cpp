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
#define mamu
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
int mark1[10],mark2[10];
int prime[]= {2,3,5,7};

int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    while(~getII(n,m))
    {
        if(n==0&&m==0)break;
        CLR(mark1);
        CLR(mark2);
        int x;
        for(int i=1; i<=n; i++)
        {
            getI(x);
            debug(x)
            int tmp=x;
            for(int k=2; k<=tmp; k++)
            {
                x=k;
                if(x)
                {

                    repI(j,4)
                    {
                        if(x%prime[j]==0)
                        {
                            while(x%prime[j]==0)
                            {
                                mark1[prime[j]]++;
                                x/=prime[j];
                            }
                        }
                    }
                }
                if(x)mark1[x]++;
                debug(x)
            }
        }
        debug("*")
        for(int i=1; i<=m; i++)
        {
            getI(x);
            int tmp=x;
            for(int k=2; k<=tmp; k++)
            {
                x=k;
                if(x)
                {
                    repI(j,4)
                    {
                        if(x%prime[j]==0)
                        {
                            while(x%prime[j]==0)
                            {
                                mark2[prime[j]]++;
                                x/=prime[j];
                            }
                        }
                    }
                }
                if(x)mark2[x]++;
            }
        }
//        repI(i,10)
//        {
//            int mn=min(mark1[i],mark2[i]);
//            mark1[i]-=mn;
//            mark2[i]-=mn;
//        }
        int flag=0;
        repI(i,10)if(mark1[i]!=mark2[i]&&i!=1&&i!=0)
        {
            //debug(i,mark1[i],mark2[i])
            flag=1;
            break;
        }
        if(flag)puts("NO");
        else puts("YES");

    }


    return 0;
}

