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
#define mx 300005

struct info
{
    int sum;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.sum=a.sum+b.sum;
    tmp.prop=0;
    return tmp;
}
void init(int node,int b,int e)
{
 if(b==e)
 {
     ///do something
     tree[node].sum=0;
     tree[node].prop=0;
  return;
 }
 int Left=node*2;
 int Right=node*2+1;
 int mid=(b+e)/2;
 init(Left,b,mid);
 init(Right,mid+1,e);
 tree[node]=call(tree[Left],tree[Right]);
}

void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop=0;
        return;
    }
 int Left=node<<1;
 int Right=(node<<1)+1;
 int mid=(b+e)>>1;
 ///update propagation
 tree[Left].prop=tree[node].prop;
 tree[Right].prop=tree[node].prop;
    tree[node].prop=0;
    ///update tree[left]
    tree[Left].sum=0;
    ///update tree[right]
    tree[Right].sum=0;

}

void update(int node,int b,int e,int i,int j,int val)
{
 if(tree[node].prop)propagate(node,b,e);
 if (i > e || j < b) return;
 if (b >= i && e <= j)
    {
        ///do something
        if(val)
        {
            tree[node].sum=1;
            tree[node].prop=0;
        }
        else
        {
            tree[node].sum=0;
            tree[node].prop=1;
        }
  return;
 }
 int Left=node*2;
 int Right=(node*2)+1;
 int mid=(b+e)/2;
 update(Left,b,mid,i,j,val);
 update(Right,mid+1,e,i,j,val);
 tree[node]=call(tree[Left],tree[Right]);
}
vector<pii> input;
map<int,int> mp;


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    while(~getII(n,m))
    {
        input.clear();
        mp.clear();

        init(1,1,mx-3);

        int cnt=0;
        rep(i,m)
        {
            int x,y;
            getII(x,y);
            input.PB(MP(x,y));
            if(x==2)
            {
                if(mp[y]==0)
                {
                    mp[y]=++cnt;
                }
            }
        }
//        debug("")
        queue<int> q[cnt+5];
        int cur=0;
        repI(i,m)
        {
            pii in=input[i];
            if(in.ff==1)
            {
                cur++;
                update(1,1,mx-3,cur,cur,1);
//                debug("");
                int pos=mp[in.ss];
                if(pos)q[pos].push(cur);
//                debug("")
            }
            else if(in.ff==2)
            {
                int pos=mp[in.ss];
                while(!q[pos].empty())
                {
                    int val=q[pos].front();q[pos].pop();
                    update(1,1,mx-3,val,val,0);
                }
            }
            else
            {
                update(1,1,mx-3,1,in.ss,0);
            }
            printf("%d\n",tree[1].sum);
        }

    }



    return 0;
}