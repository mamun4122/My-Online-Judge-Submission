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
int a,b,c,d;
typedef pair<pii,int> piii;
queue<int>q;
void make(int x,int y,int z)
{
    q.push(x);
    q.push(y);
    q.push(z);
}
bool mark[201][201][201];
int dist[201][201][201];
int res[201];

void bfs()
{
    make(0,0,c);
    mark[0][0][c]=1;
    dist[0][0][c]=0;
    while(!q.empty())
    {
////        piii src=q.front();
////        q.pop();
        int x=q.front();
        q.pop();
        int y=q.front();
        q.pop();
        int z=q.front();
        q.pop();

        res[x]=min(res[x],dist[x][y][z]);
        res[y]=min(res[y],dist[x][y][z]);
        res[z]=min(res[z],dist[x][y][z]);
        ///a->b
        int mn=min(x,b-y);
        if(mn)
        {
            if(!mark[x-mn][y+mn][z])
            {
                mark[x-mn][y+mn][z]=1;
                (make(x-mn,y+mn,z));
                dist[x-mn][y+mn][z]=mn+dist[x][y][z];
            }
            else if(dist[x-mn][y+mn][z]>mn+dist[x][y][z])
            {
                mark[x-mn][y+mn][z]=1;
                (make(x-mn,y+mn,z));
                dist[x-mn][y+mn][z]=mn+dist[x][y][z];
            }
        }
        ///a->c
        mn=min(x,c-z);
        if(mn)
        {
            if(!mark[x-mn][y][z+mn])
            {
                mark[x-mn][y][z+mn]=1;
                (make(x-mn,y,z+mn));
                dist[x-mn][y][z+mn]=mn+dist[x][y][z];
            }
            else if(dist[x-mn][y][z+mn]>mn+dist[x][y][z])
            {
                mark[x-mn][y][z+mn]=1;
                (make(x-mn,y,z+mn));
                dist[x-mn][y][z+mn]=mn+dist[x][y][z];

            }
        }
        ///b->a
        mn=min(a-x,y);
        if(mn)
        {
            if(!mark[x+mn][y-mn][z])
            {
                mark[x+mn][y-mn][z]=1;
                (make(x+mn,y-mn,z));
                dist[x+mn][y-mn][z]=mn+dist[x][y][z];
            }
            else if(dist[x+mn][y-mn][z]>mn+dist[x][y][z])
            {
                mark[x+mn][y-mn][z]=1;
                (make(x+mn,y-mn,z));
                dist[x+mn][y-mn][z]=mn+dist[x][y][z];

            }
        }
        ///b->c
        mn=min(c-z,y);
        if(mn)
        {
            if(!mark[x][y-mn][z+mn])
            {
                mark[x][y-mn][z+mn]=1;
                (make(x,y-mn,z+mn));
                dist[x][y-mn][z+mn]=mn+dist[x][y][z];
            }
            else if(dist[x][y-mn][z+mn]>mn+dist[x][y][z])
            {
                mark[x][y-mn][z+mn]=1;
                (make(x,y-mn,z+mn));
                dist[x][y-mn][z+mn]=mn+dist[x][y][z];


            }
        }
        ///c->a
        mn=min(a-x,z);
        if(mn)
        {
            if(!mark[x+mn][y][z-mn])
            {
                mark[x+mn][y][z-mn]=1;
                (make(x+mn,y,z-mn));
                dist[x+mn][y][z-mn]=mn+dist[x][y][z];
            }
            else if(dist[x+mn][y][z-mn]>mn+dist[x][y][z])
            {
                mark[x+mn][y][z-mn]=1;
                (make(x+mn,y,z-mn));
                dist[x+mn][y][z-mn]=mn+dist[x][y][z];
            }
        }
        ///c->b
        mn=min(b-y,z);
        if(mn)
        {
            if(!mark[x][y+mn][z-mn])
            {
                mark[x][y+mn][z-mn]=1;
                (make(x,y+mn,z-mn));
                dist[x][y+mn][z-mn]= mn+dist[x][y][z];
            }
            else if(dist[x][y+mn][z-mn]> mn+dist[x][y][z])
            {
                mark[x][y+mn][z-mn]=1;
                (make(x,y+mn,z-mn));
                dist[x][y+mn][z-mn]= mn+dist[x][y][z];

            }
        }

    }
}


int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        getII(a,b);
        getII(c,d);

        CLR(mark);
//        mem(dist,63);
        mem(res,63);

        int ans=res[0],val;
//        debug(ans)
        bfs();
        for(int i=d; i>=0; i--)if(res[i]<ans)
            {
                ans=res[i];
                val=i;
                break;
            }
        printf("%d %d\n",ans,val);

    }


    return 0;
}


