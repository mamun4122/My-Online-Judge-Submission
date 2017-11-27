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
vector<int> v;

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    while(~getI(n))
    {
        int x;
        v.clear();
        rep(i,n)
        {
            getI(x);
            v.push_back(x);
        }
        sort(ALL(v));
        if(n==1)puts("-1");
        else if(n==2)
        {
            int dif=v[1]-v[0];
            if(dif==0)
            {
                puts("1");
                printf("%d\n",v[0]);

            }
            else
            {
                if(v[1]-v[0]>0&&(v[1]-v[0])%2==0)
                    puts("3");
                else puts("2");
                printf("%d ",v[0]-dif);//,v[1]+dif);
                if(v[1]-v[0]>0&&(v[1]-v[0])%2==0)
                    printf("%d ",v[0]+(v[1]-v[0])/2);
                printf("%d\n",v[1]+dif);
            }
        }
        else
        {
            int flag=1;
            int dif1=v[1]-v[0],dif2=v[2]-v[1];
            if(dif1>dif2)
            {
                int cur=v[0]+dif2;
                int dif=dif2;
                int pos=1;
                flag=0;
                while(cur+dif==v[pos])
                {
                    cur=v[pos];
                    pos++;
                    if(pos==n)break;
                }
                if(pos==n)
                {
                    puts("1");
                    printf("%d\n",v[0]+dif);
                }
                else puts("0");
            }
            else if(dif1<dif2)
            {
                int dif=dif1;
                int cur=v[1]+dif1;
                int pos=2;
                while(cur+dif==v[pos])
                {
                    cur=v[pos];
                    pos++;
                    if(pos==n)break;
                }
                if(pos==n)
                {
                    puts("1");
                    printf("%d\n",v[1]+dif);
                }
                else puts("0");

            }
            else
            {
                flag=1;
                int dif=dif1;
                int cur=v[0];
                int pos=1;
                int ans=0;
                while(1)
                {
                    if(cur+dif!=v[pos])
                    {
                        if(flag)
                        {
                            flag=0;
                            ans=cur+dif;
                            cur=cur+dif;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        pos++;
                        cur=v[pos-1];
                    }
                    if(pos==n)break;
                }
                if(pos==n)
                {
                    if(flag==0)
                    {
                        puts("1");
                        printf("%d\n",ans);
                    }
                    else
                    {
                        if(dif==0)
                        {
                            puts("1");
                            printf("%d\n",v[0]);
                        }
                        else
                        {
                            puts("2");
                            printf("%d %d\n",v[0]-dif,v[n-1]+dif);
                        }
                    }
                }
                else
                {
                    puts("0");
                }
            }
        }

    }





    return 0;
}