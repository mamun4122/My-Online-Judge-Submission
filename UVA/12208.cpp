#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
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
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
ll res;
int tot;
vector<int>dig;
ll dp[70][2][70][2];
//ll call(int pos,int flag,int isStart)
//{
//    if(pos==tot)return isStart;
//    ll &ret=dp[pos][flag][isStart];
//    if(ret!=-1)return ret;
//    ll ans=0;
//    if(pos==0)
//    {
//        repI(i,dig[pos]+1)
//        {
//            ll tmp = call(pos+1,i==dig[pos],i!=0);
//            ans += tmp;
//            res += i * tmp;
//            debug(pos,i,tmp)
//        }
//    }
//    else
//    {
//        if(flag)
//        {
//            for(int i=0; i<=dig[pos]; i++)
//            {
//                ll tmp = call(pos+1,i==dig[pos],isStart||i!=0);
//                ans += tmp;
//                res += i * tmp;
//            debug(pos,i,tmp)
//            }
//        }
//        else
//        {
//            repI(i,2)
//            {
//                ll tmp = call(pos+1,0,isStart||i!=0);
//                ans += tmp;
//                res += i * tmp;
//            debug(pos,i,tmp)
//            }
//        }
//    }
//    return ret=ans;
//}
ll call(int pos,int flag,int sum,int strt)
{
    if(pos==tot)return sum;
    ll &ret=dp[pos][flag][sum][strt];
    if(ret!=-1)return ret;
    ll ans=0;
    if(pos==0)
    {
        repI(i,dig[pos]+1)
        {
            ans+=call(pos+1,i==dig[pos],sum+i,(strt||i!=0));
        }
    }
    else
    {
        if(flag)
        {
            for(int i=0;i<=dig[pos];i++)
            {
                ans+=call(pos+1,i==dig[pos],sum+i,(strt||i!=0));
            }
        }
        else
        {
            repI(i,2)
                ans+=call(pos+1,0,sum+i,(strt||i!=0));
        }
    }
    return ret=ans;
}

ll calc(ll num)
{
//    res = 0;
    dig.clear();
    while(num)
    {
        dig.push_back(num%2);
        num/=2;
    }
    reverse(ALL(dig));
    tot=dig.size();
    SET(dp);
    ll vua = call(0,0,0,0);
//    debug(vua,res)
    return vua;
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int cs = 1;
    while(~getII(n,m) && (n||m))
    {
        printf("Case %d: %lld\n",cs++,calc(m)-calc(n-1));
    }

    return 0;
}
