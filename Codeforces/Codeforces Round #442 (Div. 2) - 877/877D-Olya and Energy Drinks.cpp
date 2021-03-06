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
int k;
int adj[1005][1005];
int directon[4][1005][1005];
//int rght[1005][1005];
//int up[1005][1005];
//int down[1005][1005];
int dist[1005][1005];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int getRev(int indx)
{
    if(indx == 0)return 1;
    if(indx == 1)return 0;
    if(indx == 2)return 3;
    if(indx == 3)return 2;
}
int bfs(pii src,pii dest)
{
    queue<pii> q;
    q.push(src);
    dist[src.ff][src.ss] = 0;
    while(!q.empty())
    {
        pii u = q.front();q.pop();
        if(u == dest)return dist[dest.ff][dest.ss];
        int x = u.ff;
        int y = u.ss;
        repI(i,4)
        {
            if(directon[i][x][y])continue;
            rep(j,k)
            {
                int xx = x + dx[i]*j;
                int yy = y + dy[i]*j;
                if(!adj[xx][yy])break;
//                directon[i][xx][yy] = 1;
                directon[getRev(i)][xx][yy] = 1;
                if(dist[x][y]+1 >= dist[xx][yy])continue;
                dist[xx][yy] = min(dist[xx][yy], dist[x][y]+1);
                q.push({xx,yy});
                pii tmp = {xx,yy};
                if(tmp == dest)
                    return dist[xx][yy];
            }
        }
    }
    return INF;
}
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n >> m >> k)
    {
        rep(i,n)rep(j,m)adj[i][j] = 1,dist[i][j] = INF;
//        CLR(lft);CLR(rght);CLR(up);CLR(down);
        CLR(directon);
        repI(i,n)
        {
            string s;
            cin >> s;
//            debug(s);
            repI(j,m)if(s[j] == '#')adj[i+1][j+1] = 0;
        }
//        debug("");
        pii src,dest;
        cin >> src.ff >> src.ss;
        cin >> dest.ff >> dest.ss;
        int ans = bfs(src,dest);
        printf("%d\n",ans == INF?-1:ans);
    }

    return 0;
}