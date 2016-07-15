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
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define repI(i,n) for( i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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
const int INF = 0x7f7f7f;
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
#define MAXN 210
struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w > p.w;
    }
};
int pr[MAXN],mark[MAXN];
vector<edge>e;
vector<int> adj[MAXN],cost[MAXN];
int dist[MAXN];//,mark[MAXN];
int find(int r)
{
    return pr[r]=(pr[r]==r) ? r:  find(pr[r]);
}
void mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=1; i<=n; i++)pr[i]=i;

    int count=0;//,s=0;
    for(int i=0; i<(int)e.size(); i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            //debug(e[i].u,e[i].v)
            adj[e[i].u].push_back(e[i].v);
            adj[e[i].v].push_back(e[i].u);
            cost[e[i].u].push_back(e[i].w);
            cost[e[i].v].push_back(e[i].w);
            pr[u]=v;
            count++;
            //s+=e[i].w;
            if(count==n-1) break;
        }
    }
    //return s;
}
map<string,int> mp;
void bfs(int src,int dest)
{
    //debug(src,dest)
    mark[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(u==dest)return;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            int c=cost[u][i];
            //debug(u,v,c)
            if(!mark[v])
            {
                dist[v]=min(c,dist[u]);
                mark[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
	//READ("in.txt");
	//WRITE("out.txt");
    //debug(INF)
    int n,m,i,flg=0;
    while(getII(n,m)&&(n||m))
    {
        //if(flg)puts("");
        string x,y;
        int z;
        int cnt=1;

        edge get;
        e.clear();
        rep(i,m)
        {
            cin>>x>>y>>z;
            if(!mp[x])mp[x]=cnt++;
            if(!mp[y])mp[y]=cnt++;
            get.u=mp[x];
            get.v=mp[y];
            get.w=z;
            e.push_back(get);
        }
        rep(i,n){
            adj[i].clear();
            cost[i].clear();
            dist[i]=INF;
        }
        mst(cnt);
        CLR(mark);
        cin>>x>>y;
        //debug(x,y)
        bfs(mp[x],mp[y]);
        printf("Scenario #%d\n%d tons\n",++flg,dist[mp[y]]);
        mp.clear();
        puts("");


    }
    return 0;

}


