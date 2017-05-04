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
double arr[MAX];


double tree[MAX*3];
int num[MAX*3];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
        num[node]=b;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=max(tree[Left],tree[Right]);
	if(fabs(tree[node]-tree[Left])<=EPS)num[node]=num[Left];
	else num[node]=num[Right];
}
pair<double,int> call(pair<double,int> a,pair<double,int> b)
{
    pair<double,int> tmp;
    tmp.ff=max(a.ff,b.ff);
    if(fabs(tmp.ff-a.ff)<=EPS)tmp.ss=a.ss;
    else tmp.ss=b.ss;
    return tmp;
}
pair<double,int> query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return MP(-(double)INF,0);
	if (b >= i && e <= j) return MP(tree[node],num[node]);
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	pair<double,int> p1=query(Left,b,mid,i,j);
	pair<double,int> p2=query(Right,mid+1,e,i,j);
	return call(p1,p2);
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    double a,b;
    while(~getF(a))
    {
        getF(b);
        getI(n);
        double ans=0.0;
        int x=0,y=0;
        rep(i,n)
        {
            arr[i]=(double)i*b-(double)i*i;
        }
        init(1,1,n);
        pair<double,int> vua=query(1,1,n,1,n);
        if(vua.ff>ans+EPS)
        {
            ans=vua.ff;
            x=0;y=vua.ss;
        }
//        debug(ans,x,y)
        rep(i,n)
        {
            int lft=n-i;
            double pro=(double)a*i-i*i;
            vua=query(1,1,n,1,lft);
            double sum=pro+vua.ff;
            if(sum>ans+EPS)
            {
                ans=sum;
                x=i;
                y=vua.ss;
            }
            if(pro>ans+EPS)
            {
                ans=pro;
                x=i;
                y=0;
            }
        }
            printf("%.2lf\n",ans);
            printf("%d %d\n",x,y);

    }


    return 0;
}


