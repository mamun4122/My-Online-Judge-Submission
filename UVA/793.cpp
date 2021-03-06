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
#define mamu
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
int par[100010];
void makeset(int n){
	par[n]=n; //at first every element is parent of itself.
}
int find_representative(int r)
{
	if(par[r]==r) return r;  //if r is parent of itself than r is representative
	else
	{
		return par[r]=find_representative(par[r]); //else find representative of parent of r
	}
}
void Union(int a,int b)
{
	int u=find_representative(a);
	int v=find_representative(b);
	if(u!=v)
	{
		par[u]=v; //or you can write par[v]=u too
	}
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    getI(t);
    int cs;
    int n;
    rep(cs,t)
    {
        if(cs>1)printf("\n");
        int succ=0,unsucc=0;
        getI(n);
        getchar();
        debug(n);
        int i;
        rep(i,n)makeset(i);
        char x;
        int a,b;
        while(scanf("%c",&x)!=EOF)
        {
            debug(x);
            if(x=='\n')
            {
                break;
            }
            getII(a,b);
            getchar();
            debug(x,a,b);
            if(x=='c')
                Union(a,b);
            else
            {
                if(find_representative(a)==find_representative(b))
                    succ++;
                else
                    unsucc++;
            }
        }
        printf("%d,%d\n",succ,unsucc);

    }





    return 0;
}

