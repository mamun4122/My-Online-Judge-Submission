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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
string arr[55];
int mark[55][55];
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
bool check(pii pos)
{
    if(pos.ff>=0&&pos.ff<n&&pos.ss>=0&&pos.ss<m)return true;
    return false;
}
bool lake(pii src)
{
    mark[src.ff][src.ss]++;
    bool res=true;
    if(src.ff==0||src.ss==0||src.ff==n-1||src.ss==m-1)res=false;
    repI(i,4)
    {
        pii pos;
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&arr[pos.ff][pos.ss]=='.'&&mark[pos.ff][pos.ss]==0)
        {
            res&=lake(pos);
        }
    }
    return res;
}
int  dfs(pii src)
{
    mark[src.ff][src.ss]++;
//    if(src.ff==0||src.ss==0||src.ff==n-1||src.ss==m-1)return false;
    int res=1;
    repI(i,4)
    {
        pii pos;
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&arr[pos.ff][pos.ss]=='.'&&mark[pos.ff][pos.ss]==1)
        {
            res+=dfs(pos);
        }
    }
    return res;
}
void fillup(pii src)
{
    mark[src.ff][src.ss]++;
    arr[src.ff][src.ss]='*';
//    if(src.ff==0||src.ss==0||src.ff==n-1||src.ss==m-1)return false;
//    bool res=true;
    repI(i,4)
    {
        pii pos;
        pos.ff=src.ff+dirx[i];
        pos.ss=src.ss+diry[i];
        if(check(pos)&&arr[pos.ff][pos.ss]=='.'&&mark[pos.ff][pos.ss]==2)
        {
            fillup(pos);
        }
    }
//    return res;
}
vector<pair<int,pii> >v;

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getII(n,m))
    {
        v.clear();
        CLR(mark);

        int k;
        getI(k);
        int tot=0;
        repI(i,n)cin>>arr[i];

        repI(i,n)
        {
            repI(j,m)
            {
                if(arr[i][j]=='*')continue;
                if(mark[i][j]>0)continue;
                if(lake(pii(i,j)))
                {
                    tot++;
                    int num=dfs(pii(i,j));
                    v.push_back(MP(num,pii(i,j)));
                }
            }
        }
        sort(ALL(v));
        int ans=0;
        int cur=0;
//        CLR(mark);
        while(tot>k)
        {
            tot--;
            ans+=v[cur].ff;
            fillup(v[cur].ss);
            cur++;
        }
        printf("%d\n",ans);
        repI(i,n)cout<<arr[i]<<endl;

    }

    return 0;
}