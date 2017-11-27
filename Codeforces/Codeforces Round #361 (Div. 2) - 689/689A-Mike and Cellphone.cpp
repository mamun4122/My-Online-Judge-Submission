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
int arr[4][3]= {1,2,3,4,5,6,7,8,9,10,0,10};
vector<pii> v;
vector<int> org;
void calc(string st)
{
    org.clear();
    v.clear();
    repI(i,n)
    {
        org.push_back(st[i]-'0');
    }
    repI(i,n)
    {
        if(i==n-1)break;
        int x,y;
        repI(j,4)repI(k,3)if(arr[j][k]==org[i])
        {
            x=j;
            y=k;
            break;
        }
//        debug(org[i],x,y)
        repI(j,4)repI(k,3)if(arr[j][k]==org[i+1])
        {
            int xx=x-j;
            int yy=y-k;
            v.push_back(pii(xx,yy));
            break;
        }
    }
//    debug(st,v.size(),org.size())
//    repI(i,v.size())debug(v[i].ff,v[i].ss)
}
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<=2&&pos.ss>=0&&pos.ss<=2)return true;
    if(pos.ff==3&&pos.ss==1)return true;
    return false;
}

bool bfs(int src)
{
    pii cur;
    repI(j,4)repI(k,3)if(arr[j][k]==src)
    {
        cur.ff=j;
        cur.ss=k;
        break;
    }
//    debug("c",cur.ff,cur.ss)
    int flag;
    repI(i,v.size())
    {
        cur.ff-=v[i].ff;
        cur.ss-=v[i].ss;
//        debug("c",cur.ff,cur.ss)
        if(check(cur))continue;
        else return false;
    }
    return true;

}
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    while(~getI(n))
    {
        string st;
        cin>>st;
        if(n==1)
        {
            puts("NO");
            continue;
        }
        calc(st);
        int flag=1;
        repI(i,10)
        {
            if(org[0]==i)continue;
            int tmp=bfs(i);
            if(tmp)
            {
//                debug("sss",i)
                flag=0;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }




    return 0;
}