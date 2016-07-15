#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)         (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta0
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

bool isLeap(int y)
{
    if(y%400==0) return true;
    if(y%100==0) return false;
    if(y%4==0) return true;
    return false;
}

int adj[1004][1004];
vector <pii> q,k;
int n,m;
//int tot;
void queen(int x,int y)
{
//    adj[x][y]=1;
    for(int i=x+1;i<=n;i++)
    {
        if(adj[i][y]==3) break;
//        tot++;
        adj[i][y]=1;
    }
    for(int i=x-1;i>0;i--)
    {
        if(adj[i][y]==3) break;
        adj[i][y]=1;
    }
    for(int i=y+1;i<=m;i++)
    {
        if(adj[x][i]==3) break;
        adj[x][i]=1;
    }
    for(int i=y-1;i>0;i--)
    {
        if(adj[x][i]==3) break;
        adj[x][i]=1;
    }
    for(int i=x+1,j=y+1;i<=n && j<=m;i++,j++)
    {
        if(adj[i][j]==3) break;
        adj[i][j]=1;
    }
    for(int i=x-1,j=y-1;i>0 && j>0;i--,j--)
    {
        if(adj[i][j]==3) break;
        adj[i][j]=1;
    }
    for(int i=x+1,j=y-1;i<=n && j>0;i++,j--)
    {
        if(adj[i][j]==3) break;
        adj[i][j]=1;
    }
    for(int i=x-1,j=y+1;i>0 && j<=m;i--,j++)
    {
        if(adj[i][j]==3) break;
        adj[i][j]=1;
    }
//    adj[x][y]=3;
}
int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {1,-1,-1,1,2,-2,-2,2};
void knight(int x,int y)
{
    FOR(i,0,7)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X>0 && Y>0 && X<=n && Y <=m && adj[X][Y]!=3)
        {
            adj[X][Y]=2;
        }
    }
}

int main() {
        //READ("in.txt");
        //WRITE("out.txt");
    int ci=1;
    while(~getII(n,m))
    {
        q.clear();
        k.clear();
        if(n==0 && m==0) break;
        CLR(adj);
        FOR(i,1,3)
        {
            int n;
            getI(n);
            FOR(j,1,n)
            {
                int x,y;
                getII(x,y);
                if(i==1)
                {
                    adj[x][y]=3;
                    q.PB(pii(x,y));
                }
                else if(i==2)
                {
                    adj[x][y]=3;
                    k.PB(pii(x,y));
                }
                else adj[x][y]=3;
            }
        }
        FOR(i,0,(int)q.size()-1)
        {
            queen(q[i].ff,q[i].ss);
        }
        FOR(i,0,(int)k.size()-1)
        {
            knight(k[i].ff,k[i].ss);
        }
        int cnt=0;
        FOR(i,1,n)
        {
            FOR(j,1,m)
            {
                if(adj[i][j]==0) cnt++;
            }
        }
        printf("Board %d has %d safe squares.\n",ci++,cnt);
    }

    return 0;
}



