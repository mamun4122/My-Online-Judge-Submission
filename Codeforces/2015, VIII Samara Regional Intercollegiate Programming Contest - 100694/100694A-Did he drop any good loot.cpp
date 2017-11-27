#include <algorithm>
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
#define PI 3.1415926535897932384626

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
//
//#define    vi      vector < int >
//#define    vii     vector < vector < int > >

typedef pair <int,int>pii;

#define CLR(n, v) memset(n, v, sizeof( n ))

#define ff first
#define ss second

//******************DELETE****************
#define arnab
#ifdef arnab
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > T lcm(T a, T b) { return (a / gcd(a, b) * b); }

typedef pair<int,int>ii;
typedef vector<ii>vii;
typedef vector<int>vi;

int n,m;
struct node
{
    int p;
    int v;
    int d;
}ar[10005];

bool cmp(const node &a, const node &b)
{
    if(a.d>b.d) return true;
    else if(a.d==b.d)
    {
        if(a.p>b.p) return true;

    }
    return false;
}

int dp[10008][710][3];

int f(int i,int w,int c)
{
    if(i==n)
        return 0;
    if((w<=0&&c>=2))
        return 0;
    if(dp[i][w][c]!=-1)
        return dp[i][w][c];
    int p1=0,p2=0,p3=0,ret=0;
    if(w-ar[i].v>=0)
    {
        p1=ar[i].p+f(i+1,w-ar[i].v,c);
    }
    if(c<2&&w-ar[i].v+ar[i].d>=0)
        p3=ar[i].p+f(i+1,w-ar[i].v+ar[i].d,c+1);
    p2=f(i+1,w,c);
    ret=max(p1,p2);
    ret=max(ret,p3);
    return dp[i][w][c]=ret;
}

int main()
{
        //READ("in.txt");
    //WRITE("out.txt");
    while(cin>>n>>m)
    {
        CLR(ar,0);
        for(int i=0;i<n;i++)
        {
            int p,v,d;
            cin>>p>>v>>d;
            ar[i].p=p;
            ar[i].v=v;
            ar[i].d=d;
        }
        sort(ar,ar+n,cmp);
        CLR(dp,-1);
        int res=f(0,m,0);
        printf("%d\n",res);
    }
    return 0;
}