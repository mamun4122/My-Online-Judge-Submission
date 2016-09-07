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
#include <ctime>
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
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< long long, long long >
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



#define mx 150005

struct info
{
	int prop;
}tree[mx*5];
void init(int node,int b,int e)
{
	if(b==e)
	{
		//tree[node].sum=0;
		tree[node].prop=0;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	//tree[node].sum=tree[Left].sum+tree[Right].sum;
	tree[node].prop=0;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
	if (i > e || j < b)		return 0;

	if(b>=i && e<=j) return tree[node].prop+carry*(e-b+1);


	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

    int p1 = query(Left, b,mid,  i, j,   carry+tree[node].prop);
    int p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    //if(i==7)debug(node,b,e,carry);
    return  p1+p2;

}

void update(int node,int b,int e,int i,int j,int x)
{
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
	{
		//tree[node].sum+=0;
		tree[node].prop+=x;
		//debug("*",node,b,e,tree[node].prop)
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	//tree[node].sum=tree[Left].sum+tree[Right].sum;
}

int main()
{
	//READ("in.txt");
	int t;
	getI(t);
	int cs;
	rep(cs,t)
	{
	    printf("Case %d:\n",cs);
	    int n,q;
	    getII(n,q);
	    int i;ll x,y;
	    set<ll> in;
	    vector<pii> v;
	    vector<int> in2;
	    rep(i,n)
	    {
	        getL(x);
	        getL(y);
	        //debug(x,y)
	        in.insert(x);
	        in.insert(y);
	        v.push_back(make_pair(x,y));
	    }

	    rep(i,q)
	    {
	        getL(x);
	        in2.push_back(x);
	        in.insert(x);
	    }
	    int cnt=1;
	    map<ll,int> mp;
	    for(set<ll>::iterator it=in.begin();it!=in.end();it++)
	    {
	       // debug(*it,cnt)
	        mp[*it]=cnt++;
	    }
	    cnt--;
	    init(1,1,cnt);
	    //debug(cnt)
	    rep(i,n)
	    {
	        //debug("*",v[i-1].first,mp[v[i-1].first],v[i-1].second,mp[v[i-1].second])
	        update(1,1,cnt,mp[v[i-1].first],mp[v[i-1].second],1);
	    }
	    rep(i,q)
	    {
	       // debug(in2[i-1],mp[in2[i-1]])
	        printf("%d\n",query(1,1,cnt,mp[in2[i-1]],mp[in2[i-1]]));
	    }
	    v.clear();in.clear();
	    in2.clear();mp.clear();


	}

	return 0;
}
