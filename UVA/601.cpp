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
int n,adj[90][90],mark[90][90];
bool white,black;
int dirx[]= {0,0,1,-1};
int diry[]= {1,-1,0,0};
bool check(int srcx,int srcy,int cmp)
{
    if(srcx>0&&srcx<=n&&srcy>0&&srcy<=n&&mark[srcx][srcy]==0&&adj[srcx][srcy]==cmp)
        return true;
    return false;
}

void dfs(int srcx,int srcy,int cmp)
{
    if(white||black)return;
    mark[srcx][srcy]=1;
    if(cmp==1&&srcy==n)
    {
        white=true;
        return;
    }
    if(cmp==2&&srcx==n)
    {
        black=true;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int posx=srcx+dirx[i];
        int posy=srcy+diry[i];
        if(check(posx,posy,cmp))
        {
            dfs(posx,posy,cmp);
        }
    }


}



int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,t,cs;//n,m;
    while(~getI(n)&&n)
    {
        //  debug(n);
        string s;
        CLR(adj);
        black=white=false;
        rep(i,n)
        {
            cin>>s;
            rep(j,n)
            {
                if(s[j-1]=='W')
                    adj[i][j]=1;
                if(s[j-1]=='U')
                    adj[i][j]=3;
                if(s[j-1]=='B')
                    adj[i][j]=2;

            }
        }
        CLR(mark);
        rep(i,n)
        {
            if(white)break;
            if(adj[i][1]==1&&mark[i][1]==0)
            {
                dfs(i,1,1);
            }
        }
        if(white)
        {
            puts("White has a winning path.");
            continue;
        }
        CLR(mark);
        rep(i,n)
        {
            if(black)break;
            if(adj[1][i]==2&&mark[1][i]==0)
            {
                dfs(1,i,2);
            }
        }
        if(black)
        {
            puts("Black has a winning path.");
            continue;
        }
        rep(i,n)
        {
            rep(j,n)
            {
                if(adj[i][j]==3)
                {
                    adj[i][j]=1;
                    CLR(mark);
                    rep(t,n)
                    {
                        if(white)break;
                        if(adj[t][1]==1&&mark[t][1]==0)
                        {
                            dfs(t,1,1);
                        }
                    }
                    if(white)break;
                    adj[i][j]=3;
                }
            }
            if(white)break;
        }
        rep(i,n)
        {
            rep(j,n)
            {
                if(adj[i][j]==3)
                {

                    adj[i][j]=2;
                    CLR(mark);
                    rep(t,n)
                    {
                        if(black)break;
                        if(adj[1][t]==2&&mark[1][t]==0)
                        {
                            dfs(1,t,2);
                        }
                    }
                    if(black)break;
                    adj[i][j]=3;
                }
            }
            if(white||black)break;
        }
        if(white)
            puts("White can win in one move.");
        else if(black)
            puts("Black can win in one move.");
        else
            puts("There is no winning path.");

    }





    return 0;
}


