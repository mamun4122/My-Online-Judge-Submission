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
int t,n,m,k;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

ll cnt[A];
int pref[N], a[N];
ll ans[N];
ll answer = 0;

struct node
{
    int L, R, i;
} q[N];

bool cmp(node x, node y)
{
    if(x.L/BLOCK != y.L/BLOCK)
    {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int position)
{
//    debug(position,pref[position],pref[position]^k,cnt[pref[position]^k])
    answer+=cnt[ pref[position]^k ];
//    answer+=(a[position]==k);
    cnt[pref[position]]++;
}

void remove(int position)
{
//    debug("")
    cnt[pref[position]]--;
//    answer-=(a[position]==k);
    answer-=cnt[pref[position]^k];
}
///  sqrt-decomposion by anudeep
int main()
{

    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getIII(n,m,k))
    {
        CLR(a);answer=0;CLR(cnt);

        rep(i,n)getI(a[i]);
//        pref[1]=a[1];
        rep(i,n)pref[i]=a[i]^pref[i-1];

//        rep(i,n)debug(pref[i]);
        repI(i,m)
        {
            getII(q[i].L,q[i].R);
            q[i].L--;
//            q[i].R--;
            q[i].i = i;
        }

        sort(q, q + m, cmp);

        int currentL = 0, currentR = 0;
        repI(i,m)
        {
            int L = q[i].L, R = q[i].R;
//            debug(currentL,currentR,L,R,q[i].i)
            while(currentL < L)
            {
                remove(currentL);
                currentL++;
            }
            while(currentL > L)
            {
                add(currentL-1);
                currentL--;
            }
            while(currentR <= R)
            {
                add(currentR);
                currentR++;
            }
            while(currentR > R+1)
            {
                remove(currentR-1);
                currentR--;
            }
            ans[q[i].i] = answer;
        }
        repI(i,m)printf("%lld\n", ans[i]);
    }
}