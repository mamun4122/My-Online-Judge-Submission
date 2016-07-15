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
double dist[55][55];
int storenum[55];
double save[55];
double dp[1<<13][55];
bool mark[1<<13][55];


double ans(int mask,int ind)
{
    if(__builtin_popcount(mask)==m)return (-dist[ind][0]);
    if(mark[mask][ind])return dp[mask][ind];
    mark[mask][ind]=1;

    double res=-dist[ind][0],res1;
//    debug("")
    rep(i,m)
    {
        if(chk(mask,i)==0)
        {
            int k=on(mask,i);
            res1=ans(k,storenum[i])+save[i]-dist[ind][storenum[i]];
            res=max(res,res1);
//            debug(res,res1)
        }
    }
    return dp[mask][ind]=res;


}

int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        int x;
        getII(n,x);
        repI(i,n+1)
        {
            repI(j,n+1)
                dist[i][j]=(i==j)?0:(double)INF;
        }
//        debug(dist[0][1])
        int a,b;
        double c;
        rep(i,x)
        {
            getII(a,b);
            getF(c);
            dist[a][b]=min(c,dist[a][b]);
            dist[b][a]=dist[a][b];
        }
        for (int k = 0; k <= n; k++)
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j])+EPS)
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
//        debug(n,m)
//        repI(i,n+1)
//        {
//            repI(j,n+1)printf("%.2lf ",dist[i][j]);
//            puts("");
//        }
        getI(m);
        rep(i,m)
        {
            getI(a);
            getF(c);
            storenum[i]=a;
            save[i]=c;
        }
        CLR(mark);
        double res=ans(0,0);
//        debug(res)
        if(res>EPS)printf("Daniel can save $%.2lf\n",res);
        else puts("Don't leave the house");

    }





    return 0;
}


