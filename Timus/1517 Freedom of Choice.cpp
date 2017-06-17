#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
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
//long long base = 347;
//long long mod = 2117566807;
//ll gen[100005], pre[100005];
//ll pre1[100005];

const int SZ = 1e5+4;
ll forwardHashTable[2][SZ];
ll forwardHashTable1[2][SZ];
ll backwardHashTable[2][SZ];
ll power[2][SZ];
const long long mod[2] = {1000000007LL, 2117566807LL};
const long long base[2] = {1572872831LL, 1971536491LL};

ll MOD(ll x, int index)
{
    return (x%mod[index]+mod[index])%mod[index];
}

void get_hash(string st,string str1)
{
    CLR(forwardHashTable);
    int len = st.size();

    for(int in=0; in<2; in++)
    {
        for(int i=0; i<len; i++)
        {
            int kk = st[i] - ' ';
            if(i)
            {
                forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                continue;
            }
            forwardHashTable[in][i] = kk;
        }
    }

    CLR(forwardHashTable1);
    st = str1;
    len = st.size();

    for(int in=0; in<2; in++)
    {
        for(int i=0; i<len; i++)
        {
            int kk = st[i] - ' ';
            if(i)
            {
                forwardHashTable1[in][i] = ((forwardHashTable1[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                continue;
            }
            forwardHashTable1[in][i] = kk;
        }
    }
}
void call()
{
    power[0][0]=1;
    power[1][0]=1;
    for(int i=0; i<2; i++)
    {
        for(int j=1; j<SZ; j++)
        {
            power[i][j] = (power[i][j-1] * base[i]) % mod[i];
        }
    }
}
ll getForwardHashingQuery1(int left, int right)
{
    if(left==0)
    {
        return (forwardHashTable1[0][right] << 31) | forwardHashTable1[1][right];
    }
    ll ret1 = MOD(forwardHashTable1[0][right] - (forwardHashTable1[0][left-1] * power[0][right-left+1])%mod[0], 0);
    ll ret2 = MOD(forwardHashTable1[1][right] - (forwardHashTable1[1][left-1] * power[1][right-left+1])%mod[1], 1);
    ll ret = (ret1 << 31) | ret2;
    return ret;
}
ll getForwardHashingQuery(int left, int right)
{
    if(left==0)
    {
        return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
    }
    ll ret1 = MOD(forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1])%mod[0], 0);
    ll ret2 = MOD(forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1])%mod[1], 1);
    ll ret = (ret1 << 31) | ret2;
    return ret;
}


unordered_map<ll,int> mp;

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    call();
    while(cin >> n)
    {
        string a,b;
        cin >> a >> b;
        get_hash(a,b);
        pii ans = pii(-1,-1);
        int low = 0,high = n-1;
//        repI(i,n)debug(a[i],pre[i],b[i],pre1[i])
        while(low <= high)
        {
            int mid = (low + high)/2;
//            debug(mid)
            mp.clear();
            int flag = -1;
            repI(i,n)
            {
                if(i + mid >= n)break;
                ll val = getForwardHashingQuery(i,i+mid);
//                debug(val)
                mp[val] = 1;
            }
            repI(i,n)
            {
                if(i + mid >= n)break;
                ll val = getForwardHashingQuery1(i,i+mid);
                if(mp[val] == 1)
                {
                    flag = i;
                    break;
                }
            }
            if(flag != -1)
            {
                ans = pii(flag,mid);
                low = mid+1;
            }
            else
                high = mid-1;

        }
        if(ans.ff != -1)
            cout << b.substr(ans.ff,ans.ss+1) << endl;
        else
            cout << "" << endl;
    }

    return 0;
}

