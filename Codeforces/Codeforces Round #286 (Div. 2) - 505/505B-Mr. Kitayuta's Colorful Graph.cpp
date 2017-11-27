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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
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
//******************DELETE****************
int adj[101][101][101];
int node,dest;
bool flag;
int color[101];
void dfs(int n,int colr)
{
    if(n==dest)flag=true;
    if(flag)return;
    color[n]=1;
    for(int i=1;i<=node;i++)
    {
        if(adj[n][i][colr]==1&&!color[i])
        {
            dfs(i,colr);
            if(flag)return;
        }
    }
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int m;
    CLR(adj);
    set<int> s[101];
    getII(node,m);
    int a,b,c;
    for(int i=1;i<=m;i++){
        getIII(a,b,c);
        adj[a][b][c]=1;
        adj[b][a][c]=1;
        s[a].insert(c);
        s[b].insert(c);
    }
    int q;
    getI(q);
    set<int> ::iterator it;
    set<int> chk;
    for(int i=1;i<=q;i++)
    {

        getII(a,b);
        dest=b;
        int cnt=0;
        for(it=s[a].begin();it!=s[a].end();it++ )
        {
            flag=0;
            CLR(color);
            dfs(a,*it);
            if(flag)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}