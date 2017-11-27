#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    MP(x, y)       make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)           p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)           memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)       scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi   vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff   first
#define    ss   second
#define    ll  long long
#define    ull   unsigned long long

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
int arr[200005];
vector<int>even,odd,ans;
map<int,int> mp,org;


int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
        mp.clear();
        org.clear();
        rep(i,n)getI(arr[i]);
        rep(i,n)org[arr[i]]=1;
        int res=0;
        even.clear();
        odd.clear();
        ans.clear();
        int cnt=0;
        rep(i,m)
        {
            if(i%2==0)even.push_back(i);
            else odd.push_back(i);
            if(i%2==0)cnt++;
            if(cnt>n)break;
        }
//        debug(even[00])
        int odsize=odd.size();
        int evsize=even.size();
        int flag=0,e=0,od=0;
        rep(i,n)
        {
            if(arr[i]%2==0)e++;
            else od++;
        }
        int evenpos=0,oddpos=0;
        rep(i,n)
        {
            if(mp[arr[i]]==1)
            {
////                debug(i)
                if(arr[i]%2==0)
                {
                    if(e>od)
                    {
                        while(oddpos<odsize&&org[odd[oddpos]])oddpos++;
                        if(oddpos>=odsize)
                        {
                            flag=1;
                            break;
                        }
                        res++;
                        arr[i]=odd[oddpos++];
                        e--;
                        od++;
                    }
                    else
                    {
                        while(evenpos<evsize&&org[even[evenpos]])evenpos++;
                        if(evenpos>=evsize)
                        {
                            flag=1;
                            break;
                        }
                        res++;
                        arr[i]=even[evenpos++];
                    }
                }
                else
                {
                    if(od>e)
                    {
                        while(evenpos<evsize&&org[even[evenpos]])evenpos++;
                        if(evenpos>=evsize)
                        {
                            flag=1;
                            break;
                        }
                        res++;
//                        debug(res,evenpos)
                        arr[i]=even[evenpos++];
                        od--;
                        e++;
                    }
                    else
                    {
                        while(oddpos<odsize&&org[odd[oddpos]])oddpos++;
                        if(oddpos>=odsize)
                        {
                            flag=1;
                            break;
                        }
                        res++;
                        arr[i]=odd[oddpos++];
                    }
                }
            }
            mp[arr[i]]=1;
        }
//        debug(res)
        int i=1;
        while(e>od&&!flag)
        {
            if(arr[i]%2==0)
            {
                while(oddpos<odsize&&org[odd[oddpos]])oddpos++;
                if(oddpos>=odsize)
                {
                    flag=1;
                    break;
                }
                res++;
                arr[i]=odd[oddpos++];
                e--;
                od++;
            }
            i++;

        }
        i=1;
        while(od>e&&!flag)
        {
            if(arr[i]%2==1)
            {
                while(evenpos<evsize&&org[even[evenpos]])evenpos++;
                if(evenpos>=evsize)
                {
                    flag=1;
                    break;
                }
                res++;
                arr[i]=even[evenpos++];
                od--;
                e++;
            }
            i++;
        }

        if(flag)puts("-1");
        else
        {
            printf("%d\n",res);
            rep(i,n)printf("%d ",arr[i]);
            puts("");
        }
    }


    return 0;
}