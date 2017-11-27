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
int mark[26];
#define M 1000005
bool marked[M];
vector<int> primes;   // we'll preload primes once at the beginning

void sieve(int n)
{
    primes.push_back(2);
    int i;
    for (i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    while(i<=n)
    {
        if(marked[i]==0)primes.push_back(i);
        i+=2;
    }
}
void printans(string ans)
{
    int flag = 0;
    repI(i,ans.size())if(ans[i] == '?')flag = 1;
    if(flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    sieve(10000);
    while(cin >> s)
    {
        int sz = s.size();
        CLR(mark);
        repI(i,sz)mark[s[i]-'a']++;
        string ans = "";
        repI(i,sz)ans += '?';
        int imp = 0;
        for(int i = 0; i < primes.size() && primes[i] <= sz; i++)
        {
            int lagbe = 0;
            int val = primes[i];
            int flag = -1;
            while(val <= sz)
            {
                debug(ans[val-1],val)
                if(ans[val-1] == '?')lagbe++;
                else if(flag == -1)flag = ans[val-1]-'a';
                else if(flag != ans[val-1]-'a')
                {
                    imp = 1;
                    break;
                }
                val += primes[i];
            }
            debug(flag)
            if(imp)break;
            if(flag == -1)
            {
                repI(j,26)
                {
                    if(mark[j] >= lagbe)
                    {
                        if(flag == -1)flag = j;
                        else if(mark[j] > mark[flag])
                            flag = j;
                    }
                }
                if(flag == -1)
                {
                    imp = 1;
                    break;
                }
            }
            else if(mark[flag]<lagbe)
                imp = 1;


            if(imp)break;

            val = primes[i];
            char x = flag + 'a';
            while(val <= sz)
            {
                if(ans[val-1] == '?')
                    ans[val-1] = x,mark[flag]--;
                val += primes[i];
            }

        }
        debug(imp,ans)
        if(!imp)
        {
            repI(i,sz)
            {
                if(ans[i] != '?')continue;
                repI(j,26)
                {
//                    debug(mark[j])
                    if(mark[j])
                    {
                        ans[i] = (char)j+'a';
                        mark[j]--;
                        break;
                    }
                }
            }
        }


        if(!imp)printans(ans);
        else cout << "NO" << endl;

    }

    return 0;
}