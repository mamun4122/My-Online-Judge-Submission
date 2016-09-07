#pragma comment(linker, "/stack:640000000")

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
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
int t,n,m;
#define mx 100105

bool color[mx];
int cnt;
vector<int>adj[mx];

typedef pair<pii,int> piii;

int dist[mx],dist1[mx];
bool mark[mx];
bool mark1[mx];
int mxi,strt;
queue<int>q;
int vua;
void dfs1(int src)
{
    mark[src]=1;
    cnt++;
    dist[src]=0;
    q.push(src);
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        repI(i,adj[src].size())
        {
            int v=adj[src][i];
            if(mark[v]==0)
            {
                mark[v]=1;
                cnt++;
                dist[v]=dist[src]+1;
                q.push(v);
            }
        }

        if(dist[src]>mxi)
        {
            mxi=dist[src];
            strt=src;
        }
    }
}
void dfs2(int src)
{
    mark1[src]=1;
    q.push(src);
    dist1[src]=0;
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        repI(i,adj[src].size())
        {
            int v=adj[src][i];
            if(mark1[v]==0)
            {
                mark1[v]=1;
                dist1[v]=dist1[src]+1;
                q.push(v);
            }
        }
        if(dist1[src]>mxi)
        {
            mxi=dist1[src];
            strt=src;
        }
    }
}

int finddiameter(int src)
{
    ///1st dfs
    mxi=0;
    dfs1(src);

    ///2nd dfs
    mxi=0;
    dfs2(strt);

    return mxi;
}

vector<int> dia;
int diam[mx];

int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
//    WRITE("out.txt");
//    debug(",",mark[86460])
    getI(t);
    rep(cs,t)
    {
        vua=cs;
        debug(cs)
        getII(n,m);

        ///clear
        rep(i,n)adj[i].clear();
        dia.clear();
        CLR(color);
        cnt=0;
        CLR(diam);
        CLR(mark);
        CLR(dist);
        CLR(mark1);
        CLR(dist1);

        rep(i,m)
        {
            int a,b;
            getII(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnctd=0;
        int maxdia=0,maxcnc=0;

        rep(i,n)
        {
            cnt=0;
            if(!mark[i])
            {
                int diameter=finddiameter(i);

                if(diameter>diam[cnt])
                {
                    if(diam[cnt]==0)dia.push_back(cnt);
                    diam[cnt]=diameter;
                }
                if(cnt>cnctd)
                {
                    cnctd=cnt;
                }
                if(diameter>maxdia)maxdia=diameter;
            }
        }
        sort(ALL(dia));

        int q;
        getI(q);

        printf("Case %d:\n",cs);

        int sz=dia.size();
        rep(i,q)
        {
            int a;
            getI(a);

            if(a==1)puts("0");
            else if(a>cnctd)puts("impossible");
            else if(a<=maxdia+1)printf("%d\n",a-1);
            else
            {
                int prev=diam[dia[sz-1]];
                for(int j=sz-1; j>=0; j--)
                {
                    if(a>dia[j])break;
                    if(diam[dia[j]]>prev)prev=diam[dia[j]];

                }
                printf("%d\n",prev+(a-prev-1)*2);
            }
        }
    }
    return 0;
}

