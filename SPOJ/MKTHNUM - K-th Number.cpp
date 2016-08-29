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
#define MAX 100005
int arr[MAX];

struct info
{
    vector<int> v;
}tree[MAX*3];
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
	    tree[node].v.resize(1);
	    tree[node].v[0]=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}
pii add(pii a,pii b)
{
    return MP(a.ff+b.ff,a.ss+b.ss);
}
pii query(int node,int b,int e,int i,int j,int val)
{
	if (i > e || j < b)return MP(0,0);
	if (b >= i && e <= j)
    {
        int low=upper_bound(ALL(tree[node].v),val-1)-tree[node].v.begin();
        int high=upper_bound(ALL(tree[node].v),val)-tree[node].v.begin();
        return pii(low,high);
    }
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	pii p1=query(Left,b,mid,i,j,val);
	pii p2=query(Right,mid+1,e,i,j,val);
	return add(p1,p2);
}
///https://www.quora.com/Sphere-Online-Judge-SPOJ-How-do-I-use-a-persistent-segment-tree-to-solve-a-problem

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        rep(i,n)getI(arr[i]);
        init(1,1,n);
        sort(arr+1,arr+1+n);
        repI(i,m)
        {
            int x,y,z;
            getIII(x,y,z);
            int ans;
            int low=1,high=n;
            while(low<=high)
            {
                int mid=(low+high)/2;
                pii val=query(1,1,n,x,y,arr[mid]);
//                debug(arr[mid],val.ff,val.ss)
                if(val.ff<z&&z<=val.ss)
                {
                    ans=arr[mid];
                    break;
                }
                if(val.ff>=z)
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            printf("%d\n",ans);
        }

    }


    return 0;
}

