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
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
///start coding from here///
int t,n,m;

char input[100010];


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    while(~getI(n))
    {
//        int zero=0;
        string unlucky="";
        getchar();
        int tmp=0,cnt=0,fin=0,zero;
        int finfag=1;
        rep(i,n)
        {
            tmp=0;
            zero=1;
            int flag=0;//finfag=1;
            scanf("%s",input);
//            debug(input)
            int sz=strlen(input);
            int strt=-1,anthr=0;
            repI(j,sz)
            {
                if(input[j]!='0'&&strt==-1)
                {
                    strt=j;
                }
                if(input[j]!='1'&&input[j]!='0')
                {
                    zero=0;
                    flag=1;
                    finfag=0;
                    break;
                }
                if(input[j]=='1')
                {
                    zero=0;
                    anthr++;
                }
                if(anthr==2)
                {
                    flag=1;
                    finfag=0;
                    break;
                }
                if(strt!=-1&&input[j]!='1')tmp++;
            }
            fin|=zero;
            if(flag)
            {
                for(int j=strt; j<sz; j++)
                    unlucky+=input[j];
            }
            else
            {
                cnt+=tmp;
            }
        }
        if(finfag)unlucky="1";
        if(fin)puts("0");
        else
        {
            printf("%s",unlucky.c_str());
            rep(i,cnt)printf("0");
            puts("");
        }

    }




    return 0;
}