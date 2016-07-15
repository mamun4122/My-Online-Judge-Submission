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
int coin[]={5,10,20,50,100,200};
int num[7];
int shopkeeper[600],buyer[600];

int call(int pos,int sum)
{
    //if(sum<0)return shopkeeper[-sum];
//    debug(pos,sum)
    if(sum<-500)return 10000000;
    if(pos==6)
    {
//        if(sum==0)return 0;
        if(sum>0)return 10000000;
        if(sum<=0)return shopkeeper[-sum];
    }
//    int &ret=buyer[sum];
//    if(ret!=-1)return ret;
    int ans=10000000;
    repI(i,num[pos]+1)
    {
        ans=min(ans,i+call(pos+1,sum-coin[pos]*i));
    }

    return ans;
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    //minimum coin made by shopkeeper
    mem(shopkeeper,63);
    shopkeeper[0]=0;
    repI(i,6)
    {
        for(int j=coin[i];j<=550;j++)
        {
            shopkeeper[j]=min(shopkeeper[j],1+shopkeeper[j-coin[i]]);
        }
    }
    SET(buyer);
    while(1)
    {
        repI(i,6)getI(num[i]);
        int flag=true;
        repI(i,6)if(num[i]){flag=false;break;}
        if(flag)break;
        double x;
        getF(x);
        x*=100;
        x+=.5;
        n=x;
        int ans=call(0,n);
        printf("%3d\n",ans);
    }


    return 0;
}

