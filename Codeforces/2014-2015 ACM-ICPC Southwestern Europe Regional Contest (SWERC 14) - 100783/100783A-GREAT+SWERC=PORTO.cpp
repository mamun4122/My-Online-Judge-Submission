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
int mp[500];
set<char> st;
vector<char> v;
vector<int> perm;
int flagforzero[1000];
string arr[15];
int mx = 0;
int boro = 0;
int check()
{
    int carry = 0;
    repI(i,mx)
    {
        int tar = mp[arr[n][i]];
        int tot = 0;
        rep(j,n-1)tot += mp[arr[j][i]];
        tot += carry;
        carry = tot/10;
        tot %= 10;
        if(tar != tot)return 0;
    }

//    if(mp['S'] == 9 && mp['E'] == 5 && mp['N'] == 6 && mp['D'] == 7&& mp['M'] == 1 && mp['O'] == 0 && mp['R'] == 8 &&  mp['E'] == 5 && mp['N'] == 6)
//    {
//        debug(carry)
//    }
    if(boro && !carry)
        return 0;
    if(carry && !boro)
        return 0;
    if(carry && boro && mp[arr[n][mx]] != carry)
        return 0;
//    repI(i,v.size())debug(v[i],mp[v[i]])
//    puts("");
    return 1;
}
int mark[15];
int backtrack(int pos)
{
    if(pos == v.size())return check();
    int ans = 0;
    repI(i,10)
    {
        if(i == 0 && flagforzero[v[pos]])continue;
        if(mark[i])continue;
        mark[i] = 1;
        mp[v[pos]] = i;
        ans += backtrack(pos+1);
        mark[i] = 0;
    }
    return ans;
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
    while(cin >> n)
    {
        CLR(mark);
        v.clear();
        st.clear();
        perm.clear();
        CLR(mp);
        mp['#'] = 0;
        rep(i,n)cin >> arr[i];
//        rep(i,n)debug(arr[i]);
        CLR(flagforzero);
        mx = 0;
        rep(i,n-1)mx = max(mx,(int)arr[i].size());
        boro = 0;
        rep(i,n-1)
        {
            repI(j,arr[i].size())
                st.insert(arr[i][j]);
            flagforzero[arr[i][0]] = 1;
            while(arr[i].size() != mx)
                arr[i] = "#" + arr[i];
        }
//        debug(mx,arr[n)
        if(arr[n].size() != mx && arr[n].size() != mx+1)
        {
            puts("0");
            continue;
        }
        if(arr[n].size() == mx + 1)boro = 1;
        repI(j,arr[n].size())st.insert(arr[n][j]);
        flagforzero[arr[n][0]] = 1;
//        debug(st.size())
        for(auto it: st)
            v.push_back(it);

        repI(i,10)perm.push_back(i);
        rep(i,n)reverse(ALL(arr[i]));
//        repI(i,v.size())debug(v[i],flagforzero[v[i]])

        int ans = backtrack(0);
//        do
//        {
//            int flag = 1;
//            repI(i,v.size())
//            {
//                if(perm[i] == 0 && flagforzero[v[i]])
//                    flag = 0;
//                mp[v[i]] = perm[i];
//            }
////            if(flag)debug("")
//            if(flag)ans += check();
//        }
//        while(next_permutation(ALL(perm)));
        printf("%d\n",ans);
    }
    return 0;
}