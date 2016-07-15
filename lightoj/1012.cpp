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
int adj[25][25],mark[25][25];
int n,m,ans;
bool check(int posx,int posy)
{
    if(posx>0&&posx<=m&&posy>0&&posy<=n&&adj[posx][posy])
        return true;
    return false;
}
int dirx[]= {0,0,1,-1};
int diry[]= {1,-1,0,0};
void dfs(int srcx,int srcy)
{
    ans++;
    mark[srcx][srcy]=1;
    for(int i=0; i<4; i++)
    {
        int posx=srcx+dirx[i];
        int posy=srcy+diry[i];
        if(check(posx,posy)&&!mark[posx][posy])
            dfs(posx,posy);
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
        ans=0;
        getII(n,m);
        string s;
        CLR(adj);
        CLR(mark);
        int strtx,strty;
        rep(i,m)
        {
            cin>>s;
            rep(j,n)
            {
                if(s[j-1]=='.')adj[i][j]=1;
                if(s[j-1]=='@')
                {
                    adj[i][j]=1;
                    strtx=i;
                    strty=j;

                }
            }
        }

        dfs(strtx,strty);
        printf("Case %d: %d\n",cs,ans);
    }




    return 0;
}
