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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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
#define mam
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

int adj[200][200],mark[200][200];
int n,m,srcx,srcy;
int flag;
struct data
{
    int x,y,cnt;
    data()
    {

    }
    data(int xx,int yy,int cc)
    {
        x=xx;y=yy;
        cnt=cc;
    }
}src;
//void bfs()
//{
//    queue<data> q;
//    q.push(src);
//    int cnt=0;
//    while(!q.empty())
//    {
//        data v=q.front();q.pop();
//        if(v.x==n)
//        {
//            flag=1;
//            return;
//        }
//        if(adj[v.x+cnt+1][v.y+cnt-1]==0&&(v.y==3||v.y==2)&&adj[v.x+cnt+1][v.x+cnt+1]==0)
//            q.push(data(v.x+1,v.y));
//        if(adj[v.x+cnt+1][v.y+cnt]==0&&(v.y==1||v.y==2))
//            q.push(data(v.x+1,v.y));
//
//
//    }
//}
void dfs(data xx,int cnt)
{
    if(adj[xx.x][xx.y+cnt])return;
    if(mark[xx.x][xx.y])return;
    if(flag)return;
    mark[xx.x][xx.y]=1;
    //debug(xx.x,xx.y)
    if(xx.y==n)
    {
        flag=1;
        return;
    }
    debug(xx.x,xx.y,xx.y+cnt,cnt)
    if(xx.x==1)
    {
        if(!adj[xx.x][xx.y+1+cnt])
        {
           if(!adj[xx.x+1][xx.y+1+cnt])
                dfs(data(xx.x+1,xx.y+1,0),cnt+2);
            if(!adj[xx.x][xx.y+1+cnt])
            dfs(data(xx.x,xx.y+1,0),cnt+2);
        }

    }
    if(xx.x==3)
    {
        if(!adj[xx.x][xx.y+1+cnt])
        {
           if(!adj[xx.x-1][xx.y+1+cnt])
                dfs(data(xx.x-1,xx.y+1,0),cnt+2);
                if(!adj[xx.x][xx.y+1+cnt])
            dfs(data(xx.x,xx.y+1,0),cnt+2);
        }

    }
    if(xx.x==2)
    {
        if(!adj[xx.x][xx.y+1+cnt])
        {
           if(!adj[xx.x+1][xx.y+1+cnt])
                dfs(data(xx.x+1,xx.y+1,0),cnt+2);
               if(!adj[xx.x][xx.y+1+cnt])
            dfs(data(xx.x,xx.y+1,0),cnt+2);
            if(!adj[xx.x-1][xx.y+1+cnt])
                dfs(data(xx.x-1,xx.y+1,0),cnt+2);

        }

    }

}


int main() {
   // READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs;//n,m;
    while(~getI(t))
    {
        rep(cs,t)
        {
            CLR(adj);
            CLR(mark);
            flag=0;
            getII(n,m);
            string a;
            rep(i,3)
            {
                cin>>a;
                debug(a)
                rep(j,a.size())
                {
                    if(a[j-1]=='.')
                        adj[i][j]=0;
                    else if(a[j-1]=='s')
                    {
                        adj[i][j]=0;
                        src=data(i,j,0);

                    }
                    else
                        adj[i][j]=1;
                }
            }
            dfs(src,0);
            if(flag)puts("YES");
            else puts("NO");

        }
    }




    return 0;
}
//1
//30 6
//..........................DDDD
//.............FF....CCEEEE.AAAA
//s...........BBBB..............