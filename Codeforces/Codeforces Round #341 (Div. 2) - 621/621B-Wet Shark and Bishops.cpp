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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
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

#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long
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

int mark[1005][1005],color[1005][1005];
int main() {
    ///check for 0 and negative if limit is not specified

//    READ("out.txt");
    //WRITE("out.txt");
    while(~getI(n))
    {
        CLR(mark);
        CLR(color);
        int x,y;
        rep(i,n)
        {
            getII(x,y);
            mark[x][y]=1;
        }
        ll ans=0;
        rep(i,1000)
        {
            rep(j,1000)
            {
                if(!color[i][j])
                {
                    int cnt=0;
                    int posx=i,posy=j;
                    while(posx<=1000&&posy<=1000&&posx>0&&posy>0)
                    {
                        if(mark[posx][posy])cnt++;
                        color[posx][posy]=1;
                        posx++;
                        posy++;
                    }
                    ans+=(ll)((cnt*(cnt-1))/2);
//                    posx=i;posy=j;
//                    cnt=0;
//                    while(posx<=1000&&posy<=1000&&posx>0&&posy>0)
//                    {
//                        if(mark[posx][posy])cnt++;
//                        color[posx][posy]=1;
//                        posx++;
//                        posy--;
//                    }
//                    ans+=(ll)((cnt*(cnt-1))/2);

                }
            }
        }
        CLR(color);
        rep(i,1000)
        {
            rep(j,1000)
            {
                if(!color[i][j])
                {
                    int cnt=0;
                    int posx=i,posy=j;
                    while(posx<=1000&&posy<=1000&&posx>0&&posy>0)
                    {
                        if(mark[posx][posy])cnt++;
                        color[posx][posy]=1;
                        posx++;
                        posy--;
                    }
                    ans+=(ll)((cnt*(cnt-1))/2);
//                    posx=i;posy=j;
//                    cnt=0;
//                    while(posx<=1000&&posy<=1000&&posx>0&&posy>0)
//                    {
//                        if(mark[posx][posy])cnt++;
//                        color[posx][posy]=1;
//                        posx++;
//                        posy--;
//                    }
//                    ans+=(ll)((cnt*(cnt-1))/2);

                }
            }
        }
        cout<<ans<<endl;
    }





    return 0;
}