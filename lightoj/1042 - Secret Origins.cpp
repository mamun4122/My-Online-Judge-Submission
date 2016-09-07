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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

int on(int n,int pos)
{
    return (n|(1<<pos));
}

int off(int n,int pos)
{
    return (n-(n & (1<<pos)));
}

bool check(int n,int pos)
{
    return (n & (1<<pos));
}



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
int on(ll n,int pos)
{
    return (n|(1<<pos));
}

int off(ll n,int pos)
{
    return (n-(n & (1<<pos)));
}

bool check(ll n,int pos)
{
    return (n & (1<<pos));
}
///start coding from here///
//int t,n,m;


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    rep(cs,t)
    {
        ll n;
        getL(n);
        int frst;
        for(int i=31;i>=0;i--)
        {
            if(check(n,i))
            {
                frst=i;break;
            }
        }
//        for(int i=32;i>=0;i--)printf("%d",check(n,i));
//        printf("\n");
        int cnt=0;
        repI(i,frst+1)if(check(n,i))cnt++;
        int lst;
        repI(i,frst+1)if(check(n,i)){lst=i;break;}
        int fnd=-1,tmp=0;
        for(int i=lst;i<=frst;i++)
        {
            if(!check(n,i))
            {
                fnd=i;
                break;
            }
            else tmp++;
        }
        printf("Case %d: ",cs);
        if(fnd!=-1)
        {
            n=on(n,fnd);
            tmp--;
            repI(i,fnd)n=off(n,i);
            repI(i,tmp)n=on(n,i);
            printf("%lld\n",n);
        }
        else
        {
            repI(i,frst+1)n=off(n,i);
            repI(i,cnt-1)n=on(n,i);
            n=on(n,frst+1);
            printf("%lld\n",n);
        }
//        for(int i=32;i>=0;i--)printf("%d",check(n,i));
//        printf("\n");
    }





    return 0;
}


