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
int t,n,m;
string s;
vector<string> v;

int main() {
//    READ("in.txt");
//    WRITE("out.txt");
    while(~getI(n))
    {
        getchar();
        v.clear();
        int mx=0;
        rep(i,n){
            getline(cin,s);
//            debug(s);
            mx=max(mx,(int)s.size());
            v.push_back(s);
        }
        sort(ALL(v));
//        debug(mx)
        int col=1;
        int colcnt=60-mx;
//        debug(colcnt)
        while(colcnt-(mx+2)>=0){
            col++;colcnt-=(mx+2);
//            debug(colcnt)
        }
        int row=ceil((double)n/col);
//        debug(row,col)
        rep(i,60)printf("-");
        puts("");
        int cnt=0;
        int r=0;
        while(cnt<n)
        {
            repI(i,col)
            {
                if(r+row*i>=n)continue;
                cnt++;
                printf("%s",v[r+row*i].c_str());
                int tmp=v[r+row*i].size();
                if(i<col-1)while(tmp<mx+2)
                {
                    printf(" ");
                    tmp++;
                }
                else
                {
                    while(tmp<mx)
                    {
                        printf(" ");
                        tmp++;
                    }
                }
                if(cnt==n)break;
            }
            r++;
            puts("");
        }
    }



    return 0;
}

