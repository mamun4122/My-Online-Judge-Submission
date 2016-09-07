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
#define mx 30005

int arr[mx];
struct info
{
    int data,ind;
    info(){;}
    info(int a,int b)
    {
        data=a;ind=b;
    }
}tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].data=arr[b];
        tree[node].ind=b;
        return;
    }
    int mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    if(tree[node*2].data<tree[node*2+1].data)
        tree[node]=tree[node*2];
    else
        tree[node]=tree[node*2+1];
    //debug(node,tree[node]);
}
info query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return info(INF,INF);
    if(b>=i&&e<=j)return tree[node];
    int mid=(b+e)/2,l=node*2,r=node*2+1;
    info p1=query(l,b,mid,i,j);
    info p2=query(r,mid+1,e,i,j);
    if(p1.data>p2.data)
    {
        //debug(p2)
        return p2;
    }
    return p1;
}
int ans,n;
void recur(int i,int j)
{
    if(i>j)return;
    //debug(i,j,query(1,1,n,i,j));
    info val=query(1,1,n,i,j);
    ans=max(ans,val.data*(j-i+1));
    recur(i,val.ind-1);
    recur(val.ind+1,j);

}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t,cs,i;
    getI(t);
    rep(cs,t)
    {
        printf("Case %d:",cs);
        getI(n);
        CLR(arr);CLR(tree);
        rep(i,n)getI(arr[i]);
        init(1,1,n);
        ans=0;
        recur(1,n);
        printf(" %d\n",ans);

    }





    return 0;
}


