#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
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

//unordered_map<string,int> mp;
map<string,string> mp;
map<string,int> hashing;
map<int,string> inv;
int tot;

void intohash(string a)
{
    if(hashing[a] != 0)
        return;
    hashing[a] = tot;
    inv[tot] = a;
    tot++;
}
int gethash(string a)
{
    if(hashing[a] != 0)
        return hashing[a];
    hashing[a] = tot;
    inv[tot] = a;
    tot++;
    return hashing[a];
}
string getInv(int num)
{
    return inv[num];
}

int replacethis(int val, string b)
{
    string a = getInv(val);
    string ans = "";
    repI(i,a.size())
    {
        if(a[i] == b[0])
        {
            int flag = 1;
            repI(j,b.size())
                if(a[i+j] != b[j])
                {
                    flag = 0;
                    break;
                }
            if(flag)
                ans += mp[b],i = i+b.size()-1;
            else
                ans += a[i];
        }
        else
            ans += a[i];
    }
    int ret = gethash(ans);
    if(ans.size() > 100)
        ret = -1;
    return ret;
}
int mark[1000005];
int dist[1000005];
int bfs(int src,int dest)
{
    CLR(mark);
    MEM(dist,63);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    mark[src] = 1;
//    dist[src] = 0;
    int fck = 0;
    while(!q.empty())
    {
        fck++;
        if(fck > 1000000)
            break;
        int u = q.front();q.pop();
        if(u == dest)
            return dist[u];
        for(auto it: mp){
            int ret = replacethis(u,it.ff);
            if(ret == -1)
                continue;
            if(mark[ret] == 0)
            {
                dist[ret] = dist[u] + 1;
                mark[ret] = 1;
                q.push(ret);
            }
        }
    }
    return -1;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n && n)
    {
        hashing.clear();
        inv.clear();
        tot = 1;
        mp.clear();
        string a,b;
        rep(i,n)
        {
            cin >> a >> b;
            mp[a] = b;
        }
        string src,dest;
        cin >> src >> dest;
//        hashing(src);
//        hashing(dest);
        int ans = bfs(gethash(src),gethash(dest));
        printf("%d\n",ans);
    }

    return 0;
}

