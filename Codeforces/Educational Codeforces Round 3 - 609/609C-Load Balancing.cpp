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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))


#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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
#define mx 100001
int arr[mx];
//
//struct data
//{
//    int mini,maxi;
//    int posmini,posmaxi;
//
//}tree[mx*3];;
//
//void init(int node,int b,int e)
//{
//  if(b==e)
//  {
//      tree[node].maxi=arr[b];
//      tree[node].mini=arr[b];
//      tree[node].posmaxi=b;
//      tree[node].posmini=b;
//      return;
//  }
//  int Left=node*2;
//  int Right=node*2+1;
//  int mid=(b+e)/2;
//  init(Left,b,mid);
//  init(Right,mid+1,e);
//  if(tree[Left].maxi>tree[Right].maxi)
//    {
//        tree[node].maxi=tree[Left].maxi;
//        tree[node].posmaxi=tree[Left].posmaxi;
//    }
//    else
//    {
//        tree[node].maxi=tree[Right].maxi;
//        tree[node].posmaxi=tree[Right].posmaxi;
//    }
//    if(tree[Left].mini<tree[Right].mini)
//    {
//        tree[node].mini=tree[Left].mini;
//        tree[node].posmini=tree[Left].posmini;
//    }
//    else
//    {
//        tree[node].mini=tree[Right].mini;
//        tree[node].posmini=tree[Right].posmini;
//    }
//}
//
//void update(int node,int b,int e,int i,int newvalue)
//{
//  if (i > e || i < b) return;
//  if (b >= i && e <= i) {
//        tree[node].maxi=newvalue;
//      tree[node].mini=newvalue;
//      tree[node].posmaxi=b;
//      tree[node].posmini=b;
//      return;
//  }
//  int Left=node*2;
//  int Right=node*2+1;
//  int mid=(b+e)/2;
//  update(Left,b,mid,i,newvalue);
//  update(Right,mid+1,e,i,newvalue);
//  if(tree[Left].maxi>tree[Right].maxi)
//    {
//        tree[node].maxi=tree[Left].maxi;
//        tree[node].posmaxi=tree[Left].posmaxi;
//    }
//    else
//    {
//        tree[node].maxi=tree[Right].maxi;
//        tree[node].posmaxi=tree[Right].posmaxi;
//    }
//    if(tree[Left].mini<tree[Right].mini)
//    {
//        tree[node].mini=tree[Left].mini;
//        tree[node].posmini=tree[Left].posmini;
//    }
//    else
//    {
//        tree[node].mini=tree[Right].mini;
//        tree[node].posmini=tree[Right].posmini;
//    }
//
////        debug(node,tree[node].maxi,tree[node].mini,tree[node].posmaxi,tree[node].posmini)
//}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    rep(i,n)getI(arr[i]);
    int ans=0;
    int tot=0;
    rep(i,n)tot+=arr[i];
    int vag=tot/n;
    int mod=tot%n;
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n-mod;i++)
        ans+=abs(arr[i]-vag);
//        debug(ans)
    for(int i=n-mod+1;i<=n;i++)
        ans+=abs(arr[i]-vag-1);
//        debug(ans)
    ans/=2;

//  init(1,1,n);
//  int ans=0;
//
////        update(1,1,n,tree[1].posmaxi,tree[1].maxi-1);
////        update(1,1,n,tree[1].posmini,tree[1].mini+1);
//  while(tree[1].maxi-tree[1].mini>1)
//    {
//        int tmp=(tree[1].maxi-tree[1].mini)/8;
//        if(!tmp)tmp++;
//        int posmaxi=tree[1].posmaxi;
//        int posmini=tree[1].posmini;
////        debug(tree[1].maxi,tree[1].mini,posmaxi,posmini)
//        update(1,1,n,posmaxi,tree[1].maxi-tmp);
//        update(1,1,n,posmini,tree[1].mini+tmp);
//        ans+=tmp;
//    }
    printf("%d\n",ans);

    return 0;
}