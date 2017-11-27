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
int adj[410][410];
int distr[410][2];//,dist[410];
int mark[410];
void bfs(int src,int type,int dest)
{
    queue<int>q;
    CLR(mark);
    q.push(src);
    mark[src]=1;
    distr[src][type]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        if(v==dest)return;// distr[v][type];
        rep(i,dest)
        {
            if(adj[v][i]==type&&!mark[i])
            {
                q.push(i);
                mark[i]=1;
                distr[i][type]=distr[v][type]+1;
            }
        }
    }
    //return -1;


}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    while(~getII(n,m))
    {
        CLR(adj);
        int a,b;
        rep(i,m)
        {
            getII(a,b);
            adj[a][b]=1;
            adj[b][a]=1;
        }
        SET(distr);
        bfs(1,0,n);
        bfs(1,1,n);
        int mn=min(distr[n][0],distr[n][1]);
        int mx=max(distr[n][0],distr[n][1]);
        rep(i,n-1)
        {

            if(i!=1&&distr[i][0]==distr[i][1]&&distr[i][0]!=-1){
                mx+=2;
                break;
            }
        }
        if(mn==-1)puts("-1");
        else printf("%d\n",mx);
    }





    return 0;
}