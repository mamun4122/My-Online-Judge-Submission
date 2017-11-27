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
#define mamu
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
int arr[20][20];
int mark[20][20][4];
int n,m,strtx,strty,ans;
void dfs(int x,int y,int dir)
{
    arr[x][y]=2;
    //debug(x,y)
    for(int i=0; i<4; i++)
    {
        int posx=x;
        int posy=y;
        int d=i+dir;
        d%=4;
        debug(d)
        if(d==0)posx--;
        if(d==1)posy++;
        if(d==2)posx++;
        if(d==3)posy--;
        debug(posx,posy,d)
        if(posx<0||posx>=n||posy<0||posy>=m)continue;
        if(arr[posx][posy]!=-1&&mark[posx][posy][d]==1)
            return;
        else if(arr[posx][posy]!=-1&&mark[posx][posy][d]==0)
        {
            mark[posx][posy][d]=1;
            if(arr[posx][posy]==1){
                ans++;
                debug("m")
            }
            dfs(posx,posy,d);
            break;
        }
    }
}

int main()
{
   // READ("in.txt");
    //WRITE("out.txt");

    while(~getII(n,m))
    {
        SET(arr);
        CLR(mark);
        string s;
        int dir=0;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            //debug(s);
            for(int j=0; j<m; j++)
            {
                if(s[j]=='.')
                    arr[i][j]=1;
                else if(s[j]!='*')
                {
                    if(s[j]=='U')dir=0;
                    if(s[j]=='R')dir=1;
                    if(s[j]=='D')dir=2;
                    if(s[j]=='L')dir=3;
                    arr[i][j]=1;
                    strtx=i;
                    strty=j;
                }
            }
        }
        ans=1;
        dfs(strtx,strty,dir);
        cout<<ans<<endl;
    }
    return 0;
}