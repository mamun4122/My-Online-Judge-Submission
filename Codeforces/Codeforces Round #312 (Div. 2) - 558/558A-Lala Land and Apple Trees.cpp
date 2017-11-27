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
    int x,a;
    data(int y,int z)
    {
        x=y;a=z;
    }
};
bool cmp(const data &c,const data &d)
{
    if(c.x<d.x)return true;
    return false;
}bool cmp1(const data &c,const data &d)
{
    if(c.x>d.x)return true;
    return false;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int n;
    getI(n);
    int x,a;
    vector<data> left,right;
    for(int i=1;i<=n;i++)
    {
        getII(x,a);
        if(x<0)left.push_back(data(x,a));
        else right.push_back(data(x,a));
    }
    sort(ALL(left),cmp1);
    sort(ALL(right),cmp);
    int sz1=left.size();int sz2=right.size();
    int l=0,r=0;
    int ans=0,temp=0,cnt=1;
    while(1)
    {
        if(cnt%2==1)
        {
            if(l<sz1)
            temp+=left[l++].a;
            else break;
        }
        else
        {
            if(r<sz2)temp+=right[r++].a;
            else break;
        }
        cnt++;

    }
    ans=temp;l=0;r=0;cnt=0;temp=0;
    while(1)
    {
        if(cnt%2==1)
        {
            if(l<sz1)
            temp+=left[l++].a;
            else break;
        }
        else
        {
            if(r<sz2)temp+=right[r++].a;
            else break;
        }
        cnt++;
    }
    ans=max(ans,temp);
    cout<<ans<<endl;

    return 0;
}