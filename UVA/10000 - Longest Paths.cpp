
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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

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
vector<int> edges[105];
int mark[105],dist[105];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t,cs=1;
    while(getI(t)&&t)
    {
        //if(cs>1)printf("\n");
        //CLR(mark);
        CLR(dist);
        for(int i=1;i<=t;i++)edges[i].clear();
        int src;
        getI(src);
//        CLR(adj);
        int x,y;
        while(getII(x,y)&&x&&y)
        {
            edges[x].push_back(y);
        }
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            mark[u]=1;
            for(int i=0;i<edges[u].size();i++)
            {
                if(dist[edges[u][i]]<dist[u]+1){
                    q.push(edges[u][i]);
                    dist[edges[u][i]]=max(dist[edges[u][i]],dist[u]+1);
                }
                //}
            }
        }
        int mx=-INF,pos;
        for(int i=1;i<=t;i++)
        {
            if(mx<dist[i])
            {
                mx=dist[i];pos=i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",cs++,src,mx,pos);
        printf("\n");
    }


    return 0;
}


