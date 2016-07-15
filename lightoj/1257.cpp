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

vector<pii> edge[30005];
bool mark[30005];
int dist[30005];
void dfs(int src)
{
    mark[src]=1;
//    dist[src]=0;
    repI(i,edge[src].size())
    {
        pii v=edge[src][i];
        if(mark[v.ff]==0)
        {
            dist[v.ff]=dist[src]+v.ss;
            dfs(v.ff);
        }
    }
}
int val[300005];
void bfs1(int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    mark[src]=1;
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        repI(i,edge[src].size())
        {
            pii v=edge[src][i];
            if(mark[v.ff]==0)
            {
                dist[v.ff]=dist[src]+v.ss;
                mark[v.ff]=1;
                q.push(v.ff);
            }
        }
    }
}
void bfs2(int src)
{
    queue<int> q;
    q.push(src);
    val[src]=0;
    mark[src]=1;
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        repI(i,edge[src].size())
        {
            pii v=edge[src][i];
            if(mark[v.ff]==0)
            {
                val[v.ff]=val[src]+v.ss;
                mark[v.ff]=1;
                q.push(v.ff);
            }
        }
    }
}
int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        getI(n);
        repI(i,n)edge[i].clear();
        rep(i,n-1)
        {
            int u,v,w;
            getIII(u,v,w);
            edge[u].push_back(make_pair(v,w));
            edge[v].push_back(make_pair(u,w));
        }
        CLR(mark);
        CLR(dist);
        dfs(0);
        int mx=0,strt=0,scnd;
        repI(i,n)
        {
            if(dist[i]>mx)
            {
                strt=i;
                mx=dist[i];
            }
        }
//        debug(strt)
        CLR(mark);
        CLR(dist);
        dfs(strt);
        mx=0;
        repI(i,n)
        {
            if(dist[i]>mx)
            {
                scnd=i;
                mx=dist[i];
            }
        }
//        debug(strt,scnd)
        CLR(mark);
        bfs1(strt);
        CLR(mark);
        bfs2(scnd);
        printf("Case %d:\n",cs);
        repI(i,n)printf("%d\n",max(dist[i],val[i]));


    }





    return 0;
}



