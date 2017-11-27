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

map <string, int > node;
map <int, string > rev;
vii adj;

int dist[505];
int vis[505];
int res[505];
int par[505];

int bfs(int src)
{

    queue<int> q;
    q.push(src);
    MEM(dist,63);
    dist[src] = 0;
    CLR(vis);
    vis[src] = 1;
    int ans = INF;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(auto v: adj[u])
        {
            if(vis[v] == 0)
            {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if(v == src)
            {
                int len = dist[u] + 1;
                ans = min(ans,len);
            }
        }
    }
    return ans;
}
void bfs(int src, int d)
{
    SET(par);
    queue<int> q;
    q.push(src);
    MEM(dist,63);
    dist[src] = 0;
    CLR(vis);
    vis[src] = 1;
    int ans = INF;
    int flag = 0;
    while(!q.empty())
    {
        if(flag)break;
        int u = q.front();q.pop();
        for(auto v: adj[u])
        {
            if(vis[v] == 0)
            {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
                par[v] = u;
            }
            else if(v == src)
            {
                int len = dist[u] + 1;
                if(len == d)
                {
                    flag = u;
                    break;
                }
            }
        }
    }
//    debug(flag)
    stack<string> st;
    while(flag != -1)
    {
        st.push(rev[flag]);
        flag = par[flag];
        if(flag != -1);
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
        if(!st.empty())cout << " ";
    }
    cout << endl;
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("inI.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while ( cin >> n )
    {
        node.clear();
        rev.clear();
        adj.assign(n+4, vi());
        int in = 1;
        rep(i,n)
        {
            string st;
            cin >> st;
            if(node[st]==0)
            {
                node[st] = in;
                rev[in] = st;
                in++;
            }
        }

        FOR(sec,1,n)
        {
            string now;
            int k;
            cin >> now >> k;
//            debug(now, k)
            cin.get();
            FOR(i,1,k)
            {
                string tmp;
                getline(cin, tmp);
                stringstream ss(tmp);

//                debug(tmp);
                string x;
                ss >> x;
                while(ss >> x)
                {
                    if(x.back()==',') x.pop_back();
                    int u = node[now];
                    int v = node[x];
                    adj[u].PB(v);
                }
            }
        }
        int ans = INF;
        rep(i,n)res[i] = bfs(i),ans = min(ans, res[i]);
        if(ans == INF)
        {
            cout << "SHIP IT" << endl;
            continue;
        }
        else
        {
//            debug("")
            int src = 0;
            ROF(i,n,1)if(res[i] == ans)src = i;
//            debug(src)
            bfs(src,res[src]);
        }

    }


    return 0;
}