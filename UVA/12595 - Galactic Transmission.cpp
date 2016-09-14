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
#define    pii 	 pair< ll, ll >
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
///4*500000 ta unique thakte pare
#define MAX 2000005
vector<ll> arr[MAX];

struct info
{
    vector<ll> v;
}tree[MAX*4];
info call(info a,info b)
{
    info tmp;
    tmp.v.resize(a.v.size()+b.v.size());
    merge(ALL(a.v),ALL(b.v),tmp.v.begin());
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].v.resize(arr[b].size());
	    tree[node].v=arr[b];
	    ///sort korsi
	    sort(ALL(tree[node].v));
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
int add(int a,int b)
{
    return a+b;
}
int query(int node,int b,int e,int i,int j,int y1)
{
	if (i > e || j < b)return 0;
	if (b >= i && e <= j)
    {
        ///y2 er modde koita ase ber korlam
        int val=upper_bound(ALL(tree[node].v),y1)-tree[node].v.begin();
        return val;

    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j,y1);
	int p2=query(Right,mid+1,e,i,j,y1);
	return add(p1,p2);
}
int query1(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)return 0;
	if (b >= i && e <= j)
    {
        ///y2 er modde koita ase ber korlam
        int val=tree[node].v.size();
        return val;

    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query1(Left,b,mid,i,j);
	int p2=query1(Right,mid+1,e,i,j);
	return add(p1,p2);
}

vector<pii> in1,in2;
vector<ll> xx,yy;
map<ll,ll> mpx,mpy;
void clear()
{
    in1.clear();in2.clear();
    xx.clear();yy.clear();
    mpx.clear();mpy.clear();
}
struct point
{
    ll x,y,z;
};
ll Dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+
           (a.y-b.y)*(a.y-b.y)+
           (a.z-b.z)*(a.z-b.z);
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
//        debug("");
        clear();
        point p1,p2,tmp;
        getLLL(p1.x,p1.y,p1.z);
        getLLL(p2.x,p2.y,p2.z);
        rep(i,n)
        {
            if(i<=2)continue;
            getLLL(tmp.x,tmp.y,tmp.z);
            ll x=Dist(tmp,p1);
            ll y=Dist(tmp,p2);
//            debug(x,y);
            in1.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
        }
//        debug("");
        getI(m);
        rep(i,m)
        {
            ll x,y;
            getLL(x,y);
            x*=x;y*=y;
//            debug(x,y);
            in2.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
        }
        ///sort korlam
        sort(ALL(xx));
        sort(ALL(yy));
        ///unique element nilam
        xx.erase(unique(ALL(xx)),xx.end());
        yy.erase(unique(ALL(yy)),yy.end());
        ///renumbering korlam
        repI(i,xx.size())mpx[xx[i]]=i+1;
        repI(i,yy.size())mpy[yy[i]]=i+1;
        ///clear
        int totx=xx.size();
        int toty=yy.size();
        rep(i,totx)arr[i].clear();
        ///proti ta x pos e kon y gula ase ta ber korlam
        repI(i,n-2)
        {
            int x=mpx[in1[i].ff],y=mpy[in1[i].ss];
//            debug(in1[i].ff,in1[i].ss,x,y);
            arr[x].PB(y);
        }
        ///initialize seg tree
        init(1,1,totx);
        repI(i,m)
        {

            int x2=mpx[in2[i].ff],y2=mpy[in2[i].ss];
//            debug(i,x2,y2)
            int ans=query1(1,1,totx,1,x2);
            ans+=query(1,1,totx,1,totx,y2);
            ans-=query(1,1,totx,1,x2,y2);

            printf("%d\n",ans);
        }
//        debug("")
    }
    return 0;
}

