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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
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
#define mx 100001
int arr[mx];


int tree[mx*3];

void init(int node,int b,int e)
{
 if(b==e)
 {
  tree[node]=arr[b];
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node]=gcd(tree[Left],tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
 if (i > e || j < b) return 0;
 if (b >= i && e <= j) return tree[node];
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 int p1=query(Left,b,mid,i,j);
 int p2=query(Right,mid+1,e,i,j);
 return gcd(p1,p2);
}
vector<pii> v;

int findlow(pii num)
{
    int ans=-1;
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid].ff>num.ff)high=mid-1;
        else if(v[mid].ff<num.ff)low=mid+1;
        else if(v[mid].ss<num.ss)low=mid+1;
        else
        {
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
int findhigh(pii num)
{
    int ans=-1;
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid].ff>num.ff)high=mid-1;
        else if(v[mid].ff<num.ff)low=mid+1;
        else if(v[mid].ss>num.ss)high=mid-1;
        else
        {
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(n);
    rep(i,n)getI(arr[i]);
    rep(i,n)v.push_back(MP(arr[i],i));
    sort(ALL(v));
    init(1,1,n);
    getI(m);
    rep(i,m)
    {
        int l,r;
        getII(l,r);
        int num=query(1,1,n,l,r);
        int lft=findlow(MP(num,l));
        int rght=findhigh(MP(num,r));
//        debug(lft,rght)
        int tot=0;
        if(lft!=-1&&rght>=lft)tot=rght-lft+1;
        printf("%d\n",r-l+1-tot);
    }



    return 0;
}