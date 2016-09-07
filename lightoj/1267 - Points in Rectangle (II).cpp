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
///4*50000 ta unique thakte pare
#define MAX 200005
vector<int> arr[MAX];

struct info
{
    vector<int> v;
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
int query(int node,int b,int e,int i,int j,int y1,int y2)
{
	if (i > e || j < b)return 0;
	if (b >= i && e <= j)
    {
        ///y2 er modde koita ase ber korlam
        int val=upper_bound(ALL(tree[node].v),y2)-tree[node].v.begin();
        ///y1 er cheye chotogulao add hoye gesilo bad dilam
        val-=(lower_bound(ALL(tree[node].v),y1)-tree[node].v.begin());
        return val;

    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j,y1,y2);
	int p2=query(Right,mid+1,e,i,j,y1,y2);
	return add(p1,p2);
}

vector<pii> in1,in2,in3;
vector<int> xx,yy;
map<int,int> mpx,mpy;
void clear()
{
    in1.clear();in2.clear();
    in3.clear();xx.clear();yy.clear();
    mpx.clear();mpy.clear();
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
//        debug("");
        clear();
        getII(n,m);
        rep(i,n)
        {
            int x,y;
            getII(x,y);
            in1.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
        }
        rep(i,m)
        {
            int x,y;
            getII(x,y);
            in2.push_back(MP(x,y));
            xx.push_back(x);
            yy.push_back(y);
            getII(x,y);
            in3.push_back(MP(x,y));
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
        repI(i,n)
        {
            int x=mpx[in1[i].ff],y=mpy[in1[i].ss];
            arr[x].PB(y);
        }
        ///initialize seg tree
        init(1,1,totx);
        printf("Case %d:\n",cs);
        repI(i,m)
        {
            int x1=mpx[in2[i].ff],y1=mpy[in2[i].ss];
            int x2=mpx[in3[i].ff],y2=mpy[in3[i].ss];
            int ans=query(1,1,totx,x1,x2,y1,y2);
            printf("%d\n",ans);
        }

    }


    return 0;
}

