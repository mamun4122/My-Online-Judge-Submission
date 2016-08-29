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
const int INF = 850350000;
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

#define mx 100005
ll arr[mx];
struct info
{
    ll lazy;
    ll bestlazy;
    ll totsum;
    ll bestsum;
} tree[mx*4];
void init(int node,int b,int e)
{
    if(b==e)
    {
        ///do something
        tree[node].lazy=tree[node].bestlazy=0LL;
        tree[node].totsum=tree[node].bestsum=0LL;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].lazy=tree[node].bestlazy=0LL;
    tree[node].totsum=tree[node].bestsum=0LL;
}
void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].lazy=tree[node].bestlazy=0LL;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ///update tree[left]
    tree[Left].bestlazy=max(tree[Left].bestlazy,tree[Left].lazy+tree[node].bestlazy);
    tree[Left].lazy+=tree[node].lazy;
    tree[Left].bestsum=max(tree[Left].bestsum,tree[Left].totsum+tree[node].bestlazy);
    tree[Left].totsum+=tree[node].lazy;
    ///update tree[right]
    tree[Right].bestlazy=max(tree[Right].bestlazy,tree[Right].lazy+tree[node].bestlazy);
    tree[Right].lazy+=tree[node].lazy;
    tree[Right].bestsum=max(tree[Right].bestsum,tree[Right].totsum+tree[node].bestlazy);
    tree[Right].totsum+=tree[node].lazy;
    ///update tree[node]
    tree[node].lazy=tree[node].bestlazy=0LL;

}
ll query(int node,int b,int e,int i,int j)
{
    propagate(node,b,e);
    if (i > e || j < b)return 0LL;
    if(b>=i && e<=j)
    {
        ///do something
        return tree[node].bestsum;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  max(p1,p2);

}

void update(int node,int b,int e,int i,int j,int val)
{
    propagate(node,b,e);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        ///do something
        tree[node].lazy+=val;
        tree[node].bestlazy=max(tree[node].bestlazy,tree[node].lazy);
        tree[node].totsum+=val;
        tree[node].bestsum=max(tree[node].bestsum,tree[node].totsum);
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,val);
    update(Right,mid+1,e,i,j,val);
    /** aikhan e mone hoite pare jog kora drkr silo bt amra 1ta range k
    k node hisebe nitese r upor thek val eshe niche update kore gese
    so lft er val gula rght eo namsilo...so sudu max nibo amra nich theka
    upore jawar smy
    **/
    /**lft bujaitese 1 theke mid porjonto range tar mane ai na j rght bujaitese
    mid+1 theke e porjonto range...rght o 1 to pura range bujaitese
    only it is skipping the duplicate in lft and using it in its own range
    **/
    tree[node].totsum=max(tree[Left].totsum,tree[Right].totsum);
    tree[node].bestsum=max(tree[node].bestsum,tree[node].totsum);
}

/// https://www.quora.com/How-can-the-SPOJ-problem-GSS2-be-solved
/// https://github.com/t3nsor/SPOJ/blob/master/gss2.cpp

/**
val aikhan e upor theka niche asbe and seg tree te update hbe
nich theka upore jawar smy amra sudu dekbo kon val ta maximum
**/

map<int,int> mp;
/**pos_or_rght
type
val_or_lft
querynmbr
**/
vector<pair<pii,pii> > v;
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
        mp.clear();
        v.clear();
        init(1,1,n);
        rep(i,n)
        {
            int x;
            getI(x);
            v.push_back(MP(pii(i,1),pii(x,i)));
        }
        getI(m);
        rep(i,m)
        {
            int x,y;
            getII(x,y);
            v.push_back(MP(pii(y,2),pii(x,i)));
        }
        sort(ALL(v));
        repI(i,v.size())
        {

            int type=v[i].ff.ss;
            if(type==1)
            {
                int val=v[i].ss.ff;
                if(mp[val]==0)
                {
                    mp[val]=v[i].ff.ff;
                    update(1,1,n,1,mp[val],val);
                }
                else
                {
                    update(1,1,n,mp[val]+1,v[i].ff.ff,val);
                    mp[val]=v[i].ff.ff;
                }
//                debug(mp[val],query(1,1,n,mp[val],mp[val]));
            }
            else
            {
                int pos=v[i].ss.ss;
                arr[pos]=query(1,1,n,v[i].ss.ff,v[i].ff.ff);
//                arr[pos]=max(arr[pos],0LL);
            }
//            debug(type,tree[1].bestsum)
        }
        rep(i,m)
        {
            printf("%lld\n",arr[i]);
        }
    }

    return 0;
}
/**
8
1 2 -1 3 2 -1 2 -1
8
1 8
2 8
3 8
4 8
5 8
6 8
8 8
1 8
output:
5
5
5
5
2
2
0
5
*/
