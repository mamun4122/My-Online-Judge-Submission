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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        string a,b,c;
        vector<int> x,y;
        cin>>a>>b>>c;
        x.push_back(0);
        y.push_back(0);
        rep(i,3-a.size())
        {
            rep(j,4)x.push_back(0);
        }
        rep(i,3-c.size())
        {
            rep(j,4)y.push_back(0);
        }
        repI(i,a.size())
        {
            vector<int> tmp;
            int k=isdigit(a[i])?a[i]-48:a[i]-55;
            while(k)
            {
                tmp.push_back(k%2);
                k/=2;
            }
            reverse(ALL(tmp));
            rep(j,4-tmp.size())x.push_back(0);
            repI(j,tmp.size())x.push_back(tmp[j]);
        }
        repI(i,c.size())
        {
            vector<int> tmp;
            int k=isdigit(c[i])?c[i]-48:c[i]-55;
            while(k)
            {
                tmp.push_back(k%2);
                k/=2;
            }
            reverse(ALL(tmp));
            rep(j,4-tmp.size())y.push_back(0);
            repI(j,tmp.size())y.push_back(tmp[j]);
        }
        repI(i,x.size())printf("%d",x[i]);
//        printf(" ");
        cout<<" "<<b<<" ";
        repI(i,y.size())printf("%d",y[i]);
        int ans1=0,ans2=0;
        repI(i,x.size())
        {
            ans1*=2;
            ans1+=x[i];
        }
        repI(i,y.size())
        {
            ans2*=2;
            ans2+=y[i];
        }
        if(b[0]=='-')
        printf(" = %d\n",ans1-ans2);
        else printf(" = %d\n",ans1+ans2);

    }




    return 0;
}

