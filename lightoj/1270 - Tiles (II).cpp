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
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
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
int arr[105][105];
int masks[105];//[(1<<8)+4];
char str[105];
ull dp[105][10][(1<<8)+5][3];
int mark[105][10][(1<<8)+5][3],ci;
ull call(int row,int col,int mask,int flag=0)
{
//    debug(row,col,mask)
    if(row==n)return (__builtin_popcount(mask)==0?1:0);
    ull &ret=dp[row][col][mask][flag];
    if(mark[row][col][mask][flag]==ci)return ret;
    mark[row][col][mask][flag]=ci;
    ull ans=0;
    if(col==m)return ret=call(row+1,0,(mask|masks[row+1]));
    else if(flag)
    {
        ///tiles 2
        if(col<m-1&&bitCheck(mask,col+1)==0)
            ans+=call(row,col+2,mask);
        ///tiles 6
        if(col<m-1&&bitCheck(mask,col+1)==0&&bitCheck(masks[row+1],col+1)==0)
            ans+=call(row,col+2,bitOn(mask,col+1));
    }
    else if(bitCheck(mask,col)==1)return ret=call(row,col+1,bitOff(mask,col));
    else
    {
        ///tiles 1
        if(bitCheck(mask,col)==0&&bitCheck(masks[row+1],col)==0)
            ans+=call(row,col+1,bitOn(mask,col));
        ///tiles 2
        if(col<m-1&&bitCheck(mask,col)==0&&bitCheck(mask,col+1)==0)
            ans+=call(row,col+2,mask);
        ///tiles 3
        if(bitCheck(mask,col)==0&&bitCheck(masks[row+1],col)==0&&col<m-1&&bitCheck(masks[row+1],col+1)==0)
        {
            int tmp=bitOn(mask,col);
            if(bitCheck(mask,col+1)==0)
                ans+=call(row,col+1,bitOn(tmp,col+1),1);
            else
                ans+=call(row,col+2,bitOn(tmp,col+1));
        }
        ///tiles 4
        if(col<m-1&&bitCheck(mask,col)==0&&bitCheck(mask,col+1)==0&&bitCheck(masks[row+1],col)==0)
            ans+=call(row,col+2,bitOn(mask,col));
        ///tiles 5
        if(col&&bitCheck(mask,col-1)==0&&bitCheck(mask,col)==0&&bitCheck(masks[row+1],col)==0&&bitCheck(masks[row+1],col-1)==0)
        {
            int tmp=bitOn(mask,col);
            ans+=call(row,col+1,bitOn(tmp,col-1));

        }
        ///tiles 6
        if(col<m-1&&bitCheck(mask,col)==0&&bitCheck(mask,col+1)==0&&bitCheck(masks[row+1],col+1)==0)
            ans+=call(row,col+2,bitOn(mask,col+1));
    }
    return ret=ans;
}
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
 //   READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    CLR(mark);
    rep(cs,t)
    {
        ci=cs;
        CLR(masks);
        CLR(arr);
//        SET(dp);
//        debug(dp[0][0][0])
        getII(n,m);
        getchar();
        repI(i,n)
        {
            gets(str);
            repI(j,m)
            {
                if(str[j]=='#')arr[i][j]=1;
            }
        }
        if(m<=n)
        {
            repI(i,n)
            {
                repI(j,m)if(arr[i][j])masks[i]=bitOn(masks[i],j);
            }
        }
        else
        {
            repI(j,m)repI(i,n)if(arr[i][j])masks[j]=bitOn(masks[j],i);
            swap(n,m);
        }
//        debug(n,m)
//        repI(i,n)debug(masks[i])
        printf("Case %d: %llu\n",cs,call(0,0,masks[0]));

    }




    return 0;
}
