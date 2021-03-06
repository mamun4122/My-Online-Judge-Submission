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
#define M 100
bool marked[M];
int tot;
vector<int>dig;
map<int,int>prime;
void sieve(int n)
{
    CLR(marked);
    prime[2]=1;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            prime[i]=1;
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    for(int i=3; i<100; i+=2)
    {
        if(!marked[i])prime[i]=1;
    }
}

ll dp[10][2][90][90];
ll call(int pos,int flag,int evensum,int oddsum)
{
    if(pos==tot)return prime[(evensum-oddsum)];
    ll &ret=dp[pos][flag][evensum][oddsum];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig[pos]+1)
        ans+=call(pos+1,i==dig[pos],(tot-pos)%2==0?evensum+i:evensum,(tot-pos)%2==1?oddsum+i:oddsum);
    }
    else
    {
        if(flag)
        {
            repI(i,dig[pos]+1)
            ans+=call(pos+1,i==dig[pos],(tot-pos)%2==0?evensum+i:evensum,(tot-pos)%2==1?oddsum+i:oddsum);
        }
        else
        {
            repI(i,10)
            {
                ans+=call(pos+1,0,(tot-pos)%2==0?evensum+i:evensum,(tot-pos)%2==1?oddsum+i:oddsum);
            }
        }
    }
    return ret=ans;
}

ll calc(int num)
{
    if(num<=0)return 0;
    SET(dp);
    dig.clear();
    while(num)
    {
        dig.push_back(num%10);
        num/=10;
    }
    reverse(ALL(dig));
    tot=dig.size();
    return call(0,0,0,0);
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    sieve(100);
    int t,n,m;
    getI(t);
    while(t--)
    {
        int a,b;
        getII(a,b);
        a--;
        ll ansa=calc(a);
        ll ansb=calc(b);
        printf("%lld\n",ansb-ansa);
    }





    return 0;
}

