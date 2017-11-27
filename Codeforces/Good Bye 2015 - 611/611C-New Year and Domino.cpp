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
int t,n,m;
int arr[505][505],mark[505][505],cum[505][505];
int rght[505][505],down[505][505];
pii a,b;
int ans;
bool check(int posx,int posy)
{
    if(posx>=1&&posy>=1&&posx<=n&&posy<=m&&arr[posx][posy])return true;
    return false;

}
int dirx[]= {0,1};
int diry[]= {1,0};

//void dfs(int posx,int posy)
//{
//    repI(i,4)
//    {
//        if(check(posx+dirx[i],posy+diry[i]))
//        {
//
//        }
//    }
//
//}

int main()
{
//    READ("out.txt");
//    WRITE("out1.txt");
//    while(cin>>n>>m)
//    {
       getII(n,m);
//        CLR(mark);
        CLR(mark);
        CLR(cum);CLR(rght);
        CLR(down);
        string s;
        rep(i,n)
        {
            cin>>s;
//            debug(s)
            repI(j,s.size())
            {
                if(s[j]=='.')arr[i][j+1]=1;
                else arr[i][j+1]=0;
            }
        }
        int q;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!arr[i][j])continue;
                repI(k,2)
                {
                    if(check(i+dirx[k],j+diry[k]))
                    {
//                            debug(i+dirx[k],j+diry[k])
//                        ans++;
                        if(diry[k])rght[i][j]++;
                        if(dirx[k])down[i][j]++;
                        mark[i][j]++;

                    }
                }
            }
        }
        rep(i,n)
        {
            rep(j,m)
            {
                cum[i][j]=mark[i][j]+cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1];
            }
        }
        getI(q);
        rep(x,q)
        {
            getII(a.ff,a.ss);
            getII(b.ff,b.ss);
            ans=0;
//            debug("*",cum[b.ff][b.ss],cum[b.ff][a.ss],cum[a.ff][b.ss])
            ans=cum[b.ff][b.ss]-cum[b.ff][a.ss-1]-cum[a.ff-1][b.ss]+cum[a.ff-1][a.ss-1];
//            cout<<ans<<endl;
//debug(ans)
            for(int i=a.ff;i<=b.ff;i++)
            {
                ans-=rght[i][b.ss];
            }
            for(int i=a.ss;i<=b.ss;i++)
            {
//                debug(b.ff,i,down[b.ff][i])
                ans-=down[b.ff][i];
            }

            printf("%d\n",ans);
        }
//    }





    return 0;
}