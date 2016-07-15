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
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
ll dp[205][205];
int mat[205][205];
int r,c,n;
ll call(int i,int j)
{
    if(i>r||j>n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(mat[i][j]==0)return 0;
    ll ret=-INF;
    ret=_max(ret,call(i+1,j)+mat[i][j]);
    if(i>=n)
        ret=_max(ret,call(i+1,j-1)+mat[i][j]);
    else
        ret=_max(ret,call(i+1,j+1)+mat[i][j]);
    //debug(i,j,ret);
    return dp[i][j]=ret;

}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //printf("%lld",pow(2,15)*205);
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        SET(dp);
        CLR(mat);
        //int n;
        getI(n);
        r=2*n-1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                getI(mat[i][j]);
            }
        }
        for(int i=n-1,cnt=n+1; i>0; i--,cnt++)
        {
            for(int j=1; j<=i; j++)
                getI(mat[cnt][j]);
        }
        printf("Case %d: %lld\n",cs,call(1,1));
    }


    return 0;
}


