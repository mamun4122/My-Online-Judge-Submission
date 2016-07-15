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

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
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
int t,n,m;
vector<int>v,z;

int b_search(int val)
{
    int sz=z.size();
    if(sz==0)return 0;
    if((val>z[sz-1]))return m;
    if(val<z[0])return 0;
    int low=0,high=sz-1;
    int flag=0;
    while(low<=high)
    {
        int mid=low+high;
        mid/=2;
//        debug(low,mid,high,z[mid])
        if(val<=z[mid])
        {
            flag=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
//    debug(flag,val)
    return flag;
}
int b_search1(int val)
{
//    debug("")
    int sz=v.size();
    if(sz==0)return 0;
    if((val>v[sz-1]))return 0;
    if(val<v[0])return n;
    int low=0,high=sz-1;
    int flag=0;
    while(low<=high)
    {
        int mid=low+high;
        mid/=2;
//        debug(low,mid,high,z[mid])
        if(val>v[mid])
        {
            flag=mid;
            high=mid-1;
        }
        else
        {
//            high=mid-1;
            low=mid+1;
        }
    }
    debug(flag,val)
    return n-flag-1;
}


int main() {
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    getI(t);
    rep(cs,t)
    {
        v.clear();z.clear();
        getII(n,m);
        rep(i,n)
        {
            int x;
            getI(x);
            v.push_back(x);
        }
        rep(i,m)
        {
            int x;
            getI(x);
            z.push_back(x);
        }
//        z.push_back(0);
        sort(ALL(v));
        sort(ALL(z));
        pii ans=make_pair(INF,INF);
        repI(i,n)
        {
            int angry=n-i-1;
//            debug(angry)
            angry+=b_search(v[i]);
//            debug(angry)
            if(angry<ans.ss)
            {
                ans.ff=v[i];
                ans.ss=angry;
            }
        }
        repI(i,m)
        {
            int angry=i;
            debug(angry)
            angry+=b_search1(z[i]);
            debug(angry)
            if(angry<ans.ss)
            {
                ans.ff=z[i];
                ans.ss=angry;
            }
            else if(angry==ans.ss&&ans.ff>z[i])
            {
                ans.ff=z[i];
            }
        }
        if(ans.ss==INF)ans=make_pair(0,0);
        if(v.size()==0)ans=make_pair(0,0);
        else if(z.size()==0)ans=make_pair(v[n-1],0);
        if(v.size()>0)
        {
            if(ans.ff<v[0])ans.ff=0;
        }
        printf("%d %d\n",ans.ff,ans.ss);

    }




    return 0;
}


