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

vector<int>b;
struct data
{
    int val,pos;
    data()
    {
        ;
    }
    data(int xx,int yy)
    {
        val=xx;pos=yy;
    }
};
vector<data>f;
//vector<int>ans;
int high;
int binary_low(int val)
{
    int low=0;
    int mid=low+high;
    mid/=2;
    int flag=-1;
    while(low<=high)
    {
        if(f[mid].val==val)
        {
            flag=mid;
            high=mid-1;
        }
        else if(f[mid].val>val)
            high=mid-1;
        else
            low=mid+1;
        mid=(low+high)/2;

    }
    return flag;
}
int binary_high(int val)
{
    int low=0;
    int mid=low+high;
    mid/=2;
    int flag=-1;
    while(low<=high)
    {
        if(f[mid].val==val)
        {
            flag=mid;
            low=mid+1;
        }
        else if(f[mid].val>val)
            high=mid-1;
        else
            low=mid+1;
        mid=(low+high)/2;

    }
    return flag;
}
vector<int> ans;
bool cmp(const data &a,const data &b)
{
    return a.val<b.val;
}
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,m;
    while(~getII(n,m))
    {
        b.clear();f.clear();
        ans.clear();
        int x;
        rep(i,n)
        {
            getI(x);
            f.push_back(data(x,i));
        }
        rep(i,m)
        {
            getI(x);
            b.push_back(x);
        }
        sort(ALL(f),cmp);
        int imposs=0,ambi=0;
        repI(i,m)
        {
            high=n-1;
            if(binary_low(b[i])!=-1)
            {
                high=n-1;
                int low=binary_low(b[i]);
                high=n-1;
                int high=binary_high(b[i]);
                if(low!=high)
                    ambi=1;
                ans.push_back(f[low].pos);

            }
            else{
                imposs=1;
                break;
            }
        }
        if(imposs)
            puts("Impossible");
        else if(ambi)
            puts("Ambiguity");
        else
        {
            puts("Possible");
            repI(i,m)
            {
                if(i)printf(" ");
                printf("%d",ans[i]);
            }
            puts("");
        }

    }




    return 0;
}