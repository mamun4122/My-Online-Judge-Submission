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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

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
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
int t,n,m;
int arr[15][15];
int dirx[]= {1,0,1};
int diry[]= {0,1,1};
int mark[15][15];
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<10&&pos.ss>=0&&pos.ss<10)return true;
    return false;
}

int flag;
int ans[105];
void dfs(pii src,int tot,int dir)
{
    mark[src.ff][src.ss]=1;
    if(tot>4)
    {
        flag=1;
        return;
    }
//    int flg=1;
    int cnt=0;
    repI(i,3)
    {
        pii pos;
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&arr[pos.ff][pos.ss]==1)
        {
            if(i==2)
            {
                flag=1;
                return;
            }
            cnt++;
        }
    }
    if(cnt==2)
    {
        flag=1;
        return;
    }
    repI(i,2)
    {
        pii pos;
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&arr[pos.ff][pos.ss]==1)
        {
            if(mark[pos.ff][pos.ss]==1)
            {
                flag=1;
                return;
            }
            if(dir==2||dir==i)
            {
//                flg=0;
                dfs(pos,tot+1,i);
            }
            else
            {
                flag=1;
                return;
            }

        }
    }
    if(cnt==0)ans[tot]++;

}

int main()
{
    ///check for 0 or -1 if input not specified
//#ifdef mamun
    READ("sea.in");
    WRITE("sea.out");
//#endif // mamun
    getI(t);
    rep(cs,t)
    {
        CLR(ans);
        CLR(mark);
        CLR(arr);
        repI(i,10)
        {
            string st;
            cin>>st;
            repI(j,10)
            {
                if(st[j]=='*')arr[i][j]=1;
            }
        }
        flag=0;
        repI(i,10)repI(j,10)
        {
            if(arr[i][j]&&mark[i][j]==0)
            {
                dfs(pii(i,j),1,2);
//                debug(i,j,flag)
            }
        }
        if(flag)
        {
            puts("NO");
            continue;
        }
        if(ans[4]==1&&ans[3]==2&&ans[2]==3&&ans[1]==4)puts("YES");
        else puts("NO");
    }



    return 0;
}