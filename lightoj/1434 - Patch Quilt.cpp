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
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
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
char arr[35][35];
char finding[35];
vector<string> res;
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<n&&pos.ss>=0&&pos.ss<m)return true;
    return false;
}
int dirx[]= {0,0,0,1,-1,-1,1,-1,1};
int diry[]= {0,-1,1,0,0,-1,-1,1,1};
string poss[]= {"*","L","R","D","U","UL","DL","UR","DR"};
int flag;
int mark[35][35][35];
int tc;
void dfs(pii src,int cur)
{
    if(mark[src.ff][src.ss][cur]==tc)return;
    mark[src.ff][src.ss][cur]=tc;
//    debug(src.ff,src.ss,cur,arr[src.ff][src.ss],finding[cur])
    if(cur==strlen(finding))
    {
        flag=1;
        return;
    }
    repI(i,9)
    {
        pii pos;

        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];

        if(check(pos)&&arr[pos.ff][pos.ss]==finding[cur])
        {
//            debug("")
//            debug(i,src.ff,src.ss,pos.ff,pos.ss,cur,arr[pos.ff][pos.ss],finding[cur])
            res.push_back(poss[i]);
            dfs(pos,cur+1);
//            if(flag)debug(pos.ff,pos.ss,poss[i])
            if(flag)return;
            res.pop_back();

        }
    }
//    debug("");
}


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    CLR(mark);
    tc=0;
    rep(cs,t)
    {
        getII(n,m);
        getchar();
        repI(i,n)gets(arr[i]);
        printf("Case %d:\n",cs);
        int q;
        getI(q);
        getchar();
        repI(k,q)
        {
            tc++;
            flag=0;
            gets(finding);
//            debug(finding)
            res.clear();
            pii strt;
            repI(i,n)
            {
                repI(j,m)
                {
                    if(arr[i][j]==finding[0])
                    {
                        strt=MP(i+1,j+1);
//                        debug(i,j)
                        dfs(MP(i,j),1);
//                        puts("");
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)
            {
                printf("%s found: (%d,%d)",finding,strt.ff,strt.ss);
                repI(i,res.size())printf(", %s",res[i].c_str());
                puts("");
            }
            else
            {
                printf("%s not found\n",finding);
            }

        }
    }



    return 0;
}

