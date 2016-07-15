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
int dirx[]= {-1,-1,0,0,1,1};
int diry[]= {-1,0,-1,1,0,1};

int adj[205][205];
int mark[205][205];
int n;
bool check(int x,int y)
{
    if(x>=1&x<=n&&y<=n&&y>=1)return true;
    return false;
}
bool dfs(int srcx,int srcy)
{
    mark[srcx][srcy]=1;
    if(srcx==n)return true;
    bool flag=0;
    for(int i=0; i<6; i++)
    {
        int posx=srcx+dirx[i];
        int posy=srcy+diry[i];
        if(!mark[posx][posy]&&adj[posx][posy]&&check(posx,posy))
            flag|=dfs(posx,posy);
    }
    return flag;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs=1;//n,m;
    while(getI(n)&&n)
    {
        string x;
        CLR(adj);
        CLR(mark);
        rep(i,n)
        {
            cin>>x;
            repI(j,n)
            {
                if(x[j]=='b')
                    adj[i][j+1]=1;
            }
        }
        int flg=1;
        rep(i,n)
        {
            if(!mark[1][i]&&adj[1][i])
            {
                if(dfs(1,i))
                {
                    printf("%d B\n",cs++);
                    flg=0;
                    break;
                }

            }
        }
        if(flg)
            printf("%d W\n",cs++);
    }




    return 0;
}


