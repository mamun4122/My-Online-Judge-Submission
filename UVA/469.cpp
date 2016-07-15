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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
int t,n,m;
int sz[100];
bool check(int row,int col)
{
    if(row<0||row>=n||col<0)return false;
    if(col>=sz[row])return false;
    return true;
}
string adj[100];
int mark[100][100];
int ans;
int dirx[]={1,1,1,-1,-1,-1,0,0};
int diry[]={-1,0,1,-1,0,1,1,-1};

void dfs(int srcx,int srcy)
{
    ans++;
    mark[srcx][srcy]=1;
    repI(i,8)
    {
        int posx=dirx[i]+srcx;
        int posy=diry[i]+srcy;
        if(check(posx,posy)&&mark[posx][posy]==0&&adj[posx][posy]=='W')
            dfs(posx,posy);

    }
}

int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    getchar();
    string vua;
    getline(cin,vua);
    rep(cs,t)
    {
        CLR(sz)
        if(cs>1)puts("");
        n=0;
        while(getline(cin,adj[n])&&!isdigit(adj[n][0]))
        {
            if(adj[n].empty())break;
            sz[n]=adj[n].size();
            n++;
        }
        vua=adj[n];
        while(!vua.empty())
        {
            stringstream ss(vua);
            int a,b;
            ss>>a>>b;
            a--;
            b--;
            ans=0;
            CLR(mark);
            dfs(a,b);
            printf("%d\n",ans);
            getline(cin,vua);
        }




    }




    return 0;
}


