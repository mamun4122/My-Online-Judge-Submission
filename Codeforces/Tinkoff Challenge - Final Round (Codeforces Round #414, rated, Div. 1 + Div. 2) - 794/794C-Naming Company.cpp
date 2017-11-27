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
int one[26];
int two[26];

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    while(cin>>a)
    {
        cin >> b;
        CLR(one);
        CLR(two);
        string ans = "";
        int sz = a.size();
        repI(i,sz)ans += "?";
//        sort(ALL(a));
//        sort(ALL(b));
//        reverse(ALL(b));
        repI(i,sz)
        one[a[i]-'a']++;
        repI(i,sz)
        two[b[i]-'a']++;

        int cnt = 0;
        int lft = 0,rght = sz-1;
        int tota = (sz+1)/2;
        int totb = sz/2;
        while(sz--)
        {
            if(cnt%2==0)
            {
                repI(i,26)
                {
                    if(one[i])
                    {
                        char x = i+'a';
                        int flag = 0;
                        FOR(j,i+1,25)
                        {
                            if(two[j])
                                flag = 1;
                        }
                        if(flag)
                        {
                            one[i]--;
                            ans[lft++] = x;
                        }
                        else
                        {
                            int tot = 0;
                            repI(i,26)
                            {
                                tot += one[i];
                                if(tot >= tota)
                                {
                                    x = i+'a';
                                    one[i]--;
                                    break;
                                }
                            }
                            ans[rght--] = x;
                        }
                        tota--;
                        break;
                    }
                }
            }
            else
            {
                ROF(i,25,0)
                {
                    if(two[i])
                    {
                        char x = i+'a';
                        debug(x)
                        int flag = 0;
                        FOR(j,0,i-1)
                        {
                            if(one[j])
                                flag = 1;
                        }
                        debug(x,flag,lft)
                        if(flag){
                            two[i]--;
                            ans[lft++] = x;
                        }
                        else{
                            int tot = 0;
                            ROF(i,25,0)
                            {
                                tot+=two[i];
                                if(tot>=totb)
                                {
                                    x = i+'a';
                                    two[i]--;
                                    break;
                                }
                            }
                            ans[rght--] = x;
                        }
                        totb--;
                        break;
                    }
                }
            }
            cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}