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
#define mamun
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


// jodi proti ber 1 ta value update korte hoi dn eita use kora better

char s[10];
#define mx 150005
int arr[mx];
struct data
{
    int ase,value;

} tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].ase=0;
        tree[node].value=arr[b];
        if(arr[b]!=-1)
            tree[node].ase=1;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].ase=tree[Left].ase+tree[Right].ase;
}
int query(int node,int b,int e,int i)
{
    if (b == e)
    {
        tree[node].ase=0;
        return tree[node].value;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int ans;
    if(i<=tree[Left].ase)
        ans=query(Left,b,mid,i);
    else
        ans=query(Right,mid+1,e,i-tree[Left].ase);
    tree[node].ase=tree[Left].ase+tree[Right].ase;
    return ans;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if (i > e || i < b)	return;
    if (b >= i && e <= i)
    {
        tree[node].value=newvalue;
        tree[node].ase=1;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node].ase=tree[Left].ase+tree[Right].ase;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    int cs;
    rep(cs,t)
    {
        int n,m;
        getII(n,m);
        int tot=n+m;
        int i;
        CLR(tree);
        SET(arr);
        //debug(n,m)
        rep(i,n)
        {
            getI(arr[i]);
        }
        init(1,1,tot);
        int cnt=1,now=n;
        int x;
        //getchar();
        printf("Case %d:\n",cs);
        rep(i,m)
        {
            scanf("%s %d",s,&x);
            //debug("n",s,x);
            if(s[0]=='a')
            {
                now++;
                update(1,1,tot,n+cnt,x);
                cnt++;
            }
            else
            {
                int ans=query(1,1,tot,x);
                if(x>now)
                    puts("none");
                else{
                    printf("%d\n",ans);
                    now--;
                }
            }

        }
    }
    return 0;
}
