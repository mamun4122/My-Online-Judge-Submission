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

vector<int> edge[100010];
int arr[100010];
int mark[100010];
int n,m;
int dfs(int node,int cat)
{
    mark[node]=1;
    if(cat>m)return 0;
    int ans=0,flg=1;
    for(int i=0; i<edge[node].size(); i++)
    {
        int go=edge[node][i];
        if(!mark[go])
        {
            flg=0;
            if(arr[node]&&arr[edge[node][i]]&&cat<=m)
                ans=ans+dfs(edge[node][i],cat+1);
            else if(cat<=m)
                ans=ans+dfs(edge[node][i],arr[edge[node][i]]);
        }
    }
    if(flg)return 1;
    return ans;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    while(~getII(n,m))
    {
        for(int i=1; i<=n; i++)
        {
            getI(arr[i]);
        }
        int x,y;
        for(int i=1; i<n; i++)
        {
            getII(x,y);
            edge[x].push_back(y);
            edge[y].push_back(x);

        }
        int ans=dfs(1,arr[1]);
        //9debug("2");
        printf("%d\n",ans);
        for(int i=1; i<=n; i++)
            edge[i].clear();
        CLR(arr);
        CLR(mark);
    }




    return 0;
}