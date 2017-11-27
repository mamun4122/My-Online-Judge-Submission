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

#define rep(i,n) for( i = 1 ; i<=(n) ; i++)
#define repI(i,n) for( i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)


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


#define mx 200001

struct dta
{
    int day,time,type,r;
    bool operator < (const dta &a)const
    {
        return time<a.time;
    }
}data[mx*2];

struct node
{
    ll sum,cnt;
}tree[mx*3];

void init(int node,int b,int e)
{
    tree[node].cnt=tree[node].sum=0;
    if(b==e)
    {
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
}
int query(int node,int b,int e,int i,int j)
{
    if(tree[node].sum-tree[node].cnt*i<j)return 0;
    if (b==e)
    {
        return b;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    if(tree[Left].sum-tree[Left].cnt*i>=j)
        return query(Left,b,mid,i,j);
    else
        return query(Right,mid+1,e,i,j-(tree[Left].sum-tree[Left].cnt*i));

}
void update(int node,int b,int e,int i,int newvalue)
{
    if (i > e || i < b) return;
    if (b >= i && e <= i) {
        tree[node].cnt=1;
        tree[node].sum=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node].cnt=tree[Left].cnt+tree[Right].cnt;
    tree[node].sum=tree[Left].sum+tree[Right].sum;
}
int ans[mx];
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int i,j,n,m;
    getII(n,m);

    rep(i,m)
    {
        getI(data[i].time);
        data[i].day=i;
        data[i].r=0;
        data[i].type=0;
    }
    rep(i,n)
    {
        getII(data[i+m].time,data[m+i].r);
        data[i+m].day=i;
        data[i+m].type=1;
    }
    sort(data+1,data+1+n+m+1);
    reverse(data+1,data+1+n+m+1);
    init(1,1,m);
    int flg=0;
    rep(i,n+m)
    {
        //debug(data[i].time)
        if(data[i].type==0)
        {
            update(1,1,m,data[i].day,data[i].time);
        }
        else
        {
            ans[data[i].day]=query(1,1,m,data[i].time,data[i].r);
//            if(flg)printf(" ");flg=1;
//            printf("%d",query(1,1,m,data[i].time,data[i].r));
        }
    }
    for (i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);


//  int n;
//  cin>>n;
//  repl(i,n)
//      cin>>arr[i];
//  init(1,1,n);
//
//  update(1,1,n,2,0);
//  cout<<query(1,1,n,1,3)<<endl;
//  update(1,1,n,2,2);
//  cout<<query(1,1,n,2,2)<<endl;
    return 0;
}