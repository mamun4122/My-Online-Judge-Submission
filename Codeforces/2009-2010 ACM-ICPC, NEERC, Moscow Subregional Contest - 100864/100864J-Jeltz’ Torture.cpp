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
vector<int> row[205],col[205];
string arr[205];

int main() {
    ///check for 0 or -1 if input not specified
//    #ifdef mamun
        READ("japanese.in");
        WRITE("japanese.out");
//    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>m)
    {
        repI(i,n)cin>>arr[i];
        int rowmx=1,colmx=1;
        repI(i,n)
        {
            int cur=0;
            repI(j,m)
            {
                if(arr[i][j]=='X')cur++;
                else
                {
                    if(cur)row[i].PB(cur);
                    cur=0;
                }
            }
            if(cur)row[i].PB(cur);
            rowmx=max(rowmx,(int)row[i].size());
        }
        repI(i,n)
        {
            reverse(ALL(row[i]));
            while(row[i].size()<rowmx)row[i].PB(0);
            reverse(ALL(row[i]));
        }
        repI(j,m)
        {
            int cur=0;
            repI(i,n)
            {
                if(arr[i][j]=='X')cur++;
                else
                {
                    if(cur)col[j].PB(cur);
                    cur=0;
                }
            }
            if(cur)col[j].PB(cur);
            colmx=max(colmx,(int)col[j].size());
        }
        repI(i,m)
        {
            reverse(ALL(col[i]));
            while(col[i].size()<colmx)col[i].PB(0);
            reverse(ALL(col[i]));
        }
        int nwrow=n+colmx,nwcol=m+rowmx;
//        debug(rowmx,colmx,nwrow,nwcol)
        repI(i,nwrow)
        {
            repI(j,nwcol)
            {
//                debug(i,j)
                if(i<colmx&&j<rowmx)cout<<"*";
                else if(i<colmx)
                {
                    if(col[j-rowmx][i])cout<<col[j-rowmx][i];
                    else cout<<"_";
                }
                else if(j<rowmx)
                {
                    if(row[i-colmx][j])cout<<row[i-colmx][j];
                    else cout<<"_";
                }
                else cout<<".";
            }
            cout<<endl;
        }
    }

    return 0;
}