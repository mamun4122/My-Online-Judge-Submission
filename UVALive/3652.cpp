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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

int cost[5][5]= {{7,6,5,6,7},
    {6,3,2,3,6},
    {5,2,0,2,5},
    {6,3,2,3,6},
    {7,6,5,6,7}
};


#define mx 1010
int adj[1010][1010];
//vectorg[mx],cost[mx];
struct node
{
    int u,v,w;
    node(int a,int c,int b)
    {
        u=a;
        v=c;
        w=b;
    }
    bool operator < ( const node &p ) const
    {
        return w > p.w;
    }
};
int d[mx][mx];//par[mx][mx];
int col,row;
bool check(int x,int y)
{
    if(x>0&&x<=row&&y>0&&y<=col)return true;
    return false;
}
int dijkstra(int srcx,int srcy,int destx,int desty)
{
    memset(d,63,sizeof(d));
    //memset(par,-1,sizeof(par));
    priority_queue<node>q;
    q.push(node(srcx,srcy,0));
    d[srcx][srcy]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int u=top.u;
        int v=top.v;
        //debug(u,v);

        if(u==destx&&v==desty) return d[destx][desty];
        for(int i=-2,m=0; i<=2;m++, i++)
        {
            for(int j=-2,n=0; j<=2;n++, j++)
            {
                if(!check(u+i,v+j))continue;
                if(adj[u+i][v+j]==0&&!(m==2&&n==2))
                {
                    //debug("*");
                    if(d[u][v]+cost[m][n]<d[u+i][v+j])
                    {
                        d[u+i][v+j]=d[u][v]+cost[m][n];
                        q.push(node(u+i,v+j,d[u+i][v+j]));
                    }
                }
            }
        }

        /*for(int i=-2;i<=2;i++)
        {
            for(int )
            int v=g[u][i];
            if(d[u]+cost[u][i]&lt;d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }*/
    }
    return -1;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    while(~getII(col,row)&&(col||row))
    {
        int srcx,srcy,destx,desty;
        getII(srcy,srcx);
        getII(desty,destx);
        int t;
        getI(t);
        CLR(adj);
        while(t--)
        {
            int a,b,c,d;
            getII(a,b);
            getII(c,d);
            for(int i=a; i<=c; i++)
                for(int j=b; j<=d; j++)
                    adj[j][i]=-1;
        }/*
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
*/
        int ret=dijkstra(srcx,srcy,destx,desty);
        if(ret==-1) puts("impossible");
        else printf("%d\n",ret);
    }

}
