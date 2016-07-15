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
int n,m,adj[25][25],mark[25][25],dist[25][25],destx,desty;
bool check(int posx,int posy)
{
    if(posx>0&&posx<=n&&posy>0&&posy<=m&&adj[posx][posy])
        return true;
    return false;
}
int dirx[]= {0,0,1,-1};
int diry[]= {1,-1,0,0};
int bfs(int srcx,int srcy)
{
    dist[srcx][srcy]=0;
    queue<pair<int,int> >q;
    q.push(make_pair(srcx,srcy));
    while(!q.empty())
    {
        pair<int,int> pp=q.front();q.pop();
        if(pp.first==destx&&pp.second==desty)return dist[destx][desty];
        for(int i=0; i<4; i++)
        {
            int posx=pp.first+dirx[i];
            int posy=pp.second+diry[i];
            if(check(posx,posy)&&!mark[posx][posy])
            {
                mark[posx][posy]=1;
                dist[posx][posy]=dist[pp.first][pp.second]+1;
                q.push(make_pair(posx,posy));
            }
        }
    }

}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs;//,n,m;
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        CLR(adj);
        CLR(mark);
        int ax,ay,bx,by,cx,cy;
        rep(i,n)
        {
            string s;
            cin>>s;
            rep(j,m)
            {
                if(s[j-1]=='.')adj[i][j]=1;
                if(s[j-1]=='a')
                {
                    adj[i][j]=1;
                    ax=i;
                    ay=j;
                }
                if(s[j-1]=='b')
                {
                    adj[i][j]=1;
                    bx=i;
                    by=j;
                }
                if(s[j-1]=='c')
                {
                    adj[i][j]=1;
                    cx=i;
                    cy=j;
                }
                if(s[j-1]=='h')
                {
                    adj[i][j]=1;
                    destx=i;
                    desty=j;
                }

            }
        }
        int ans=-INF;
        CLR(mark);
        CLR(dist);
        //debug(destx,desty)
        ans=max(ans,bfs(ax,ay));
        //debug(ans,dist[destx][desty]);
        CLR(mark);
        CLR(dist);
        ans=max(ans,bfs(bx,by));
        CLR(mark);
        CLR(dist);
        ans=max(ans,bfs(cx,cy));
        printf("Case %d: %d\n",cs,ans);
    }




    return 0;
}


