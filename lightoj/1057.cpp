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
int srcx,srcy;
int arr[25][25];
int n,m;
pii gold[15];

int dx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]= {-1,+1,+0,+0,+1,+1,-1,-1};
int mark[25][25],dist[25][25][25][25];

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}




bool Check(int xx,int yy)
{
    if(xx>0&&xx<=n&&yy>0&&yy<=m)return 1;
    return 0;
}


void bfs(int srcxx,int srcyy)
{
    CLR(mark);
    //CLR(dist);
    queue<pii> q;
    mark[srcxx][srcyy]=1;
    dist[srcxx][srcyy][srcxx][srcyy]=0;
    q.push(make_pair(srcxx,srcyy));

    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        repI(i,8)
        {
            int x=u.ff+dx[i];
            int y=u.ss+dy[i];
            if(!mark[x][y]&&Check(x,y))
            {
                dist[srcxx][srcyy][x][y]=dist[srcxx][srcyy][u.ff][u.ss]+1;
                mark[x][y]=1;
               // debug(x,y,dist[srcxx][srcyy][x][y])
                q.push(make_pair(x,y));
            }
        }
    }
}
int dp[(1<<15)+4][21];
int cnt;


int call(int mask,pii src,int pos)
{
    if(__builtin_popcount(mask)==cnt)return dist[src.ff][src.ss][srcx][srcy];
    int &ret=dp[mask][pos];//[src.ss];
    if(ret!=-1)return ret;
    int res=INF;
    for(int i=0; i<cnt; i++)
    {
        if(check(mask,i)==0)
        {
            int cost=dist[src.ff][src.ss][gold[i].ff][gold[i].ss]+call(Set(mask,i),gold[i],i);
            res=min(cost,res);
        }
    }
    return ret=res;


}


int main()
{
   // READ("in.txt");
    //WRITE("out.txt");
    int t;//,n,m;
        CLR(dist);
    n=20;
    m=20;
    //bfs(1,1);
    rep(i,20)
    {
        rep(j,20)
        bfs(i,j);
    }

    getI(t);
    rep(cs,t)
    {
        SET(dp);
        getII(n,m);
        cnt=0;
        string s;
        rep(i,n)
        {

            cin>>s;
           // debug(s);
            repI(j,m)
            {
                if(s[j]=='g')
                {
                    arr[i][j+1]=1;
                    gold[cnt++]=make_pair(i,j+1);
                }
                else if(s[j]=='x')
                {

                    arr[i][j+1]=0;
                    srcx=i;
                    srcy=j+1;
                }
            }
        }
//        debug(cnt);
//        rep(i,n)
//        {
//            rep(j,m)
//            {
//                printf("%d ",dist[srcx][srcy][i][j]);
//            }
//            puts("");
//
//        }
        int ans=call(0,make_pair(srcx,srcy),16);
        printf("Case %d: %d\n",cs,ans);
    }



    return 0;
}

