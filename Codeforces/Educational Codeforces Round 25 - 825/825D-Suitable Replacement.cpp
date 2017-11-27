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
ll mark[26];
ll fck[26];
ll vua[26];
ll baki;
bool check(int mid)
{
    ll tmp = baki;
    repI(i,26)
    {
        ll tot = mark[i] * mid;
        if(tot > fck[i])
            tmp -= (tot-fck[i]);
    }
    return tmp >= 0;
}
string a,b;
void getans(int mid)
{
    string ans = "";
    ll tmp = baki;
    CLR(vua);
    repI(i,26)
    {
        ll tot = mark[i] * mid;
        vua[i] += max(0LL,tot - fck[i]);
    }
    repI(i,26)
    {
        repI(j,a.size())
            if(a[j] == '?' && vua[i])
                vua[i]--,a[j] = (char)(i+'a');
    }
    repI(i,a.size())
        if(a[i] == '?')
            a[i] = 'a';
//    return ret;

}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> a)
    {
        baki = 0;
        cin >> b;
        if(a.size() < b.size())
        {
            repI(i,a.size())
                if(a[i] == '?')a[i] = 'a';
            cout << a << endl;
            continue;
        }
        CLR(mark);CLR(fck);
        repI(i,b.size())
            mark[b[i]-'a']++;
        CLR(fck);
        repI(i,a.size())if(a[i] != '?')fck[a[i]-'a']++;
        else baki++;
//        int mx = INF;
//        repI(i,26)
//        {
//            mx = min(mx,fck[i]/mark[i]);
//        }
        int ans = 0;
//        int tot = 0;
//        repI(i,26)
//            fck[i] -= mark[i]*mx,tot += mark[i] * mx;
        int low = 0,high = 1e6;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(check(mid))
                ans = mid,low = mid+1;
            else
                high = mid-1;
        }
        getans(ans);
        cout << a << endl;
//        printf("%d\n",ans);


    }

    return 0;
}