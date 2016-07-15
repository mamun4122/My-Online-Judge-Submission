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

#define iseq(a,b) (fabs(a-b)<EPS)

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
int b,c,a,n;
vector<int> adj[2002];
int visited[2002],color[2002];
int cnctedgraph,zeroone[2002][2];
int dfs(int node,int tobecolor)
{
    //debug(node);
    zeroone[cnctedgraph][tobecolor]++;
    visited[node]=1;
    color[node]=tobecolor;
    for(int i=0;i<adj[node].size();i++)
    {
        if(visited[adj[node][i]]&&color[adj[node][i]]==tobecolor) return 0;
        else if(!visited[adj[node][i]])dfs(adj[node][i],(tobecolor+1)%2);
    }
    return 1;
}
int dp[1005][1005];
int func(int node,int bull)
{
    //debug(node,bull);
    if(node==cnctedgraph)
    {
        if(bull==b)return 1;
        else return 0;
    }
    if(dp[node][bull]!=-1)return dp[node][bull];
    dp[node][bull]=max(func(node+1,bull+zeroone[node][0]),func(node+1,bull+zeroone[node][1]));
    return dp[node][bull];
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    for(int cs=1;cs<=t;cs++)
    {
        CLR(zeroone);
        cnctedgraph=0;
        getIII(b,c,a);
        n=b+c;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        CLR(visited);
        for(int i=1;i<=a;i++)
        {
            int u,v;
            getII(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int flag=false;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(!dfs(i,0))
                {
                    flag=true;
                    break;
                }
                cnctedgraph++;
            }
            //debug(i);

        }
        //debug(cnctedgraph);
        //debug("mamun");
        if(flag)printf("no\n");
        if(flag)continue;
        SET(dp);
        if(func(0,0))
            puts("yes");
        else
            puts("no");

    }



    return 0;
}


