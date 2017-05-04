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
template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

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
int t,n,m;
int mark[10][10];
int sol[100][10];

bool isok(int row,int col)
{
    rep(i,8)
    {
        if(mark[i][col]&&i!=row)return false;
    }
    rep(i,8)
    {
        if(mark[row][i]&&i!=col)return false;
    }
    rep(i,8)rep(j,8)
    {
        if(mark[i][j]&&!(i==row&&j==col)&&abs(i-row)==abs(j-col))return false;
    }
    return true;

}
int cnt;
void solve(int row,int col)
{
    if(col>8)
    {
        rep(i,8)
        {
            rep(j,8)
            {
                if(mark[i][j])sol[cnt][j]=i;
            }
        }
        cnt++;
        return;
    }
    rep(i,8)
    {
        if(isok(i,col))
        {
            mark[i][col]=1;
            solve(1,col+1);
            mark[i][col]=0;
        }
    }
}


int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    cnt=1;
    solve(1,1);
    int cs=1;
    cnt--;
    int arr[10];
//    rep(i,cnt)
//    {
//        rep(j,8)printf("%d ",sol[i][j]);
//        puts("");
//    }
    while(~getI(arr[1]))
    {
        rep(i,7)getI(arr[i+1]);
        int ans=INF,tmp;
        rep(i,cnt)
        {
            tmp=0;
            rep(j,8)
            {
                if(sol[i][j]!=arr[j])tmp++;
            }
            ans=min(ans,tmp);
        }
        printf("Case %d: %d\n",cs++,ans);
    }




    return 0;
}



