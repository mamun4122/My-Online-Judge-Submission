#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
string grid[10];
vector<pii> v;
int dp[9][9][70][(1<<8)+2];
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<8&&pos.ss>=0&&pos.ss<8)return true;
    return false;
}
int dist[10][10],mark[10][10];
int dirx[] = {-2,-2,2,2,-1,-1,1,1};
int diry[] = {1,-1,-1,1,2,-2,-2,2};
int bfs(pii src,pii dest)
{
    CLR(mark);
    dist[src.ff][src.ss]=0;
    mark[src.ff][src.ss]=1;
//    debug(src.ff,src.ss,dest.ff,dest.ss)
    queue<pii> q;
    q.push(src);
    while(!q.empty())
    {
        pii u=q.front();q.pop();
        if(u.ff==dest.ff&&u.ss==dest.ss)return dist[dest.ff][dest.ss];
        repI(i,8)
        {
            pii pos;
            pos.ff=u.ff+dirx[i];
            pos.ss=u.ss+diry[i];
            if(check(pos)&&mark[pos.ff][pos.ss]==0&&(grid[pos.ff][pos.ss]=='.'||(pos.ff==dest.ff&&pos.ss==dest.ss)))
            {
                mark[pos.ff][pos.ss]=1;
                q.push(pos);
                dist[pos.ff][pos.ss]=dist[u.ff][u.ss]+1;
            }
        }
    }
    return -1;
}

int call(int row,int col,int lft,int mask)
{
    if(__builtin_popcount(mask)==v.size())return 1;
    int &ret=dp[row][col][lft][mask];
    if(ret!=-1)return ret;
    int ans=0;
    repI(i,v.size())
    {
        if(bitCheck(mask,i)==0)
        {
            int d=bfs(pii(row,col),v[i]);
//            debug(i,d)
            if(d!=-1&&d<=lft)
            {
                grid[v[i].ff][v[i].ss]='.';
                ans|=call(v[i].ff,v[i].ss,lft-d,bitOn(mask,i));
                if(ans)return ret=ans;
                grid[v[i].ff][v[i].ss]='P';

            }
        }
    }
    return ret=ans;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        v.clear();
        getI(n);
        repI(i,8)cin>>grid[i];
        SET(dp);
        pii pos;
        repI(i,8)repI(j,8)if(grid[i][j]=='k')
        {
            pos=pii(i,j);
            break;
        }
        repI(i,8)repI(j,8)if(grid[i][j]=='P')v.push_back(pii(i,j));
//        debug(v.size())
        if(call(pos.ff,pos.ss,n,0))puts("Yes");
        else puts("No");
    }


    return 0;
}

