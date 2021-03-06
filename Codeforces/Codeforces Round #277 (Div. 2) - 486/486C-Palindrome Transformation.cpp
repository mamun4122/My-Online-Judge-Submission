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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n,p;
    while(~getII(n,p))
    {
        string s;
        cin>>s;
        if(p>n/2)
        {
            reverse(ALL(s));
            p=n-p;
        }
        else
            p--;
        int first=0,last=0,flag=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                first=i;break;
            }
        }
        for(int i=(n-1)/2,j=n-1-i;i>=0;i--,j++)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                last=i;break;
            }
        }
        debug(p,first,last);
        int ans=0;
        if(flag)
        {
            ans=min(abs(p-first),abs(p-last));
            ans+=(last-first);
        }
        debug(ans);
        for(int i=first,j=n-first-1;i<=last;i++,j--)
        {
            debug(s[i],s[j]);
            if(s[i]!=s[j])
            {
                char l=min(s[i],s[j]),h=max(s[i],s[j]);
                int tmp=(int)(l-'a')+(int)('z'-h)+1;

                ans+=min(abs(s[i]-s[j]),tmp);
                debug(ans);
            }
        }
        cout<<ans<<endl;

    }





    return 0;
}