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
int n,ln;
int adj[12][12],taken[12];
vector<int> ans;
int flag;
void solve(int crnt,int sz)
{
    if(sz>n)return;
    if(sz==ln)
    {
        flag=0;
        printf("(");
        for(int i=0;i<ans.size();i++)
        {
            if(i>0)printf(",");
            printf("%d",ans[i]);
        }
        printf(")\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[crnt][i]==1&&!taken[i])
        {
            taken[i]=1;
            ans.push_back(i);
            solve(i,sz+1);
            ans.pop_back();
            taken[i]=0;
        }
    }

}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int cs=0;
    while(cin>>n>>ln)
    {
        if(cs)printf("\n");
        cs=1;
        flag=1;
        CLR(taken);
        CLR(adj);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>adj[i][j];
        }
        taken[1]=1;
        ans.push_back(1);
        solve(1,0);
        int tmp;
        getI(tmp);
        ans.pop_back();
        if(flag)printf("no walk of length %d\n",ln);
    }


    return 0;
}


