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



//******************DELETE****************
#define mam
#ifdef mamun
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
#define mx 100010

char arr[mx];

struct info
{
    int toggole;
} tree[mx*3];


void init(int node,int b,int e)
{
    if(b==e)
    {
        //tree[node].val=arr[b]-'0';
        tree[node].toggole=arr[b-1]-'0';
        //debug(b-1,tree[node].toggole);
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
}

int query(int node,int b,int e,int i)
{
    if (i > e || i < b)	return 0;

    if(b<=i && i<=e && b==e)
    {
        //debug(b,e,i,tree[node].toggole);
        return tree[node].toggole;
    }

    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    if(i<=mid)
    {
        int x= query(Left, b,mid,  i);
        return x^tree[node].toggole;
    }
    else return query(Right, mid+1, e, i)^tree[node].toggole;
}

void update(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        debug(b,e,i,j);
        tree[node].toggole^=1;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j);
    update(Right,mid+1,e,i,j);

}

int main()
{
    //READ("in");
    int t;
    getI(t);
    getchar();
    for(int cs=1; cs<=t; cs++)
    {
        CLR(arr);
        CLR(tree);
        scanf("%s",&arr);
        int len=strlen(arr);
        init(1,1,len);
        printf("Case %d:\n",cs);
        char x;
        int a,b;
        int n;
        //debug(tree);
        getI(n);
        //debug(n);
        getchar();
        while(n--)
        {
            scanf("%c %d",&x,&a);

            //debug("m",x,a);
            if(x=='I')
            {
                getchar();
                getI(b);
            }
            getchar();
        //debug(x,a,b);
            if(x=='I')
            {
                update(1,1,len,a,b);
            }
            else
                printf("%d\n",query(1,1,len,a));
        }
    }

    return 0;
}


