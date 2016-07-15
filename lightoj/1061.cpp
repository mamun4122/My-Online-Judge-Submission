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
int board[8][8];
int soln[100][8];
int tot=0;

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}



bool isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        if (board[row][i]&&i!=col)
            return false;
    }
    for(int i=0; i<8; i++)
    {
        if(i==row)continue;
        for(int j=0; j<8; j++)
        {
            if(j==col)continue;
            if(abs(row-i)==abs(col-j)&&board[i][j])
                return false;
        }
    }

    return true;
}


void solveNQUtil(int col)
{
    if(col==8)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if(board[i][j])
                    soln[tot][i]=j;
            }
        }
        tot++;
        return;
    }
    for(int i=0; i<8; i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            solveNQUtil(col+1);
            board[i][col]=0;
        }
    }
}
pii pos[10];
int dp[1<<10];//[10];
int cost(pii a,pii b)
{
    if(a.ff==b.ff&&a.ss==b.ss)return 0;
    if(a.ff==b.ff||a.ss==b.ss)return 1;
    if(abs(a.ff-b.ff)==abs(a.ss-b.ss))return 1;
    return 2;
}

int call(int solnindx,int ind,int mask)
{
    if(__builtin_popcount(mask)==8)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    int ans=INF;
    repI(i,8)
    {
        if(check(mask,i)==0)
        {
            int val=cost(pos[i],make_pair(ind,soln[solnindx][ind]));
            ans=min(ans,call(solnindx,ind+1,Set(mask,i))+val);
        }
    }
    return ret=ans;
}


int main()
{
//    READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    CLR(board);
    solveNQUtil(0);
//    debug(tot);

    getI(t);
    rep(cs,t)
    {
        int t=0;
        string s;
        repI(i,8)
        {
            cin>>s;
            repI(j,8)
            {
                if(s[j]=='q')
                    pos[t++]=make_pair(i,j);
            }
        }
        int ans=INF;
        for(int i=0;i<92;i++)
        {
            SET(dp);
            ans=min(ans,call(i,0,0));
        }
        printf("Case %d: %d\n",cs,ans);
    }



    return 0;
}

