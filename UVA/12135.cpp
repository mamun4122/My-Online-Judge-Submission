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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

#define iseq(a,b) (fabs(a-b)<EPS)

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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



//******************DELETE****************
#define mamun
#ifdef mamun
     #define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
int on(int n,int pos)
{
    return (n|(1<<pos));
}

int off(int n,int pos)
{
    return (n-(n & (1<<pos)));
}

bool check(int n,int pos)
{
    return (n & (1<<pos));
}

int t,n,m;
vector<int> v[45];
int sz[45];
int in;
int flag=0;
int dp[50][1<<15+4];
int call(int pos,int mask)
{
//    debug(mask)
    if(pos==m)
    {
        if(mask==0)
        {
            flag=1;
            return 0;
        }
        return 1000;
    }
    int &ret=dp[pos][mask];
    if(ret!=-1)return ret;
    int ans1,ans2;
    int tmp=mask;
    ans2=call(pos+1,mask);
    repI(i,sz[pos])
    {
        if(check(tmp,v[pos][i])==1)tmp=off(tmp,v[pos][i]);
        else tmp=on(tmp,v[pos][i]);
    }
    ans1=1+call(pos+1,tmp);
    return ret=min(ans1,ans2);
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
//        if(cs>1)puts("");
        int x,y;
        getII(n,m);
        CLR(sz);
        repI(i,m)
        {
            v[i].clear();
            getI(x);
            sz[i]=x;
            rep(j,x)
            {
                getI(y);
                v[i].push_back(y);
            }
        }
        int q;
        getI(q);
        printf("Case %d:\n",cs);
        SET(dp);
        ll vua;
        rep(i,q)
        {
            flag=0;
            getL(vua);
            in=0;
            int pos=0;
            while(vua)
            {
                if(vua%10==1)in=on(in,pos);
                pos++;
                vua/=10;
            }
//            debug(in)
            int ans=call(0,in);
            if(ans>=1000)puts("-1");
            else
            {
                printf("%d\n",ans);
            }
        }
        puts("");

    }





    return 0;
}



