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
int ans[5][5]=
{
    {1,1,1,1,1},
    {0,1,1,1,1},
    {0,0,-1,1,1},
    {0,0,0,0,1},
    {0,0,0,0,0}
};
int dirx[]= {1,1,2,2,-1,-1,-2,-2};
int diry[]= {2,-2,1,-1,2,-2,1,-1};
char input[5][5];
int arr[5][5];
int res=0;
int check()
{
    int cnt=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(arr[i][j]!=ans[i][j])cnt++;
        }
    }
    return cnt;
}
int flag;
stack<pair<int,int> > pos;
int IDA_Search(int movecnt,int posx,int posy,int bound,int prevx,int prevy)
{
    int goal=check();
    int f=movecnt+goal;
    if(f>bound)return f;
    if(goal==0)
    {
        flag=1;
        return goal;
    }
    int mn=1000;
    for(int i=0; i<8; i++)
    {
        int xx=posx+dirx[i];
        int yy=posy+diry[i];
        if(xx<0||xx>=5||yy<0||yy>=5||(xx==prevx&&yy==prevy))continue;
        swap(arr[xx][yy],arr[posx][posy]);
        int t=IDA_Search(movecnt+1,xx,yy,bound,posx,posy);
        if(flag)
        {
            res++;
            return goal;
        }
        swap(arr[xx][yy],arr[posx][posy]);
        if(t<mn)mn=t;
    }
    return mn;
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
        WRITE("out.txt");
#endif // mamun
    getI(t);
    getchar();
    rep(cs,t)
    {
        CLR(arr);
        for(int i=0; i<5; i++)gets(input[i]);
        int strtx,strty;
        flag=0;
        res=0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(input[i][j]==' ')
                {
                    arr[i][j]=-1;
                    strtx=i;
                    strty=j;
                }
                else arr[i][j]=input[i][j]-48;
            }
        }
//        debug(strtx,strty)
        int bound=check();
        while(1)
        {
            if(bound>16)break;
            bound=IDA_Search(0,strtx,strty,bound,-1,-1);
//        debug(bound)
            if(flag)
            {
                break;
            }
        }
        int sz=res;
//        while(!pos.empty())pos.pop();
        if(sz>=16||flag==0)printf("Case %d: Unsolvable in less than 16 move(s).\n",cs);
        else printf("Case %d: Solvable in %d move(s).\n",cs,sz);

    }

    return 0;
}
