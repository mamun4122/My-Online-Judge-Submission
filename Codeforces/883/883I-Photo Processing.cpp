#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << ": " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << ": " << arg1 << " | ";
        __f(comma+1, args...);
    }
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define trace(...)
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

int arr[300005];
int  dp[300005];

int check(int diff)
{
    CLR(dp);
    dp[0] = 1;
    int up = 0,pos = 1;
    rep(i,n)
    {
        if(dp[i-1] == 0)continue;
        if(i+m-1 > n)break;
        up = max(up,i+m-1);
        while(pos < n && arr[pos+1] - arr[i] <= diff)pos++;
        while(up <= pos)dp[up] = 1,up++;
    }
    return dp[n];
}

//int mark[300005];
//int lft[300005];
//int rght[300005];
//int diff;
//int cc;
//int call(int pos)
//{
//    if(pos > n)return 1;
//    int &ret = dp[pos];
//    int &vis = mark[pos];
//    if(vis == cc)return ret;
//    vis = cc;
//    if(n-pos+1 >= m && arr[n]-arr[pos] <=diff)
//        return ret = 1;
//    ret = 0;
//    int l = lft[pos];
//    int r = rght[pos];
//    while(r >= l)
//    {
//        ret |= call(r+1);
//        r--;
//        if(ret)break;
//    }
//    return ret;
//}


//int check(int dif)
//{
//    cc++;
//    diff = dif;
//    rep(i,n)
//    {
//        int p = i+m-1;
//        lft[i] = INF,rght[i] = -INF;
//        if(p <= n && arr[p] - arr[i] <= diff)
//        {
//            lft[i] = p;rght[i] = p;
//            int low = p,high = n;
//            while(low <= high)
//            {
//                int mid = (low+high)/2;
//                if(arr[mid]-arr[i] <= diff)
//                    rght[i] = mid,low = mid+1;
//                else
//                    high = mid-1;
//            }
//        }
//    }
//    return call(1);
//}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getII(n,m))
    {
//        CLR(mark);
//        cc = 1;
        rep(i,n)getI(arr[i]);
        sort(arr+1,arr+1+n);
        int low = 0,high = 1e9;
        int ans = INF;
//        debug(check(7));
//        break;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(check(mid))
                high = mid-1,ans = mid;
            else
                low = mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}