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
int p[]={2,3,5,7,11,13,17,19,23,29,31,37};
int prime[40];
int n;
int taken[17];
vector<int> v;
void solve(int crnt,int sz)
{
    if(sz==n)
    {
        for(int i=0;i<sz;i++)
        {
            if(i)printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(taken[i]==0&&prime[i+crnt]&&sz!=n-1)
        {
            v.push_back(i);
            taken[i]=1;
            solve(i,sz+1);
            taken[i]=0;
            v.pop_back();
        }
        else if(sz==n-1&&taken[i]==0&&prime[i+1]&&prime[i+crnt])
        {
            v.push_back(i);
            taken[i]=1;
            solve(i,sz+1);
            taken[i]=0;
            v.pop_back();
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    CLR(prime);
    for(int i=0;i<12;i++)
        prime[p[i]]=1;
    int flag=0,cs=1;
    while(cin>>n)
    {
        v.clear();
        CLR(taken);
        if(flag)printf("\n");
        flag=1;
        printf("Case %d:\n",cs++);
        taken[1]=1;
        v.push_back(1);
        solve(1,1);

    }


    return 0;
}


