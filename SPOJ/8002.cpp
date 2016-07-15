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

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }

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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
#define mx 100005
int arr[mx];

struct info
{
	ll prop,sum;
}tree[mx*3];
void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].sum=arr[b];
		tree[node].prop=0;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node].sum=tree[Left].sum+tree[Right].sum;
	tree[node].prop=0;
}

ll query(int node,int b,int e,int i,int j,ll carry=0)
{
	if (i > e || j < b)		return 0;

	if(b>=i and e<=j) return tree[node].sum+carry*(e-b+1);


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
    //READ("in.txt");
    int t;
    getI(t);
    // debug(t);
    int cs;
    rep(cs,t)
    {
        CLR(arr);
        CLR(tree);
        int n,q;
        getII(n,q);
        init(1,1,n);
        int i;
        int a,b,c,d;
        rep(i,q)
        {
            getIII(a,b,c);
            if(a==0)getI(d);
            if(a==0)
                update(1,1,n,b,c,d);
            else
                printf("%lld\n",query(1,1,n,b,c));

        }


    }
    /*int n;
    cin>>n;
    repl(i,n)
    cin>>arr[i];
    init(1,1,n);

    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;*/
    return 0;
}

