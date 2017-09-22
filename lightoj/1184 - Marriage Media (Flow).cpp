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
int t,n,m;
namespace mf{
    const int MAX = 5000;
    const long long INF = 1LL << 60;

    long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
    int n, m, s, t, Q[10010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

    void init(int nodes, int source, int sink){
        m = 0, n = nodes, s = source, t = sink;
        for (int i = 0; i <= n; i++) last[i] = -1;
    }

    void addEdge(int u, int v, long long c, long long w){
        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
    }

    bool spfa(){
        int i, j, x, f = 0, l = 0;
        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;

        dis[s] = 0, Q[l++] = s;
        while (f < l){
            i = Q[f++];
            for (j = last[i]; j != -1; j = link[j]){
                if (flow[j] < cap[j]){
                    x = adj[j];
                    if (dis[x] > dis[i] + cost[j]){
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if (!visited[x]){
                            visited[x] = 1;
                            if (f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t] != INF);
    }

    pair <long long, long long> solve(){
        int i, j;
        long long mincost = 0, maxflow = 0;

        while (spfa()){
            long long aug = INF;
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                aug = min(aug, cap[j] - flow[j]);
            }
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                flow[j] += aug, flow[j ^ 1] -= aug;
            }
            maxflow += aug, mincost += aug * dis[t];
        }
        return make_pair(mincost, maxflow);
    }
}
int age[55],height[55],divorce[55];

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        mf::init(n+m+2,n+m+1,n+m+2);
        rep(i,n)getIII(height[i],age[i],divorce[i]);
        rep(j,m)
        {
            int x,y,z;
            getIII(x,y,z);
            rep(i,n)
                if(abs(height[i]-x) <= 12 && abs(y-age[i]) <= 5 && z == divorce[i])
                    mf::addEdge(i,n+j,1,0);//mf::addEdge(n+j,i,1,0);
        }
        rep(i,n)mf::addEdge(n+m+1,i,1,0);
//        rep(i,n)mf::addEdge(i,n+m+1,1,0);
        rep(i,m)mf::addEdge(n+i,n+m+2,1,0);
//        rep(i,m)mf::addEdge(n+m+2,n+i,1,0);
//        debug("")
        printf("Case %d: %d\n",cs,mf::solve().ss);
    }

    return 0;
}

