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
int dp[100005];
vector<int> arr;
vector<pii> vua;
map<ll,int> mp;
int call(int num)
{
    if(num == 0)
        return 0;
    int &ret = dp[num];
    if(ret != -1)
        return ret;
    ret = INF;
    repI(i,vua.size())
    {
        if(num-vua[i].ff >= 0)
            ret = min(ret, call(num - vua[i].ff) + vua[i].ss);
    }
    return ret;

}
void backtrack(int pos, ll num, int tot)
{
    if(num > m)
        return;
    if(pos >= arr.size())
    {
        if(tot != 0)
        {
            if(mp[num] == 0)
                mp[num] = tot;
            else
                mp[num] = min(tot, mp[num]);
        }
        return;
    }
    backtrack(pos+1,num,tot);
    if(num*arr[pos] <= m )
        backtrack(pos+1,num*arr[pos],tot+1);
    ll vv = (ll)num*arr[pos] ;
    int jog = 2;
    while(vv <=m && arr[pos] != 1)
    {
        vv *= arr[pos];
        backtrack(pos+1,vv,tot+jog);
        jog++;
    }

}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    READ("complexity.in");
    WRITE("complexity.out");
    while(~getII(n,m))
    {
        arr.clear();
        vua.clear();
        mp.clear();
        arr.push_back(n);
        while(true)
        {
            n = log2(n);
            if(n == 0)break;
            arr.push_back(n);
        }
        backtrack(0,1,0);
        for(map<ll,int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            vua.push_back(MP(it->first,it->second));
        }
////        debug(vua.size())
////        repI(i,vua.size())
////        debug(vua[i].ff,vua[i].ss)
        SET(dp);
        int ans = 0;
//         ans = call(m);
//        sort(ALL(vua));
//        reverse(ALL(vua));
////        int ans = 0;
//        repI(i,vua.size())
//        {
//            while(m-vua[i].ff >= 0)
//                m -= vua[i].ff,ans += vua[i].ss;
//        }
        rep(i,m)dp[i] = m+m;
        dp[0] = 0;
        repI(i,vua.size())
        {
            rep(j,m)
            {
                if(j-vua[i].ff >= 0)
                    dp[j] = min(dp[j], dp[j-vua[i].ff]+vua[i].ss);
            }
        }
        ans = dp[m];
        printf("%d\n",ans);


    }

    return 0;
}