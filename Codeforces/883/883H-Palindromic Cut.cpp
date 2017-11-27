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

#define mamu
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

map <char, int> globmp;
string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
vector < string > vs;

void solve(int sz, int koita)
{
    string st[koita];
    repI(i, koita) st[i] = "";

    int needSame = ((sz/2)*2)*koita;
    for(auto ch: letters)
    {
        if(globmp[ch])
        {
            int aseSame = (globmp[ch]/2)*2;
            int mn = min(aseSame, needSame);
            globmp[ch] -= mn;
            needSame -= mn;

            int jog = mn / 2;

            int in = 0;
            for(int i=1; i<=jog; i++)
            {
                while(st[in].size() >= sz/2) in++;

                st[in] += ch;
            }
        }
    }

    int needDiff = (sz%2)*koita;
    int in = 0;
    for(auto ch: letters)
    {
        if(globmp[ch])
        {
            for(int i=1; i<=globmp[ch];i ++)
            {
                st[in] += ch;
                in++;
            }
//                    int mn = min(needDiff, mp[j]);
            needDiff -= globmp[ch];
            globmp[ch] = 0;
        }
    }

    FOR(i,0,koita-1)
    {
        if(sz&1)
        {
            int len = st[i].size()-2;
            ROF(j,len,0) st[i] += st[i][j];
        }
        else
        {
            int len = st[i].size()-1;
            ROF(j,len,0) st[i] += st[i][j];
        }

        vs.PB(st[i]);
    }
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);

    debug(letters.size())
    int len;
    while( cin >> len )
    {
        vs.clear();
        string st;
        cin >> st;
        map < char, int > mp;
        globmp.clear();
        FOR(i,0,len-1)
        {
            mp[st[i]]++;
            globmp[st[i]]++;
        }

        vi v;
        int nn = sqrt(len);
        FOR(i,1,nn)
        {
            if(len%i==0)
            {
                v.PB(i);
                if(len/i!=i) v.PB(len/i);
            }
        }
        sort(ALLR(v));

        repI(i, v.size())
        {

            for(auto ch: letters) mp[ch] = globmp[ch];

            int sz = v[i];
            int koita = len / sz;
            int needSame = ((sz/2)*2)*koita;

            for(auto ch: letters)
            {
                if(mp[ch])
                {
                    int aseSame = (mp[ch]/2)*2;
                    int mn = min(aseSame, needSame);
                    mp[ch] -= mn;
                    needSame -= mn;
                }
            }
            trace(needSame, sz);
            if(needSame) continue;

            int needDiff = (sz%2)*koita;
            for(auto ch: letters)
            {
                if(mp[ch])
                {
//                    int mn = min(needDiff, mp[j]);
                    needDiff -= mp[ch];
                    mp[ch] = 0;
                }
            }
            trace(needDiff, sz);
            if(needDiff) continue;

            solve(sz, koita);
            break;
        }

        cout << vs.size() << endl;
        repI(i, vs.size())
        {
            if(i) cout << " ";
            cout << vs[i];
        }
        cout << endl;
    }

    return 0;
}