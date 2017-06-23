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
int t;
ll n,m;
string s;
bool checkmult()
{
    stack<ll> st;
    int gun = 0;
    repI(i,s.size())
    {
        if(i%2)
        {
            if(s[i] == '*')
              gun = 1;
            continue;
        }
        ll val = s[i] - '0';
        if(gun)
        {
            ll top = st.top();
            st.pop();
            top *= val;
            st.push(top);
            gun = 0;
        }
        else st.push(val);
    }
    ll tot = 0;
    while(!st.empty())
    {
        tot += st.top();st.pop();
    }
    return tot == n;
}
bool checklft()
{

    stack<ll> st;
    int gun = 0,jog = 0;
    repI(i,s.size())
    {
        if(i%2)
        {
            if(s[i] == '*')
              gun = 1;
            else jog = 1;
            continue;
        }
        ll val = s[i] - '0';
        if(gun)
        {
            ll top = st.top();
            st.pop();
            top *= val;
            st.push(top);
            gun = 0;
        }
        else if(jog)
        {
            ll top = st.top();
            st.pop();
            top += val;
            st.push(top);
            jog = 0;
        }
        else
        {
            st.push(val);
        }
    }
    ll tot = 0;
    while(!st.empty())
    {
        tot += st.top();st.pop();
    }
    return tot == n;
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> s)
    {
        cin >> n;
        int m = 0, l = 0;
        m = checkmult();
        l = checklft();
        if( m && l)
            puts("U");
        else if(m)
            puts("M");
        else if(l)
            puts("L");
        else
            puts("I");
    }
    return 0;
}

