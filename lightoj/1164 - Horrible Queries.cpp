#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;


#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    ld 	 long double


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define iseq(a,b) (fabs(a-b)<EPS)

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************


#define mx 100005
int arr[mx];


struct info
{
	ll prop,sum;
}tree[mx*3];

ll query(int node,int b,int e,int i,int j,ll carry=0)
{
	if (i > e || j < b)		return 0;

	if(b>=i && e<=j) return tree[node].sum+carry*(e-b+1);
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

    ll p1 = query(Left, b,mid,  i, j,   carry+tree[node].prop);
    ll p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    return  p1+p2;

}

void update(int node,int b,int e,int i,int j,ll x)
{
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
	{
		tree[node].sum+=((e-b+1)*x);
		tree[node].prop+=x;
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;

}

int main()
{
	//READ("in");
	int t;
	getI(t);
	for(int cs=1;cs<=t;cs++)
    {
        CLR(tree);
        printf("Case %d:\n",cs);
        int n,q;
        getII(n,q);
        int ch,a,b,val;
        for(int i=1;i<=q;i++)
        {
            getIII(ch,a,b);
            if(!ch)getI(val);
            if(!ch)update(1,1,n,a+1,b+1,val);
            else
                printf("%lld\n",query(1,1,n,a+1,b+1));
        }
    }

	return 0;
}
