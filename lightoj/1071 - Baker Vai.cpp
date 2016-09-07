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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
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
int dp[101][101][201],mat[101][101];//,dp1[101][101];
int mark[101][101];
int n,m;

int call(int i,int j,int k,int l,int dist)
{

    if(i>n||j>m||k>n||l>m)return 0;
    if(i==k&&j==l&&!(i==1&&j==1)&&!(i==n&&j==m))return 0;
    if(dp[i][k][dist]!=-1)return dp[i][k][dist];
    int ans=-INF;
    ans=max(ans,call(i+1,j,k,l+1,dist+1)+mat[i][j]+mat[k][l]);
    ans=max(ans,call(i+1,j,k+1,l,dist+1)+mat[i][j]+mat[k][l]);
    ans=max(ans,call(i,j+1,k+1,l,dist+1)+mat[i][j]+mat[k][l]);
    ans=max(ans,call(i,j+1,k,l+1,dist+1)+mat[i][j]+mat[k][l]);
    return  dp[i][k][dist]=ans;


}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    for(int cs=1; cs<=t; cs++)
    {
        SET(dp);
        CLR(mat);
        CLR(mark);
        getII(n,m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                getI(mat[i][j]);
        //debug(call1(1,1));
        printf("Case %d: %d\n",cs,call(1,1,1,1,0)-mat[1][1]-mat[n][m]);


    }

    return 0;
}


