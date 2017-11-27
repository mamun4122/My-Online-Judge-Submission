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
struct data
{
    int line,curr,last;
    double pressure;
    data()
    {

    }
    data(int a,int b,double c,int d)
    {
        line=a;curr=b;pressure=c;last=d;
    }

};
class comparefunc
{
public:
    bool operator()(data &a,data &b)
    {
        if(fabs(a.pressure-b.pressure)<=EPS)
        {
            return a.line>b.line;
        }
        if(a.pressure+EPS>b.pressure)return true;
        return false;


    }
};


int arr[100010];
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n,k;
    while(~getII(n,k))
    {
        priority_queue<data,vector<data>,comparefunc> pq;
        for(int i=1;i<=k;i++)
            pq.push(data(i,0,0.0,0));
        int x;
        for(int i=1;i<=n;i++)
        {
            getI(x);
            data tp=pq.top();
            pq.pop();
            //debug(tp.line,tp.curr,tp.pressure,tp.last);
            if(tp.curr==0)
            {
                pq.push(data(tp.line,tp.curr+1,(double)(tp.curr+1)*x,x));
            }
            else
            {
                pq.push(data(tp.line,tp.curr+1,(tp.curr+1)*(tp.last+x)/2.0,x));
            }
            arr[i]=tp.line;

        }
        for(int i=1;i<=n;i++)
        {
            if(i>1)printf(" ");
            printf("%d",arr[i]);
        }
        printf("\n");
    }





    return 0;
}