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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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
#define mam
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
struct data
{
    int doc,hall,confidence;
} arr[4005];
int mark[4010],c[4010];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs,n,m;
    while(~getI(n))
    {
        rep(i,n)
        {
            getIII(arr[i].doc,arr[i].hall,arr[i].confidence);
        }
        int cnt=0;
        vector<int> v;
        rep(i,n)
        {
            if(arr[i].confidence<0)continue;
            v.push_back(i);
            cnt++;
            vector<int> chain;
            for(j=i+1; j<=n; j++)
            {
                if(arr[j].confidence>=0)
                {
                    arr[j].confidence-=arr[i].doc;
                    arr[i].doc--;
                    if(arr[j].confidence<0)chain.push_back(j);
                }
                debug(j,arr[j].confidence)
                if(arr[i].doc<0)break;
            }
            for(j=0;j<chain.size();j++)
            {
                //debug(i,chain[j]);
                int x=chain[j];
                for(int k=x+1;k<=n;k++)
                {

//                debug("*c*",k,arr[k].confidence)

                    if(arr[k].confidence>=0)
                    {
                        arr[k].confidence-=arr[x].hall;
                        if(arr[k].confidence<0)
                            chain.push_back(k);
                    }
                    debug("*",k,arr[k].confidence)
                }
            }
            debug("*******")

        }
        printf("%d\n",cnt);
        for(i=0; i<cnt; i++)
        {
            if(i)printf(" ");
            printf("%d",v[i]);
        }
        puts("");
    }




    return 0;
}