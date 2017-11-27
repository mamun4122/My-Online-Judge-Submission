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
#define MAX 100005
int bit[MAX];
void update ( int x, int v )
{
    while ( x < MAX )
    {
        bit[x] += v;
        x += x & (-x);
    }
}
int query ( int x )
{
    int res = 0;
    while ( x )
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}
int getSum(int l,int r)
{
    return query(r) - query(l-1);
}

pair<int,string> longestBalanceString(string s)
{
//    string org = s;
//    repI(i,s.size())if(s[i] == '(')s[i] = '[';else if(s[i] == ')')s[i] = ']';
    int l = s.size();
    vector<int >r(l);
    vector<int >c(l);
    stack<pii >stk;
    for(int i = 0; i<l; i++)
    {
        if(s[i] == '[') stk.push({i,1});
        else if(s[i] == '(')stk.push({i,2});
        else
        {
            int val = 1;
            if(s[i] == ')')val = 2;
//            else val = 1;
            if(stk.size()>0 && stk.top().ss == val)
            {
                int tmp = stk.top().ff;
                stk.pop();
                r[tmp] = i+1;
                c[i] = tmp+1;
            }
            else while(!stk.empty())stk.pop();
        }
    }
    int len = 0,ans = 0;
    int lft = -1,rght = -2;
    for(int i = 0; i<l; ++i)
    {
        int cur = i;
        //__(s[i],r[i],c[i])
        if((s[i] == '['||s[i]=='(') && r[i] == 0) len = 0;
        else if((s[i] == ']'||s[i] == ')') && c[i] == 0) len = 0;
        else if(s[i] == '[' || s[i] == '(')
        {
            len += (r[i]-i);
            i = r[i]-1;
        }
//        debug(len)
        if(len != 0)
        {
//            debug(r[cur]-len+1,r[cur])
            int sum = getSum(r[cur]-len+1,r[cur]);
            if(sum > ans)
            {
                ans = sum;
                lft = r[cur]-len;
                rght = r[cur]-1;
            }
        }
    }
//    debug("");
    string res = "";
    FOR(i,lft,rght)res += s[i];


    return {ans,res};
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin >> s)
    {
        CLR(bit);
        repI(i,s.size())if(s[i] == '[')update(i+1,1);
//        repI(i,s.size())if(s[i] == '')s[i]
        pair<int,string> ans = longestBalanceString(s);
        cout << ans.ff << "\n" << ans.ss << "\n";
    }

    return 0;
}