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
#define SET(p)    memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
//******************DELETE****************
int t,n,m;

string s;
int val[25],arr[25];
int sz;
ll ans2;
int flg;
void ok(int pos,ll num,int flag)
{
//    debug(num,pos,flag)
    if(pos==sz)
    {
        ans2=num;
//        debug(num)
        flg=1;
        return;
    }
    if(pos==0)
    {
        for(int i=val[pos]; i>=0; i--)
        {
            if(arr[i]>1)continue;
            arr[i]++;
            ok(pos+1,num*10+i,i==val[pos]);
            if(flg)return;
            arr[i]--;
        }
    }
    else
    {
        if(flag)
        {
            for(int i=val[pos]; i>=0; i--)
            {
                if(arr[i]>1)continue;
                arr[i]++;
                ok(pos+1,num*10+i,i==val[pos]);
                if(flg)return;
                arr[i]--;
            }
        }
        else
        {
            for(int j=pos;j<sz;j++)
            {
                for(int k=9;k>=0;k--)
                {
                    if(arr[k]!=2)
                    {
                        num*=10;
                        num+=k;
                        arr[k]++;
                        break;
                    }
                }
            }
            ok(sz,num,0);
            if(flg)return;
        }
    }
}


int main()
{
    ///check for 0 and negative if limit is not specified

//    READ("in.txt");
    //WRITE("out.txt");
    while(cin>>s)
    {
        CLR(arr);
        CLR(val);
        sz=s.size();
        repI(i,s.size())val[i]=s[i]-48;
        ll ans1=0;
        ll val=9;
        rep(i,sz-1)
        {
            ans1*=10;
            ans1+=val;
            if(i%2==0)val--;
        }
        ans2=0;
        flg=0;
        ok(0,0,0);
        printf("%lld\n",max(ans1,ans2));
    }






    return 0;
}

