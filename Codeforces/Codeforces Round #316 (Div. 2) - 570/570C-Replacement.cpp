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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)

#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(x) push_back(x)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    ld    long double


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
#define mam
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

#define mx 300005
//char arr[mx];
string s;

char arr[mx];
struct info
{
    int val,ans,l,r;
}tree[mx*4];
int cnt=0;

void init(int node,int b,int e)
{
    if(b==e)
    {
        //debug("m",node,b,arr[b]);
        if(arr[b-1]=='.')
        {
            tree[node].l=1;
            tree[node].r=1;
        }
        else
            tree[node].l=tree[node].r=0;
        tree[node].ans=0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].l=tree[Left].l;
        tree[node].r=tree[Right].r;
         tree[node].ans=tree[Left].ans+tree[Right].ans;
    if(tree[Left].r+tree[Right].l==2)
    {
        tree[node].ans++;

    }
    //debug(node,tree[node].ans);
}
//int query(int node,int b,int e,int i,int j)
//{
//  if (i > e || j < b) return 0;
//  if (b >= i && e <= j) return tree[node];
//  int Left=node*2;
//  int Right=node*2+1;
//  int mid=(b+e)/2;
//  int p1=query(Left,b,mid,i,j);
//  int p2=query(Right,mid+1,e,i,j);
//  return p1+p2;
//}
void update(int node,int b,int e,int i,int newvalue)
{

    if (i > e || i < b) return;
    if (b >= i && e <= i) {
        debug("m",node,b,arr[b]);
        if(arr[b-1]=='.')
        {
            tree[node].l=1;
            tree[node].r=1;
        }
        else
            tree[node].l=tree[node].r=0;
        tree[node].ans=0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node].l=tree[Left].l;
    tree[node].r=tree[Right].r;
    tree[node].ans=tree[Left].ans+tree[Right].ans;
    if(tree[Left].r+tree[Right].l==2)
    {
        tree[node].ans++;

    }
    debug(node,tree[node].ans);


//  tree[node].val=tree[Left].val+tree[Right].val;
//  tree[node].ans=tree[Left].ans+tree[Right].ans;
//  if(tree[node].val==2){
//            tree[node].val=1;
//            tree[node].ans++;
//  }
//  else tree[node].val=0;

}
int main()
{

    int n,m;
    while(~getII(n,m))
    {
        //cin>>s;
        getchar();
        gets(arr);

        //getchar();
        //debug(n,m,s);
        CLR(tree);
        int f;
//       rep(f,n)
//           arr[f-1]='.';
//    arr[n]='\0';
//        puts("");
        init(1,1,n);
        int a;char c;
        //debug("m");
        for(int i=1;i<=m;i++)
        {
            scanf("%d %c",&a,&c);
           // debug(a,c);
            arr[a-1]=c;
            update(1,1,n,a,0);
            printf("%d\n",tree[1].ans);
        }
    }

    return 0;
}