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

#ifdef mamunSobPare
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

set<pair<ll,int> > st;
vector<ll> v;

bool check(int mid)
{
//    debug(mid)
    st.clear();
    repI(i,v.size())st.insert({v[i],i});
    queue<pair<ll,int> > q[2];
    int cur = 0;
    int prv = 1;
    repI(i,mid)
    {
        q[cur].push(*st.begin());
        st.erase(*st.begin());
    }
    int lagbe = m;
    lagbe--;
    while(lagbe)
    {
        swap(cur,prv);
        while(q[prv].size())
        {
            ll val = q[prv].front().ff;
            val *= 2;
//            debug(val)
            auto it = st.lower_bound({val,-1});
            if(it == st.end())break;
//            debug(it->ff,q[prv].size())
            q[prv].pop();
            q[cur].push(*it);
            st.erase(it);
        }
        if(q[prv].size() != 0)break;
        lagbe--;
    }
//    debug("ff");
    return lagbe == 0;
}
int main() {
    ///check for 0 or -1 if input not specified
    /// For printing double use %f
    #ifdef mamunSobPare
        READ("in.txt");
//        WRITE("out.txt");
    #else
//        READ("immetric.in");
//        WRITE("immetric.out");
    #endif // mamun
    getI(t);
    rep(cs,t)
    {
        v.clear();
        st.clear();
        getII(n,m);
        int ans = 0;
        rep(i,n)
        {
            ll x;
            getL(x);
            v.push_back(x);
        }
        sort(ALL(v));
        int low = 1, high = n/m;
//        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(check(mid))
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
//        while(st.size() >= m)
//        {
//            int lagbe = m;
//            auto it = (st.begin());
//            ll val = it->ff;
////            de
//            st.erase(it);
//            lagbe--;
//            while(lagbe)
//            {
////                debug(val/2)
//                auto it = st.lower_bound({val/2,-1});
//                if(it == st.end())
//                    break;
//                val = it->ff;
//                st.erase(it);
//                lagbe--;
//            }
//            if(lagbe == 0)ans++;
//            else break;
//        }
        printf("Case #%d: %d\n",cs,ans);
    }

    return 0;
}