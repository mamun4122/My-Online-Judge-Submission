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
int dp[1005][1005][5];
string s;
int call(int pos,int win,int loss)
{
    int dif = abs(win-loss);
    int flag = 0;
    if(win > loss) flag = 1;
    int &ret = dp[pos][dif][flag];
    if(pos == s.size())
    {
        if(dif == m)return ret = 1;
        return ret = 0;
    }
    if(ret != -1) return ret;
    if(dif == m)return ret = 0;
    if(s[pos] == 'L')
    {
        return ret = call(pos+1,win,loss+1);
    }
    if(s[pos] == 'W')
    {
        return ret = call(pos+1,win+1,loss);
    }
    if(s[pos] == 'D')
    {
        return ret = call(pos+1,win,loss);
    }
    ret = 0;
    ret |= call(pos+1,win,loss+1);
    ret |= call(pos+1,win+1,loss);
    ret |= call(pos+1,win,loss);
    return ret;
}
void print(int pos,int win,int loss)
{
    int dif = abs(win-loss);
    int flag = 0;
    if(win > loss) flag = 1;
    if(pos == s.size())
    {
        return;
    }
    if(s[pos] == 'L')
    {
        putchar(s[pos]);
        print(pos+1,win,loss+1);
        return;
    }
    if(s[pos] == 'W')
    {
        putchar(s[pos]);
        print(pos+1,win+1,loss);
        return;
    }
    if(s[pos] == 'D')
    {
        putchar(s[pos]);
        print(pos+1,win,loss);
        return;
    }
    if(call(pos+1,win,loss+1))
    {
        putchar('L');
        print(pos+1,win,loss+1);
    }
    else if(call(pos+1,win+1,loss))
    {
        putchar('W');
        print(pos+1,win+1,loss);
    }
    else
    {
        putchar('D');
        print(pos+1,win,loss);
    }
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n >> m)
    {
        SET(dp);
        cin >> s;
        int ans = call(0,0,0);
        if(!ans)
        {
            puts("NO");
        }
        else
        {
            print(0,0,0);
            puts("");
        }

    }

    return 0;
}