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
string arr[205];
ll pre_row[205][205];
ll pre_col[205][205];
ll rev_col[205][205];
ll rev_row[205][205];
long long base = 10007;
long long mod = 1000000007;
long long get_hash()
{
    long long hash_val =0;
    long long rev_hash_val =0;
    repI(j,n)
    {
        hash_val = rev_hash_val = 0;
        string str = arr[j];
        for(int i = 0,k = n-1; str[i]; i++,k--)
        {
            hash_val = hash_val*base + str[i];
            hash_val %= mod;
            pre_row[j][i] = hash_val;
            rev_hash_val = rev_hash_val*base + str[k];
            rev_hash_val %= mod;
            rev_row[j][k] = rev_hash_val;
        }
    }
    hash_val = rev_hash_val = 0;
    repI(j,n)
    {
        hash_val = rev_hash_val = 0;
        for(int i = 0,k = n-1; i<n; i++,k--)
        {
            hash_val = hash_val*base + arr[i][j];
            hash_val %= mod;
            pre_col[i][j] = hash_val;
            rev_hash_val = rev_hash_val*base + arr[k][j];
            rev_hash_val %= mod;
            rev_col[k][j] = rev_hash_val;
        }
    }
}
ll val[100005];
void call()
{
    val[0] = 1;
    rep(i,100001)
    {
        val[i] = val[i-1]*base;
        val[i] %= mod;
    }
}

int row[205][205][205];
int col[205][205][205];
int cum_row[205][205][205];
int cum_col[205][205][205];
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    call();
    while(cin >> n)
    {
        CLR(row);
        CLR(col);
        CLR(cum_row);
        CLR(cum_col);
        repI(i,n)
        cin >> arr[i];
        get_hash();
//
//        repI(i,n)
//        {
//            repI(j,n)
//            printf("%d ",pre_row[i][j]);
//            puts("");
//        }
//        puts("");
//        repI(i,n)
//        {
//            repI(j,n)
//            printf("%d ",rev_row[i][j]);
//            puts("");
//        }
//        puts("");

        int ans = 1;
        ROF(sz,n-1,0)
        {
//            int sz = 2;
            int flag = 0;
            repI(i,n)
            {
                repI(j,n)
                {
                    if(j+sz<n)
                    {
                        ll value = pre_row[i][j+sz];
                        ll prev = j-1<0?0:pre_row[i][j-1];
                        value -= prev*val[sz+1];
                        if(value < 0)value = ((value%mod)+mod)%mod;

                        ll rev_value = rev_row[i][j];
                        prev = rev_row[i][j+sz+1];
                        rev_value -= prev*val[sz+1];
                        if(rev_value < 0)rev_value = ((rev_value%mod)+mod)%mod;
                        ///i,j theke sz size er cur row palindrome
                        if(value == rev_value)
                            row[i][j][sz] = 1;
    //                    debug(i,j,value,rev_value)
                    }
                    if(i+sz<n)
                    {
                        ll value = pre_col[i+sz][j];
                        ll prev = i-1<0?0:pre_col[i-1][j];
                        value -= prev*val[sz+1];
                        if(value < 0)value = ((value%mod)+mod)%mod;

                        ll rev_value = rev_col[i][j];
                        prev = rev_col[i+sz+1][j];
                        rev_value -= prev*val[sz+1];
                        if(rev_value < 0)rev_value = ((rev_value%mod)+mod)%mod;
                        ///i,j theke sz size er cur col palindrome
                        if(value == rev_value)
                            col[i][j][sz] = 1;
                    }

                }
            }
            repI(i,n)
            {
                repI(j,n)
                {
                    cum_row[i][j][sz] = i-1<0?0:cum_row[i-1][j][sz];
                    cum_row[i][j][sz] += row[i][j][sz];
                    cum_col[i][j][sz] = j-1<0?0:cum_col[i][j-1][sz];
                    cum_col[i][j][sz] += col[i][j][sz];
                }
            }
            repI(i,n)
            {
                if(i+sz>=n)break;
                repI(j,n)
                {
                    if(j+sz>=n)break;
                    int val = cum_row[i+sz][j][sz] - (i-1<0?0:cum_row[i-1][j][sz]);
                    int val1 = cum_col[i][j+sz][sz] - (j-1<0?0:cum_col[i][j-1][sz]);
                    if(val == val1 && val == sz+1)
                    {
                        ans = sz+1;
                        flag = 1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag)break;
        }
//        repI(i,n)
//        {
//            repI(j,n)
//            printf("%d ",cum_row[i][j][2]);
//            puts("");
//        }
//        puts("");
//        repI(i,n)
//        {
//            repI(j,n)
//            printf("%d ",cum_col[i][j][2]);
//            puts("");
//        }
        printf("%d\n",ans);
    }


    return 0;
}

