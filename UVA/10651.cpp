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
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


//int w[20][20];
int arr[13];
int n;
int dp[(1<<12)];
int call(int mask)
{
    //debug(mask,sum);
	if(dp[mask]!=-1) return dp[mask];
	int mn=0;
	for(int i=0;i<12;i++)
        if(check(mask,i))mn++;
	for(int i=0;i<12;i++)
	{
		if(check(mask,i)==0&&i<=9)
		{
		   if(check(mask,i+1)&&check(mask,i+2))
		   {
                int tmp=mask;
                tmp=Set(tmp,i);
                tmp=reset(tmp,i+1);
                tmp=reset(tmp,i+2);
                mn=min(mn,call(tmp));
		   }
		}
		if(check(mask,i)==0&&i>=2)
        {
            if(check(mask,i-1)&&check(mask,i-2))
            {
                int tmp=mask;
                tmp=Set(tmp,i);
                tmp=reset(tmp,i-1);
                tmp=reset(tmp,i-2);
                mn=min(mn,call(tmp));
            }
        }
	}
	return dp[mask]=mn;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    while(t--)
    {
        int x=0;
        string s;
        cin>>s;
        SET(dp);
        for(int i=0;i<12;i++)
        {
            if(s[i]=='o')
                x=Set(x,i);
        }
        printf("%d\n",call(x));
    }


    return 0;
}


