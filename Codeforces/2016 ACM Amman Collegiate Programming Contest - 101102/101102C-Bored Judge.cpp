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
#define MAX 100005
int arr[MAX];


pii tree[MAX*3];
pii call(pii a,pii b)
{
    pii tmp;
    tmp.ff=max(a.ff,b.ff);
    tmp.ss=INF;
    if(a.ff==tmp.ff)tmp.ss=min(tmp.ss,a.ss);
    if(b.ff==tmp.ff)tmp.ss=min(tmp.ss,b.ss);
    return tmp;
}
void init(int node,int b,int e)
{
 if(b==e)
 {
  tree[node].ff=0;
  tree[node].ss=b;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node]=call(tree[Left],tree[Right]);
}

void update(int node,int b,int e,int i,int newvalue)
{
 if (i > e || i < b) return;
 if (b >= i && e <= i) {
  tree[node].ff+=newvalue;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 update(Left,b,mid,i,newvalue);
 update(Right,mid+1,e,i,newvalue);
 tree[node]=call(tree[Left],tree[Right]);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        init(1,1,n);
        pii ans=MP(1,0);
        int flag=0;
        rep(i,m)
        {
            int a,b;
            getII(a,b);
            update(1,1,n,a,b);
            if(tree[1].ss!=ans.ff)
            {
//                flag++;
                ans=MP(tree[1].ss,i);
            }
//            debug(tree[1].ff,tree[1].ss,i,ans.ss)
        }
//        if(flag==)ans.ss=0;
        printf("%d\n",ans.ss);
    }


    return 0;
}