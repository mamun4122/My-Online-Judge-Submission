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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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
int mark[505][505];
string s;
int x,y;
bool check(int xx,int yy)
{
    if(xx>0&&xx<=x&&yy>0&&yy<=y)return 1;
    return 0;
}

void dfs(int pos,int srcx,int srcy,int prevx,int prevy)
{
    if(pos==s.size())
    {
        int cnt=0;
        rep(i,x)
        {
            rep(j,y)
            {
                if(mark[i][j])cnt++;
            }
        }
        printf("%d\n",x*y-cnt);
        return;
    }
    if(!check(srcx,srcy))
    {
        printf("0 ");
        srcx=prevx;
        srcy=prevy;
        if(s[pos]=='L')dfs(pos+1,srcx,srcy-1,srcx,srcy);
        else if(s[pos]=='R')dfs(pos+1,srcx,srcy+1,srcx,srcy);
        else if(s[pos]=='U')dfs(pos+1,srcx-1,srcy,srcx,srcy);
        else dfs(pos+1,srcx+1,srcy,srcx,srcy);
        return;
    }
    else if(mark[srcx][srcy])printf("0 ");
    else printf("1 ");
    mark[srcx][srcy]=1;
    if(s[pos]=='L')dfs(pos+1,srcx,srcy-1,srcx,srcy);
    else if(s[pos]=='R')dfs(pos+1,srcx,srcy+1,srcx,srcy);
    else if(s[pos]=='U')dfs(pos+1,srcx-1,srcy,srcx,srcy);
    else dfs(pos+1,srcx+1,srcy,srcx,srcy);

}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    int a,b;
    while(~getIII(x,y,a))
    {
        CLR(mark);
        getI(b);
        cin>>s;
        dfs(0,a,b,0,0);

    }


    return 0;
}