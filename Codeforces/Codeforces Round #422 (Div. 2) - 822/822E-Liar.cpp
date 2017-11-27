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
#define MAX 100005
int dp[40][MAX];
string a,b;
long long base = 10007;
long long mod = 1000000007;
ll val[100005], preA[100005],preB[100005];
long long get_hash()
{
    CLR(preA);CLR(preB);
 long long hash_val =0;
 repI(i,a.size())
 {
  hash_val = hash_val*base + a[i]-'a';
  hash_val %= mod;
  preA[i+1] = hash_val;
 }
 hash_val =0;
 repI(i,b.size())
 {
  hash_val = hash_val*base + b[i]-'a';
  hash_val %= mod;
  preB[i+1] = hash_val;
 }
}
void call()
{
    val[0] = 1;
    rep(i,100001)
    {
        val[i] = val[i-1]*base;
        val[i] %= mod;
    }
}
int isEqual(int l1, int r1, int l2, int r2)
{
    if(r2 > m)return 0;
    ll val1 = preA[r1] - (preA[l1-1]*val[r1-l1+1])%mod + mod;
    val1 %= mod;
    ll val2 = preB[r2] - (preB[l2-1]*val[r2-l2+1])%mod + mod;
    val2 %= mod;
    return val1 == val2;
}
pii match(int i,int j)
{
    int low = 0, high = n-i;
    int ans = -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(isEqual(i,i+mid,j,j+mid))
            ans = mid,low = mid+1;
        else
            high = mid-1;
    }
    ans++;
    return pii(i+ans, j+ans);
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    call();
    while(cin >> n )
    {
        cin >> a;
        cin >> m;
        cin >> b;
        get_hash();
        int x;
        cin >> x;
        CLR(dp);
        rep(i,n)dp[1][i] = 1;
        int flag = 0;
        rep(i,x)
        {
            int mx = 1;
            rep(j,n)
            {
                mx = max(dp[i][j], mx);
                dp[i][j+1] = max(dp[i][j+1], mx);
                pii suruhbe = match(j,mx);
                dp[i+1][suruhbe.ff] = max(dp[i+1][suruhbe.ff], suruhbe.ss);
                if(suruhbe.ss > m)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }


    return 0;
}