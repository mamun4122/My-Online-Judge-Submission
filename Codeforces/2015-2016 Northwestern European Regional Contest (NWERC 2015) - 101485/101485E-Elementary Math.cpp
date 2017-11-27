#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = (1<<28);
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

#ifdef mamunKmneSobPare
    #define DUMP(p) #p
    #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define DUMP(p)
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t;//,n,m;

#define MAX 100004
#define NIL 0

vi G[MAX];
int n,m, match[MAX], dist[MAX];

bool bfs()
{
    int i,u,v,len;
    queue <int> q;
    FOR(i,1,n)
    {
        if(match[i] == NIL)
        {
            dist[i] = 0;
//            debug("i")
            q.push(i);
        }
        else dist[i] = INF;
    }

    dist[NIL] = INF;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u!=NIL)
        {
            len = G[u].size();
            FOR(i,0,len-1)
            {
                v = G[u][i];
                if(dist[match[v]] == INF)
                {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
    }
//    debug("")
    return (dist[NIL] != INF);
}

bool dfs(int u)
{
    int i,v,len;
    if(u!=NIL)
    {
        len = G[u].size();
        FOR(i,0,len-1)
        {
            v = G[u][i];
            if(dist[match[v]] == dist[u]+1)
            {
                if(dfs(match[v]))
                {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hop_karp()
{
    CLR(match);
    int matching = 0;

    while(bfs())
    {
        debug("ff")
        FOR(i,1,n)
        {
            if(match[i] == NIL && dfs(i))
                matching++;
        }
    }
    return matching;
}

unordered_map < ll, int > nodes;
unordered_map < int, ll > org;

pii arr[MAX];
int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamunKmneSobPare
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    int n;
    while(~getI(n))
    {
        int in = 0;
        FOR(i,1,n)
        {
            int x,y;
            getII(x,y);
            arr[i] = {x,y};

            ll kk = (ll)x+y;
            if(nodes[kk]==0)
            {
                nodes[kk] = n + (++in);
                org[n+in] = kk;
            }
//            debug(i,kk,nodes[kk])

            kk = (ll)x-y;
            if(nodes[kk]==0) nodes[kk] = n + (++in),org[n+in] = kk;

            kk = (ll)x*y;
            if(nodes[kk]==0) nodes[kk] = n + (++in),org[n+in] = kk;

            G[i].push_back(nodes[(ll)x+y]);
            G[nodes[(ll)x+y]].push_back(i);

            G[i].push_back(nodes[(ll)x-y]);
            G[nodes[(ll)x-y]].push_back(i);

            G[i].push_back(nodes[(ll)x*y]);
            G[nodes[(ll)x*y]].push_back(i);
        }
        int res = hop_karp();
//        debug(res);
        if(res != n)
        {
            puts("impossible");
            continue;
        }
        else
        {
            rep(i,n)
            {
                int x = match[i];
//                debug(i,x,org[x])
                printf("%d ",arr[i].ff);
                if((ll)arr[i].ff+arr[i].ss == org[x])
                {
                    printf("+");
                }
                else if((ll)arr[i].ff-arr[i].ss == org[x])
                {
                    printf("-");
                }
                else if((ll)arr[i].ff*arr[i].ss == org[x])
                {
                    printf("*");
                }
                printf(" %d",arr[i].ss);
                printf(" = %lld\n",org[x]);
            }
        }


    }

    return 0;
}