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
struct info
{
    int val;
    int upor;
    int niche;
    int prop;
}tree[mx*3],org;
info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.upor=a.upor+b.upor;
    tmp.niche=a.niche+b.niche;
    tmp.prop=0;
    return tmp;
}
void init(int node,int b,int e)
{
	if(b==e)
	{
	    ///do something
	    tree[node].val=0;
	    tree[node].upor=0;
	    tree[node].niche=1;
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

    tree[Left].val=tree[node].val;
    tree[Right].val=tree[node].val;
    ///update tree[left]
    tree[Left].upor=tree[Left].niche*tree[node].val;
    ///update tree[right]
    tree[Right].upor=tree[Right].niche*tree[node].val;

}
info query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)return org;
	if(tree[node].prop)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    info p1 = query(Left,b,mid,i,j);
    info p2 = query(Right,mid+1,e,i,j);
    return  call(p1,p2);

}

void update(int node,int b,int e,int i,int j,int x)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        ///do something
        tree[node].val=x;
        tree[node].upor=(e-b+1)*x;
        tree[node].prop=1;
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	tree[node]=call(tree[Left],tree[Right]);
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        org.val=0;
        org.upor=0;
        org.niche=0;
        org.prop=0;

        getII(n,m);
        init(1,1,n);
        printf("Case %d:\n",cs);
        rep(i,m)
        {
            int type,x,y;
            getIII(type,x,y);
            if(type==1)
            {
                int k;
                getI(k);
                update(1,1,n,x+1,y+1,k);
            }
            else
            {
                info tmp=query(1,1,n,x+1,y+1);
                int gc=gcd(tmp.upor,tmp.niche);
                tmp.upor/=gc;
                tmp.niche/=gc;
                printf("%d",tmp.upor);
                if(tmp.niche!=1)printf("/%d\n",tmp.niche);
                else puts("");

            }
        }
    }


    return 0;
}


